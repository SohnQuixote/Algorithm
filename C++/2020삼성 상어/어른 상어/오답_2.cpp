#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
using namespace std;

/*
  어른 상어
  물고기 없어지고 상어만 있음
  상어 -> 1~M
  1의 번호 상어 가장 강력
  N * N 격자중 M개 칸에 상어 1마리씩
  냄새 -> 상어 k번 이동 사라짐
  상어 이동 - 냄새뿌림 -> 상하좌우 하나로 이동
  상어 이동방향 결정 -> 인접한 칸중 아무 냄새 없는 칸 ->X 자신의 냄새 방향
  가능 칸 여러개 -> 우선순위
  상어 이동후 한칸에 여러마리 상어 -> 가장 낮은 번호 제외 모두 쫓겨남
  1번 상어만 격자에 남기까지 몇초 소요?
  한번에 합치면 복잡함 -> 자료구조 분리
  왜 틀린지 모르겠음
*/
//20*20 인데 
vector<pair<int,int>> sea[20][20];//원소가 두개 이상이면 작은 숫자 제외하고 다 제외
//first -상어 번호 second - 상어 방향
//상어 번호
vector<vector<pair<int,int>>>scent_sea(20,vector<pair<int,int>>(20,make_pair(0,0))); //first -냄새 주인 second - 냄새 지속 시간
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,-1,1}; //1~4 상하좌우
string to_str(int a)
{
  if(a == 1)
    return "상";
  else if(a==2)
    return "하";
  else if(a==3)
    return "좌";
  else
    return "우";
}
void print_sea_scent(int N,int S)
{
  cout<<"cur_time::"<<S<<endl;
  cout<<"printing sea..."<<endl<<endl;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          if(sea[i][j].size() != 0)
          {
            cout<<' '<<sea[i][j][0].first<<' '<<to_str(sea[i][j][0].second)<<' ';
          }
          else
          {
            cout<<' '<<"0 0"<<' ';
          }
          
        }
        cout<<endl;
      
    }
  cout<<endl<<endl<<"printing scent..."<<endl;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          cout<<' '<<scent_sea[i][j].first<<' '<<scent_sea[i][j].second<<' ';
          
        }
      cout<<endl;
      
    }
  
}
void clear_sea(int N,int K)
{
  //매번 이동할때마다 호출
  //냄새 하나씩 줄임
  //sea에 두개이상 있으면 낮은거 하나 빼고 삭제
  /*for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          cout<<sea[i][j].size()<<' ';
        }
      cout<<endl;
    }*/
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          if(scent_sea[i][j].second >0 && sea[i][j].size() == 0)
          {
            scent_sea[i][j].second-=1;
            if(scent_sea[i][j].second == 0)
            {
              scent_sea[i][j] = make_pair(0,0);
              //냄새 소멸
            }
            
          }
          //상어 소멸
          int size = sea[i][j].size();
          if(size>=2)
          {
            for(int k=0;k<size-1;k++)
              {
                sea[i][j].pop_back();
              }
          }
          if(size == 1)
          {
            int shark = sea[i][j][0].first;
            scent_sea[i][j] = make_pair(shark,K);
            
          }
          
        }

      
    }
  
}
bool chk_finished(int N)
{
  int size = 0;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
        size+= sea[i][j].size();
          
        }
      
    }
  if(size == 1)
    return false;
  return true;
  //상어가 하나만 남았나?
}
bool calc_range(int a, int N)
{
  if(a>=0 && a<N)
    return true;
  return false;
}
pair<int,int> find_shark(int num,int N)
{
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          if(sea[i][j].size() != 0)
          {
            if(sea[i][j][0].first == num)
              return make_pair(i,j);
          }
        }
      
    }
  return make_pair(-1,-1);
}
int calc(int N, int M, int K, int shark_dir[][4][4])
{
  int result =0;
  //상어 이동 시작
  //상어 이동방향 결정 - 인접한 칸중 아무 냄새가 없는 칸
  //없으면 자신의 칸
  //여러개일 경우 우선순위
  while(chk_finished(N) && result<1000)
    {
      //if(result<30)
        //print_sea_scent(N,result);
      //clear_sea(N);
      result++;
      if(result == 1000) //1000일 때 움직이면 안됨
        break;
      vector<tuple<int,int,int>> scent_spread;
      //x,y 번호
      //현재 상어 공간은 냄새 안깎임
      for(int i=1;i<=M;i++)
        {
          //이동이 이상하게 됨
          //한 위치에 언제나 상어 하나씩 유지
          //상어 위치 찾기
          //순차적으로 가기에 겹치면 그냥 하나만 남기고 다 pop_back하면 됨 숫자 낮은 놈이 자동 뒤로감
          pair<int,int> pos = find_shark(i,N);
          //아무 냄새 없는 칸
          int x =pos.first;
          int y = pos.second;
          //cout<<"orig_loc..."<<endl;
          //cout<<i<<' '<<x<<' '<<y<<endl;
          if(x!= -1) //상어 생존
          {
          vector<tuple<int,int,int>> moving_dir;
          moving_dir.clear();
          //좌표 및 방향도 저장해야함
          for(int d=1;d<=4;d++)
            {
              int mov_x = x+ dx[d];
              int mov_y = y+ dy[d];
              
              if(calc_range(mov_x,N) && calc_range(mov_y,N))
              {
                if(scent_sea[mov_x][mov_y].first ==0 && scent_sea[mov_x][mov_y].second == 0)
                {
              //cout<<"moving candid..."<<endl;
              //cout<<i<<' '<<mov_x<<' '<<mov_y<<' '<< to_str(d)<<endl;
                  //냄새 없는 곳임 
                  moving_dir.push_back(make_tuple(mov_x,mov_y,d));     
                }
                
              }
              
            }
            if(moving_dir.size() == 1)
            {
              //방향 결정
              int mov_x = get<0>(moving_dir[0]);
              int mov_y = get<1>(moving_dir[0]);
              int mov_dir = get<2>(moving_dir[0]);
              sea[mov_x][mov_y].push_back(make_pair(i,mov_dir));
              sea[x][y].pop_back();
              //이동하고 사라짐
              scent_spread.push_back(make_tuple(mov_x,mov_y,i));//이동 장소에 냄새남김
              //다른 냄새 있는칸으로는 절대 이동 안함
            }
            else if(moving_dir.size() >=2)
            {
              pair<int,int> fin_mov = make_pair(987654321,-1);//우선순위와 moving_dir 인덱스
              int cur_dir = sea[x][y][0].second;
              //0~4까지 shark_dir[i][cur_dir][0~4]
              for(int mo = 0;mo<moving_dir.size();mo++)
                {
                  int candid_dir = get<2>(moving_dir[mo]);
                  for(int di = 0;di<4;di++)
                    {
                      if(candid_dir == shark_dir[i][(cur_dir-1)][di])
                      {
                        if(fin_mov.first > di)
                        {
                          fin_mov = make_pair(di,mo);
                        }
                      }
                    }
                  
                }
              //가장 낮은 우선순위 방향 결정후 이동
              int mov_x = get<0>(moving_dir[fin_mov.second]);
              int mov_y = get<1>(moving_dir[fin_mov.second]);
              
              
              int mov_dir = get<2>(moving_dir[fin_mov.second]);
              //cout<<i<<"'s cur dir!!::"<<to_str(cur_dir)<<endl;
              //cout<<i<<" chosed from dir!!"<<endl;
              //cout<<to_str(mov_dir)<<endl;
              sea[mov_x][mov_y].push_back(make_pair(i,mov_dir));
              sea[x][y].pop_back();
              //이동하고 사라짐
              scent_spread.push_back(make_tuple(mov_x,mov_y,i));
              //우선순위 따라 방향 결정해야함
            }
            else
            {
              
              //갈곳이 없음
              //자신의 냄새로 결정
              //자신의 냄새도 두곳일 경우 우선순위 봐야함
              for(int d=1;d<5;d++)
                {
                  int mov_x = x+dx[d];
                  int mov_y = y+dy[d];
                  if(calc_range(mov_x,N) && calc_range(mov_y,N))
                  {
                    if(scent_sea[mov_x][mov_y].first == i)
                    {
                      moving_dir.push_back(make_tuple(mov_x,mov_y,d));
                      
                    }
                    
                  }
                  
                }
                if(moving_dir.size()== 1)
                {
              int mov_x = get<0>(moving_dir[0]);
              int mov_y = get<1>(moving_dir[0]);
              int mov_dir = get<2>(moving_dir[0]);
              sea[mov_x][mov_y].push_back(make_pair(i,mov_dir));
              sea[x][y].pop_back();
              //이동하고 사라짐
              scent_spread.push_back(make_tuple(mov_x,mov_y,i)); 
                }
                else // 없는 경우는 없음 (두개 이상일 경우?)
                {
                  
              pair<int,int> fin_mov = make_pair(987654321,-1);//우선순위와 moving_dir 인덱스
              int cur_dir = sea[x][y][0].second;
              //0~4까지 shark_dir[i][cur_dir][0~4]
              for(int mo = 0;mo<moving_dir.size();mo++)
                {
                  int candid_dir = get<2>(moving_dir[mo]);
                  for(int di = 0;di<4;di++)
                    {
                      if(candid_dir == shark_dir[i][(cur_dir-1)][di])
                      {
                        if(fin_mov.first > di)
                        {
                          fin_mov = make_pair(di,mo);
                        }
                      }
                    }
                }
              int mov_x = get<0>(moving_dir[fin_mov.second]);
              int mov_y = get<1>(moving_dir[fin_mov.second]);
              int mov_dir = get<2>(moving_dir[fin_mov.second]);
              sea[mov_x][mov_y].push_back(make_pair(i,mov_dir));
              sea[x][y].pop_back();
              //이동하고 사라짐
              scent_spread.push_back(make_tuple(mov_x,mov_y,i));

                  
            }
          
        }
      }
          //이동 다하고 냄새 뿌려야됨
          //1번 냄새때문에 이동을 안함
        //상어 이동 다하면 냄새 줄이고 중복되는 상어 없앰
    }
    
    /*for(int sce = scent_spread.size()-1;sce>=0;sce--)
      {
        int sce_x = get<0>(scent_spread[sce]);
        int sce_y = get<1>(scent_spread[sce]);
        int sce_t = get<2>(scent_spread[sce]);
        scent_sea[sce_x][sce_y] = make_pair(sce_t,K);
        //1~4까지 되었기에 역으로 하면 동일한 위치에 낮은 숫자가 덮어씀
      }*/
      clear_sea(N,K);
  }
  //print_sea_scent(N,result);
  if(result == 1000)
    return -1;
  return result;
}
int main() {
  //초기 냄새 초기화 필요
    int N,M,K;
    cin>>N>>M>>K;
    int shark_dir[M+1][4][4]; //상어 우선순위
    for(int i=0;i<N;i++)
      {
        for(int j=0;j<N;j++)
          {
            int tmp;
            cin>>tmp;
            if(tmp != 0)
            {
              sea[i][j].push_back(make_pair(tmp,0));
              scent_sea[i][j] = make_pair(tmp,K);              
            }

            
          }
        
      }
    for(int i=0;i<M;i++)
      {
        int tmp;
        cin>>tmp;
        for(int j=0;j<N;j++)
          {
            for(int k=0;k<N;k++)
              {
                if(sea[j][k].size() !=0)
                {
                  if(sea[j][k][0].first == (i+1))
                  {
                    sea[j][k][0].second = tmp;
                  }
                  //break해봤자 그리 크지도 않음 그냥 생략
                  //최대 400회 연산
                }
                
              }
            
          }
      }
    for(int i=1;i<=M;i++)
      {
        for(int r=0;r<4;r++)
          {
            for(int c=0;c<4;c++)
              {
                cin>>shark_dir[i][r][c];
              }
          }
      }
  /*for(int i=1;i<=M;i++)
      {
        cout<<i<<"번 상어 우선순위"<<endl;
        for(int r=0;r<4;r++)
          {
            cout<<to_str(r+1)<<"::";            
            for(int c=0;c<4;c++)
              {
                cout<<to_str(shark_dir[i][r][c])<<' ';
              }
            cout<<endl;
          }
      }*/
  cout<<calc(N,M,K,shark_dir)<<endl;  
}