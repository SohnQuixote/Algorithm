#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
  뱀
  게임 N*N 정사각 보드 위에서 진행
  뱀은 처음에 오른쪽 향함
  뱀 맨위 맨 좌측 길이 1
  게임 몇초에 끝나는지 계산
  뱀은 매초마다 이동
*/
const int MAX = 102;
//최대 크기더라도 1로 둘러쌀 수 있게 하기위해
//(1,1) ~ (100,100)
//vector<pair<int,int>> apples;
queue<pair<int,char>> directions;
int dx[4] = {1,0,-1,0}; //-----x축 | y축
int dy[4] = {0,1,0,-1};
//dx는 열 dy는 행
//머리 위치랑 꼬리위치 별개로 계산 해야함
int maps[MAX][MAX] = {0,};
int calc(int N)
{
  //D == 68
  //L == 76
  int result =0;
  int cur_dir = 0;
  int ch_dir_time = directions.front().first;
  int ch_dir_way = directions.front().second;
  int cur_x = 1;
  int cur_y = 1;
  int cur_tail_x = 1;
  int cur_tail_y = 1;
  queue<int> tail_dir;
  //헤드 다르게 표현해야함
  int body_size =1;
  while(true)
    {
      result +=1;
      //1초부터 시작
      
      cur_x += dx[cur_dir];
      cur_y += dy[cur_dir];
      tail_dir.push(cur_dir);
      maps[cur_y][cur_x] +=1;
      if(maps[cur_y][cur_x] >= 2)
      {
        //벽을 마주친거나 자신의 몸을 마주
        return result;
      }
      else if(maps[cur_y][cur_x] == 1)
      {
        //빈 공간
        int tail_idx = tail_dir.front();
        tail_dir.pop();
        maps[cur_tail_y][cur_tail_x] = 0;
        //근처 자신의 몸 공간으로 줄여야함
        //몸이 겹쳐 있어도 올바른 몸공간으로 줄여야 함
        //꼬리 진행 방향 필요
        cur_tail_y += dy[tail_idx];
        cur_tail_x += dx[tail_idx];
        //이전의 진행 공간
        //cur_tail_y += dy[cur_dir];
        //cur_tail_x += dx[cur_dir];
        
      }
      else if(maps[cur_y][cur_x] == 0)
      {
        //사과 꼬리 이동하지 않음
        //사과 먹으면 꼬리 이동이 쌓임
        maps[cur_y][cur_x] = 1;
        body_size+=1;
        //cur_tail_x -= dx[cur_dir];
        //cur_tail_y -= dy[cur_dir];
      }
      /*cout<<"---"<<result<<"---"<<endl;
      for(int i=0;i<N+2;i++)
        {
          for(int j=0;j<N+2;j++)
            {
              cout<<maps[i][j]<<' ';
            }
          cout <<endl;
        }
      cout<<endl<<endl;*/
    //방향 변경 잘됨
    if(result == ch_dir_time)
      {
        if(ch_dir_way == 68)
        {
          //오른쪽
          cur_dir = (cur_dir+1) %4;
        }
        else if(ch_dir_way == 76)
        {
          cur_dir = (cur_dir-1) %4;
          if(cur_dir < 0)
            cur_dir +=4;
          
          //왼쪽
        }
        directions.pop();
        if(!directions.empty())
        {  
          ch_dir_time = directions.front().first;
          ch_dir_way = directions.front().second;
        }
        
      }  
      
    }
  return result;
}
int main() {
  for(int i=0;i<MAX;i++)
    for(int j=0;j<MAX;j++)
      maps[i][j] = 5;    
  int N , K; 
  int L;
  cin>>N;
  for(int i=1;i<N+1;i++)
    for(int j=1;j<N+1;j++)
      maps[i][j] = 0;
  //허용된 크기만큼 맵 0으로 할당
  maps[1][1] = 1;
  cin>>K;
  for(int i=0;i<K;i++)
    {
      int x,y;
      cin>>x>>y;
      //apples.push_back(make_pair(x,y));
      maps[x][y] = -1; //사과 = -1
    }
  cin>>L;
  for(int i=0;i<L;i++)
    {
      int x;
      char d;
      cin>>x>>d;
      directions.push(make_pair(x,d));
      //알파벳 쓰면 다 종료되버림
    }
   cout<<calc(N)<<endl;
}