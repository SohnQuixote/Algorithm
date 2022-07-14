#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

/*
  1249 보급로
  복구 시간 가장 짧은 경로 
*/
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
const int INF = 987654321;
int result = INF;
vector<vector<int>> grid(100,vector<int>(100,0));
bool calc_range(int x, int y, int N)
{
  if(x>=0 && x<N && y>=0 && y<N)
    return true;
  return false;
  
}
int find_shortest(int N)
{
  vector<vector<int>>result(N,vector<int>(N,INF));
  queue<pair<int,int>>q;
  q.push(make_pair(0,0));
  result[0][0] = 0;
  while(!q.empty())
    {
      int r = q.front().first;
      int c = q.front().second;
      q.pop();
      for(int d =0;d<4;d++)
        {
          int mov_r = r+dx[d];
          int mov_c = c +dy[d];
          if(calc_range(mov_r,mov_c,N))
          {
            if(result[mov_r][mov_c] > (grid[mov_r][mov_c] + result[r][c]))
            {
              result[mov_r][mov_c] = grid[mov_r][mov_c] + result[r][c];
              q.push(make_pair(mov_r,mov_c));
              
            }
            
          }

          
        }
      
    }

  return result[N-1][N-1];
  //시간초과
}

int main() {
  int T;
  cin>>T;
  vector<int> results;
  for(int i=0;i<T;i++)
    {
      int N;
      cin>>N;
      for(int r=0;r<N;r++)
        {
        for(int c=0;c<N;c++)
          {
            int tmp;
            scanf("%1d" , &tmp);
            grid[r][c] = tmp;
          }
        }
      vector<vector<bool>> visited(N,vector<bool>(N,false));
       results.push_back(find_shortest(N));
    }
  for(int i=0;i<T;i++)
    {
        cout<<"#"<<(i+1)<<' '<<results[i]<<endl;
      
    }
}