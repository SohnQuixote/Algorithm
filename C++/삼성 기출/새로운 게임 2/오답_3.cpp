#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
/*
  새로운 게임 2
*/
int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};
const int MAX = 12;
int board[MAX][MAX] ={0,};
vector<pair<int,int>> grid[MAX][MAX];
tuple<int,int,int> info[11];
int N;
int chg_dir(int a)
{
  if(a==1)
    return 2;
  else if(a==2)
    return 1;
  else if(a==3)
    return 4;
  else
    return 3;
}
bool calc_range(int x, int y)
{
  if(x>=0&&x<N &&y>=0 && y<N)
    return true;
  return false;
}
int play(int k)
{
  int result =1;
  while(1)
    {
       if(result>1000)
         return -1;
      for(int i=1;i<=k;i++)
        {
          int x = get<0>(info[i]);
          int y = get<1>(info[i]);
          int d = get<2>(info[i]);
          int mov_x = x+dx[d];
          int mov_y = y+dy[d];
          queue<tuple<int,int,int,int>>q;
          bool moved = false;
          if(calc_range(mov_x,mov_y)&& board[mov_x][mov_y] == 0)
          {
            //빨간색
            int size = 0;
            moved = true;
            for(int h=0;h<grid[x][y].size();h++)
              {
                if(grid[x][y][h].first == i)
                {
                  for(int k=h;k<grid[x][y].size();k++)
                    {
                     size++; q.push(make_tuple(mov_x,mov_y,grid[x][y][k].first,grid[x][y][k].second));
                      
                    }
                  break;
                }
              }
            while(size)
              {
                grid[x][y].pop_back();
                size--;
              }
          }
          else if(calc_range(mov_x,mov_y) && board[mov_x][mov_y] == 1)
          {
            moved = true;
            for(int h=0;h<grid[x][y].size();h++)
              {
                if(grid[x][y][h].first == i)
                {
                  for(int k=h;k<grid[x][y].size();k++)
                    { 
                      
                      q.push(make_tuple(mov_x,mov_y, grid[x][y].back().first, grid[x][y].back().second));
                      grid[x][y].pop_back();
                    }
                  break;
                }
              } 
            
          }
          else if((calc_range(mov_x,mov_y)&& board[mov_x][mov_y] == 2) || calc_range(mov_x,mov_y) == false)
          {
            d = chg_dir(d);
            mov_x = x+dx[d];
            mov_y = y+dy[d];
            if(calc_range(mov_x,mov_y) && board[mov_x][mov_y] == 0)
            {
              moved = true;
              int size = 0;
              for(int h=0;h<grid[x][y].size();h++)
              {
                if(grid[x][y][h].first == i)
                {
                  size++;
                  q.push(make_tuple(mov_x,mov_y,i,d));
                  for(int k=h+1;k<grid[x][y].size();k++)
                    {
                      size++; 
                      q.push(make_tuple(mov_x,mov_y,grid[x][y][k].first,grid[x][y][k].second));
                      
                    }
                  break;
                }
              }
            while(size)
              {
                grid[x][y].pop_back();
                size--;
              }
            }
            else if(calc_range(mov_x,mov_y) && board[mov_x][mov_y] == 1)
            {
              moved = true;
              for(int h=0;h<grid[x][y].size();h++)
              {
                if(grid[x][y][h].first == i)
                {
                  q.push(make_tuple(mov_x,mov_y,i,d));
                  grid[x][y].erase(grid[x][y].begin()+h);
                  for(int k=h+1;k<grid[x][y].size();k++)
                    { 
                      
                      q.push(make_tuple(mov_x,mov_y, grid[x][y].back().first, grid[x][y].back().second));
                      grid[x][y].pop_back();
                    }
                  break;
                }
              }
            }
            
          }
        while(!q.empty())
        {
          int mov_x = get<0>(q.front());
          int mov_y = get<1>(q.front());
          int c = get<2>(q.front());
          int d = get<3>(q.front());
          q.pop();
          info[c] = make_tuple(mov_x,mov_y,d);
          grid[mov_x][mov_y].push_back(make_pair(c,d));
        }
        if(grid[mov_x][mov_y].size() >=4)
          return result;
      }
      result++;
    }  
}
int main() {
  int K;
  cin>>N>>K;
  for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)   
        cin>>board[i][j];
  for(int i=1;i<=K;i++)
    {
      int a,b,c;
      cin>>a>>b>>c;
      a--;
      b--;
      grid[a][b].push_back(make_pair(i,c));
      info[i] = make_tuple(a,b,c);
    }
  cout<<play(K)<<endl;
}