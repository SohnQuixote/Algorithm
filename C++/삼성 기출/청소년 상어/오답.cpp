#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
/*
  청소년 상어
  4 * 4크기 공간
  한 칸에는 물고기 1마리 각 물고기 번호 방향 
  번호 (1~16) 방향 (상하좌우 대각선)
  번호 작은 물고기 부터 이동 -> 배열로 해서 이동시킴
  물고기 한칸 이동
  이동 못하는 칸이면 반시계 45도씩 계속 이동
  물고기 이동하면 서로 위치 바꿈
  상어 0,0부터 시작  
  그리디?
  행이 x 열이 y
*/
int dy[8] = {0,-1,-1,-1,0,1,1,1}; //0~7
int dx[8] = {-1,-1,0,1,1,1,0,-1};
bool calc_range(int a)
{
  if(a>=0 && a<=3)
    return true;
  return false;
}
int calc(vector<vector<int>> sea,tuple<int,int,int> fishes[],int shark_x,int shark_y, int shark_dir, int shark_ate)
{
  //-1,-1,-1 막 들어오는 것임
  //함수의 종료 조건
  //상어가 밖에 있고 존재하는 모든 물고기가 0,0으로 도달 하지 못할때
  //sea[shark_x][shark_y] = -1; //상어 존재해서 물고기가 못감
  //sea[shark_x][shark_y] = 0;
  //cout<<"orig_loc"<<shark_x<<' '<<shark_y<<' '<<shark_dir<<endl;
    //상어가 공간 안에 있음
    //1.물고기 먼저 이동
    for(int i=1;i<=16;i++)
      {
        int orig_dir = get<0>(fishes[i]);
        int fish_x = get<1>(fishes[i]);
        int fish_y = get<2>(fishes[i]);
        if(orig_dir != -1)
        {
          //물고기 생존
          int mov_dir;
          int mov_fish_x;
          int mov_fish_y;
          for(int d = 0;d<8;d++)
            {
              mov_dir = (orig_dir+d)%8;
              mov_fish_x = fish_x +dx[mov_dir];
              mov_fish_y = fish_y +dy[mov_dir];
              //cout<<i<<"is trying to..."<<endl;
              //cout<<mov_dir<<' '<<mov_fish_x<<' '<<mov_fish_y<<endl;
              if(calc_range(mov_fish_x) && calc_range(mov_fish_y) && (mov_fish_x != shark_x || mov_fish_y != shark_y))
              {
                //기존에 있는애랑 위치 변경 0이어도 위치 변경됨              
                //cout<<i<<" moving to..."<<mov_dir<<endl;
                int mov_fish_num = sea[mov_fish_x][mov_fish_y];
                sea[mov_fish_x][mov_fish_y] = i;
                sea[fish_x][fish_y] = mov_fish_num;
                fishes[i] = make_tuple(mov_dir,mov_fish_x,mov_fish_y);
                if(mov_fish_num != 0)
                {
                  fishes[mov_fish_num] = make_tuple(get<0>(fishes[mov_fish_num]) , fish_x,fish_y);
                }
                
                break;
              }
              
            }
        }
      }
    
    //상어 이동
    int mv_shark = 0;
    int mv_shark_x = shark_x + dx[shark_dir];
    int mv_shark_y = shark_y + dy[shark_dir];
    int orig_shark_ate = shark_ate;
    while(calc_range(mv_shark_x) && calc_range(mv_shark_y))
      {
        //cout<<mv_shark_x<<' '<<mv_shark_y<<endl;
        //범위 안에 있을 때
        if(sea[mv_shark_x][mv_shark_y] != 0)
        {
          //먹이가 있음
          int chged_shark_dir = get<0>(fishes[sea[mv_shark_x][mv_shark_y]]);
          fishes[sea[mv_shark_x][mv_shark_y]] = make_tuple(-1,-1,-1); //먹어서 없어짐//이동 필요 없음
          int fed = sea[mv_shark_x][mv_shark_y];
          sea[mv_shark_x][mv_shark_y] = 0;
          
          shark_ate = max(shark_ate, calc(sea,fishes,mv_shark_x,mv_shark_y,chged_shark_dir,orig_shark_ate + fed));//누적됨
          sea[mv_shark_x][mv_shark_y] = fed;
          fishes[sea[mv_shark_x][mv_shark_y]] = make_tuple(chged_shark_dir,mv_shark_x,mv_shark_y);                 //안먹고 다른곳도 먹어봐야함
          mv_shark++;
          
        }
        mv_shark_x += dx[shark_dir];
        mv_shark_y += dy[shark_dir];

        
    }
    
  return shark_ate;
}
int main() {
  vector<vector<int>> sea (4, vector<int>(4,0));
  tuple<int,int,int> fishes_dir[17]; //1~16
  //tuple써서 이동 방향과 좌표 저장
  //int shark_dir = 0;
  
  
  for(int i=0;i<4;i++)
    {
      for(int j=0;j<4;j++)
        {
          int num,dir;
          cin>>num>>dir;
          fishes_dir[num] = make_tuple(dir-1,i,j);
          sea[i][j] = num;
          
        }
      
    }
    /*for(int i=0;i<4;i++)
      {
        for(int j=0;j<4;j++)
          {
            cout<<sea[i][j]<<' ';
          }
          cout<<endl;
      }
  for(int i=0;i<4;i++)
      {
        for(int j=0;j<4;j++)
          {
            cout<<get<0>(fishes_dir[sea[i][j]])<<' ';
          }
          cout<<endl;
      }*/
  int shark_dir = get<0>(fishes_dir[sea[0][0]]);
  fishes_dir[sea[0][0]] = make_tuple(-1,-1,-1);//먹혔음
  //방향 좌표 x 좌표 y
  //cout<<"tillgood"<<endl;
  sea[0][0] = 0;
  cout<<calc(sea,fishes_dir,0,0,shark_dir, sea[0][0])<<endl;
  //처음 있는거 먹고 시작
  //재귀로 모든 경우 탐색
  //종료조건 
}