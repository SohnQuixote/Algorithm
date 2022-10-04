#include <iostream>
#include <cstring>
using namespace std;
int cache[100][100] = {0,};
int map[100][100] = {0,};
int C;
int N;
int dx[2] = {1,0};
int dy[2] = {0,1};
bool calc_range(int x, int y)
{
  if(x>=0 && x<N && y>=0 && y<N)
    return true;
  return false;
}
void move(int x,int y)
{
  if(x==N-1 && y== N-1)
    return;
  for(int d=0;d<2;d++)
    {
      int mov_x = x+(dx[d]*map[x][y]);
      int mov_y = y+(dy[d] * map[x][y]);
      if(calc_range(mov_x,mov_y))
      {
        if(!cache[mov_x][mov_y])
        {
          cache[mov_x][mov_y]  =1;
          move(mov_x,mov_y);
        }
        
      }

      
    }
  
}
int main() {
  cin>>C;
  for(int tc=0;tc<C;tc++)
    {
      cin>>N;
      memset(cache,0,sizeof(cache));
      for(int r=0;r<N;r++)
        for(int c=0;c<N;c++)
          cin>>map[r][c];
      cache[0][0] = 1;
      move(0,0);
      if(cache[N-1][N-1])
        cout<<"YES\n";
      else
        cout<<"NO\n";
    }
  
  
  
}