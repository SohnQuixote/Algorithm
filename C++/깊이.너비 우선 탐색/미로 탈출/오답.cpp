#include <iostream>
#include <queue>
using namespace std;
/*
  미로탈출
  N*M 형태의 미로
  0,0에서 시작
  N-1,M-1 이 도착지
  괴물 부분 1로 표시 없는 부분 0로 표시
*/
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int calc(int **map,int N,int M)
{
  queue<pair<int,int>> q;
  q.push(make_pair(0,0));
  int length = 1;
  while(!q.empty())
    {
      int x = q.front().first;
      int y = q.front().second;
      q.pop();
      for(int i=0;i<4;i++)
        {
          int dir_x = x+dx[i];
          int dir_y = x+dy[i];
          if(dir_x>=0 && dir_x<=N-1 && dir_y>=0 && dir_y<=M-1)
          {
            if(map[dir_x][dir_y] == 1)
            {
              q.push(make_pair(dir_x,dir_y));
              length++;
              map[dir_x][dir_y] = length;
              //map[dir_x][dir_y] +=map[x][y];
            }
          }
          
        }
    }
  return map[N-1][M-1];
}

int main() {
  int N,M;
  int **map;
  cin>>N>>M;
  map = new int*[N];
  for (int i=0;i<N;i++)
    {
      map[i] = new int[M];
    }
  for(int i=0;i<N;i++)
    {
      for (int j=0;j<M;j++)
        cin>>map[i][j];
    }
  cout<<calc(map,N,M)<<endl;
    for(int i=0;i<N;i++)
    {
      for (int j=0;j<M;j++)
        cout<<map[i][j]<<' ';
      cout<<endl;
    }
}