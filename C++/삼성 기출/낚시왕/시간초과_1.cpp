#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
/*
  낚시왕
  상어 낚시 격자판 R * C
  낚시왕 초기 위치 0열
  1초
  -> 낚시왕 오른쪽 한칸 이동
  -> 땅과 제일 가까운 상어 잡기
 -> 상어 이동
  상어 이동 ->
  입력으로 주어진 속도 이동 -> 경계 넘을 경우 방향 반대 바꿔서 이동
  상어 두마리 이상 가능
  크기 큰 상어 나머지 상어 잡아먹음
  낚시왕 잡은 상어 크기 결과
*/
int R,C;
typedef tuple<short,short,short,short,short> S;
const int MAX = 101;
typedef struct shark{
  short size = 0;
  short speed = 0;
  short dir = 0;
}shark;
//크기가 작은거부터 움직이면 덮어씌우기 해서 가능
//우선순위 큐 - 작은거 부터 움직임
short dr[5] = {0,-1,1,0,0};
short dc[5] = {0,0,0,1,-1};
vector<vector<shark>>grid(MAX,vector<shark>(MAX,shark{0,0,0}));
void print_grid(int r,int c)
{
  cout<<endl<<"Printing Grid::"<<endl;
  for(int i=1;i<=r;i++)
    {
      for(int j=1;j<=c;j++)
        {
          cout<<grid[i][j].size<<' ';
        }
      cout<<endl;
    }
  
  cout<<"Printing Direction::"<<endl;
  for(int i=1;i<=r;i++)
    {
      for(int j=1;j<=c;j++)
        {
          cout<<grid[i][j].dir<<' ';
        }
      cout<<endl;
    }
}
void shark_move()
{
  priority_queue<S,vector<S>,greater<S>> pq;
  for(int i=1;i<=R;i++)
    {
      for(int j=1;j<=C;j++)
        {
          if(grid[i][j].size)
          {
           pq.push(make_tuple(grid[i][j].size,grid[i][j].dir,grid[i][j].speed,i,j)); 
          }
        }
    }
  //상어들 작은 크기 우선
  while(!pq.empty())
    {
      short size = get<0>(pq.top());
      short r = get<3>(pq.top());
      short c = get<4>(pq.top());
      short speed = get<2>(pq.top());
      short dir = get<1>(pq.top());
      //cout<<size<<endl;
      pq.pop();
      //short orig_dir = dir;
      short mov_r = r;
      short mov_c = c;
      //short mov_r = r+speed*dr[dir];
      //short mov_c = c+speed*dc[dir];
      int i=1;
      while(i<=speed)
        {
          mov_r+=dr[dir];
          mov_c+=dc[dir];
          //부딪혔을 경우 방향변경 필요
          if(mov_r>R)
          {
            dir = 1;
            mov_r = R-1;
          }
          else if(mov_r<=0)
          {
            dir =2;
            mov_r = 2;
          }
          else if(mov_c>C)
          {
            dir = 4;
            mov_c = C-1;
          }
          else if(mov_c<=0)
          {
            dir = 3;
            mov_c = 2;
          }
          i++;
        }
      if(size == grid[r][c].size)
        grid[r][c] = shark{0,0,0};
      
      grid[mov_r][mov_c] = shark{size,speed,dir};
      //cout<<r<<' '<<c<<endl;
      //cout<<mov_r<<' '<<mov_c<<endl;
      //print_grid(R,C);
  }
}
short col_hunt(int col)
{
  short result = 0;
  for(int i=1;i<=R;i++)
    {
       if(grid[i][col].size>0)
       {
         result = grid[i][col].size;
         grid[i][col] = shark{0,0,0};
         break;
       }
    }
  return result;
}
int hunt(int C)
{
  int result = 0;
  int sec =1;
  while(sec<=C)
    {
      //해당 열 사냥
      //cout<<sec<<endl;
      result +=col_hunt(sec);
      //상어 이동
      //print_grid(R,C);
      shark_move();
      //print_grid(R,C);
      sec+=1;
    }
  return result;
}
int main() {
  //hunt(6);
  int M = 0;
  cin>>R>>C>>M;
  //C초동안 이동
  for(int i=0;i<M;i++)
    {
      short r,c,s,d,z;
      cin>>r>>c>>s>>d>>z;
      grid[r][c] = shark{z,s,d};
    }
  cout<<hunt(C)<<endl;
    //크기가 작은 상어부터 이동
}