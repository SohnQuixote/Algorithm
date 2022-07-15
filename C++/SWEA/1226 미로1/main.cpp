#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
  미로
*/
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
vector<vector<int>>maze(16,vector<int>(16,0));
bool calc_range(int x, int y)
{
  if(x>=0 && x<16 && y>0 && y<16 && maze[x][y] !=1)
    return true;
  return false;
  
}
int calc(int x, int y)
{
  queue<pair<int,int>>q;
  q.push(make_pair(x,y));
  vector<vector<bool>> visited(16,vector<bool>(16,false));
  while(!q.empty())
    {
      pair<int,int> pos = q.front();
      visited[pos.first][pos.second] = true;
      if(maze[pos.first][pos.second] == 3)
        return 1;
      q.pop();
      for(int d=0;d<4;d++)
        {
          int mov_x = pos.first+dx[d];
          int mov_y = pos.second+dy[d];
          if(calc_range(mov_x,mov_y) &&!visited[mov_x][mov_y])
            {
              q.push(make_pair(mov_x,mov_y));
            
            }
        }
      

      
    }

  return 0;
}
int main() {
  for(int i=0;i<10;i++)
    {
      int num;
      cin>>num;
      int s_x,s_y;
      for(int r = 0;r<16;r++)
        {
        for(int c=0;c<16;c++)
          {
          scanf("%1d", &maze[r][c]);
            if(maze[r][c] == 2)
            {
              s_x =r;
              s_y = c;
            }
          }

        }
      cout<<"#"<<num<<' '<<calc(s_x,s_y)<<endl;
      
    }
}