#include <iostream>
#include <queue>
using namespace std;
/*
  벽 부수고 이동하기
  (0,0)에서 (N-1,M-1)까지 이동
  벽은 한개까지 부술 수 있음
  0 이동 할 수 있는 곳 1 이동할 수 없는 벽
  벽 한번씩 다 부숴볼 수 밖에 없음
  벽 부순 정보 갖고 있어야함
*/
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>>broken;
int calc(int **map,int N,int M)
{
  queue<pair<int,int>> visited;
  int **tmp_map = new int *[N];  
  for( int i=0;i<N;i++)
    {
      tmp_map[i] = new int[M];
    }
  //tmp_map 초기화
  int result = 9876543;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        tmp_map[i][j] = map[i][j];
    }
  tmp_map[0][0] = 1;
  visited.push(make_pair(0,0));
  //처음에는 그냥 안부수고 한번 해봄
  while(!visited.empty())
  {
    int x = visited.front().first;
    int y = visited.front().second;
    visited.pop();
    for(int i=0;i<4;i++)
      {
        int dir_x = x+dx[i];
        int dir_y = y+dy[i];
        if(dir_x>=0 && dir_x <= N-1 && dir_y >= 0 && dir_y <= M-1)
        {
          if(tmp_map[dir_x][dir_y] == 0)
          {
            //안들렀음
            tmp_map[dir_x][dir_y] = tmp_map[x][y]+1;
            visited.push(make_pair(dir_x,dir_y));
          }
          
        }
      }
  }
  if(tmp_map[N-1][M-1] != 0 && result> tmp_map[N-1][M-1])
  {
    result = tmp_map[N-1][M-1];
  }
  
  while(!broken.empty())
  {
  for(int i=0;i<N;i++)
  {
      for(int j=0;j<M;j++)
        tmp_map[i][j] = map[i][j];
  }
    int bx = broken.front().first;
    int by = broken.front().second;
    tmp_map[bx][by] = 0;
    broken.pop();
  tmp_map[0][0] = 1;
  visited.push(make_pair(0,0));
  while(!visited.empty())
  {
    int x = visited.front().first;
    int y = visited.front().second;
    visited.pop();
    for(int i=0;i<4;i++)
      {
        int dir_x = x+dx[i];
        int dir_y = y+dy[i];
        if(dir_x>=0 && dir_x <= N-1 && dir_y >= 0 && dir_y <= M-1)
        {
          if(tmp_map[dir_x][dir_y] == 0)
          {
            //안들렀음
            tmp_map[dir_x][dir_y] = tmp_map[x][y]+1;
            visited.push(make_pair(dir_x,dir_y));
          }
          
        }
      }
  }
    if(tmp_map[N-1][M-1] != 0 && result>tmp_map[N-1][M-1])
    {
      result = tmp_map[N-1][M-1];
    }
  }
  if(result == 9876543)
    return -1;
  return result;
}
int main() {
  int N,M;
  char ch;
  cin>>N>>M;
  int **map = new int*[N];
  for(int i=0;i<N;i++)
    map[i] = new int[M];
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        {
        scanf("%1d" , &map[i][j]);
          if(map[i][j] == 1)
          {
            broken.push(make_pair(i,j));
          }
          
        }
      ch = cin.get();
    }
  cout<<calc(map,N,M)<<endl;
}