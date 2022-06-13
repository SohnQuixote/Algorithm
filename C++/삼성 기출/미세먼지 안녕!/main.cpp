#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int N,M;
const int MAX = 51;
vector<vector<int>>map(MAX,vector<int>(MAX,0));
vector<int*> windways[2];
/*
  미세먼지 안녕
  R * C 격자판
  (r,c) r행 c열
  공기청정기 1열 존재 
  1초동안
  1. 미세먼지 확산
    인접 4방향 확산
    해당 값/5 확산
    남은 먼지 -> 확산되고 남은 양
  2. 공기 청정기 작동
    위쪽 반시계 순환
    아래쪽 시계 순환
    바람 불면 미세먼지 바람 방향 한칸씩 이동
  공기청정기로 들어가야지 미세먼지 사라짐
  먼지 만나면 이동 방향 다음 좌표로 이동
*/
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void print_map()
{
  cout<<endl<<endl;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        {
          cout<<map[i][j]<<' ';
        }
        cout<<endl;
    }
}
bool calc_range(int x,int y, int a,int b)
{
  if(x>=0 && x<a && y>=0 && y<b && map[x][y] != -1)
    return true;
  return false;
}
int sum_dust(int a, int b)
{
  int result = 0;
  for(int i =0;i<a;i++)
    {  
      for(int j=0;j<b;j++)
        {
          if(map[i][j]>0)
            result+=map[i][j];
        }
      
    }
  return result;
}
int time_flow(int T)
{
  //cout<<T<<endl;
  while(T)
    {
  //확산
  queue<tuple<int,int,int>>q;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        {
          if(map[i][j] >0)
            q.push(make_tuple(i,j,map[i][j]));
        }
    }
  while(!q.empty())
    {
      //동시에 일어나야 하니 값을 분리
      int x = get<0>(q.front());
      int y = get<1>(q.front());
      int c = get<2>(q.front());
      q.pop();
      int num = 0;
      for(int d =0;d<4;d++)
        {
          int mov_x = x+dx[d];
          int mov_y = y+dy[d];
          if(calc_range(mov_x,mov_y,N,M))
          {
            num+=1;
            map[mov_x][mov_y] += (c/5);
          }
        }
      map[x][y] -= num * (c/5);
      
    }
      
      //print_map();
  //청정
  
  int u_size = windways[0].size();
  int d_size = windways[1].size();
  *(windways[0][u_size-1]) = 0;
  *(windways[1][d_size-1]) = 0;
  for(int i=u_size-2;i>=0;i--)
    {
      if(*(windways[0][i]))
      {
         *(windways[0][i+1]) = *(windways[0][i]); 
         *(windways[0][i]) = 0;
      }
    }
  for(int i=d_size-2;i>=0;i--)
    {
      if(*(windways[1][i]))
      {
         *(windways[1][i+1]) = *(windways[1][i]); 
         *(windways[1][i]) = 0;
      }
    }
      T--;
      //print_map();
  }
  
  return sum_dust(N,M);
  //return time_flow(T-1);
}
int main() {
  int T;
  cin>>N>>M>>T;
  int starting_row =0;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        {
          cin>>map[i][j];
          if(!starting_row && map[i][j] == -1)
          {
            starting_row = i;
          }
          
        }
    }
  //바람길 포인터 변수로 받음
  //한번에 조작 가능
  
  for(int j=1;j<M;j++)
    {
      int *tmp_1 = &map[starting_row][j];
      int *tmp_2 = &map[starting_row+1][j];
      windways[0].push_back(tmp_1);
      windways[1].push_back(tmp_2);
    }
  for(int i =starting_row-1;i>=0;i--)
    {
      int *tmp = &map[i][M-1];
      windways[0].push_back(tmp);
    }
  for(int i= starting_row+2;i<N;i++)
    {
      int *tmp = &map[i][M-1];
      windways[1].push_back(tmp);
    }
  for(int j= M-2;j>=0;j--)
    {
      int *tmp_1 = &map[0][j];
      int *tmp_2 = &map[N-1][j];
      windways[0].push_back(tmp_1);
      windways[1].push_back(tmp_2);
    }
  for(int i=1;i<starting_row;i++)
    {
      int *tmp = &map[i][0];
      windways[0].push_back(tmp);
    }
  for(int i= N-2;i>starting_row+1;i--)
    {
      int *tmp = &map[i][0];
      windways[1].push_back(tmp);
    }
  cout<<time_flow(T)<<endl;
}