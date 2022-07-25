#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int n,m;
const int INF = 987654321;
vector<vector<int>>map(100,vector<int>(100,0));


int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

bool calc_range(int x, int y)
{
  if(x>=0 && x<n && y>=0 && y<m)
    return true;
  return false;
}
int calc()
{
  vector<vector<int>> root(n,vector<int>(m,0));
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      root[i][j] = INF;
  queue<pair<int,int>>q;
  root[0][0] = map[0][0];
  q.push(make_pair(0,0));
  while(!q.empty())
    {
      int x= q.front().first;
      int y = q.front().second;
      q.pop();
      for(int d= 0;d<4;d++)
        { 
          int mov_x = x+dx[d];
          int mov_y = y+dy[d];
          if(calc_range(mov_x,mov_y))
          {
            if(root[mov_x][mov_y] >(root[x][y] + map[mov_x][mov_y]))
            {
            root[mov_x][mov_y]= root[x][y] +map[mov_x][mov_y];
              q.push(make_pair(mov_x,mov_y));
              
            }
          }

          
        }

      
    }
  return root[n-1][m-1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>n>>m;
  for(int i=0;i<n;i++)
    {
      string tmp;
      cin>>tmp;
    for(int j=0;j<m;j++)
      map[i][j] = static_cast<int>(tmp[j] - '0');
    }
  cout<<calc()<<endl;
}