#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
  화성 탐사
  출발 - 목적지 최적 경로
  화성 공간 N * N
  0,0 ~> N-1 N-1 이동 최소 비용
  다익스트라 사용 / bfs

*/
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

bool calc_range(int a,int n)
{
  if(a>=0 && a<n)
    return true;
  return false;
}
int calc(vector<vector<int>> mars, int N)
{
  //이동하면서 min사용?(visited false일 경우는 그냥 대체)
  //(true면 ) min
  //bfs 시간초과 안하나? 
  vector<vector<bool>> visited(N,vector<bool>(N,false));
  queue<pair<int,int>>q;
  vector<vector<int>> orig_mars = mars;
  q.push(make_pair(0,0));
  visited[0][0] = true;
  while(!q.empty())
    {
      int x = q.front().first;
      int y = q.front().second;
      //visited[x][y] = true;      
      q.pop();
      for(int i=0;i<4;i++)
        {
          int mv_x = x+dx[i];
          int mv_y = y+dy[i];
          if(calc_range(mv_x,N) && calc_range(mv_y,N))
          {
            //범위 안
            if(!visited[mv_x][mv_y])
            {
              q.push(make_pair(mv_x,mv_y));
              visited[mv_x][mv_y] = true;
              mars[mv_x][mv_y] += mars[x][y];
            }
            else if((orig_mars[mv_x][mv_y] + mars[x][y]) < mars[mv_x][mv_y]) //들렀는데 이렇게 가는게 빠를 경우
            {
              q.push(make_pair(mv_x,mv_y));
              mars[mv_x][mv_y] = orig_mars[mv_x][mv_y] + mars[x][y];
            }
          }
          
        }
    }
  return mars[N-1][N-1];
}
int main() {
  int T;
  cin>>T;
  vector<int> results;
  for(int i=0;i<T;i++)
    {
      int N;
      cin>>N;
      vector<vector<int>>mars(N,vector<int>(N,0)); 
      for(int r= 0;r<N;r++)
        {
          for(int c = 0;c<N;c++)
            {
              cin>>mars[r][c];
              
            }
        }
        results.push_back(calc(mars,N));
    }
  for(int i=0;i<T;i++)
    cout<<results[i]<<endl;
  
}