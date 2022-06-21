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
//해당 보드의 색깔 구분
vector<pair<int,int>> grid[MAX][MAX];
//말 번호, 방향
tuple<int,int,int,int> info[11];
//해당 말의 좌표, 방향, 높이
int N;
void print_info(int k)
{
  cout<<endl<<"printing"<<endl;
  for(int i=1;i<=k;i++)
    {
      cout<<i<<endl;
      cout<<"x,y"<<endl;
      cout<<get<0>(info[i])<<' '<<get<1>(info[i])<<endl;
      cout<<"d,h"<<endl;
      cout<<get<2>(info[i])<<' '<<get<3>(info[i])<<endl;
    }
}
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
  if(x>=0&&x<N &&y>=0 && y<N&&(board[x][y] == 0 || board[x][y] == 1))
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
          int h = get<3>(info[i]);
          int mov_x = x+dx[d];
          int mov_y = y+dy[d];
          queue<pair<int,int>>q; //말의 번호, 방향
          //cout<<x<<' '<<y<<' '<<mov_x<<' '<<mov_y<<endl;
          //cout<<calc_range(mov_x,mov_y)<<endl;
          if(calc_range(mov_x,mov_y))
          {
            if(board[mov_x][mov_y] == 0)
            {
              //흰
              for(int j=h;j<grid[x][y].size();j++)
                {
                  //cout<<i<<"is moving::"<<endl;
                  q.push(make_pair(grid[x][y][j].first ,grid[x][y][j].second));
                }
            }
            else
            {
              //빨
              for(int j=grid[x][y].size()- 1;j>=h;j--)
                {
                  q.push(make_pair(grid[x][y][j].first ,grid[x][y][j].second));
                }
            }
          }
          else
          {
            d = chg_dir(d);
            mov_x = x+dx[d];
            mov_y = y+dy[d];
            if(calc_range(mov_x,mov_y))
            {
              if(board[mov_x][mov_y] == 0)
              {
              //흰
              for(int j=h;j<grid[x][y].size();j++)
                {
                  if(j==h)
                    q.push(make_pair(grid[x][y][j].first,d));
                  else
                    q.push(make_pair(grid[x][y][j].first ,grid[x][y][j].second));
                }
              }
            else
              {
              //빨
              for(int j=grid[x][y].size()- 1;j>=h;j--)
                {
                  if(j==h)
                    q.push(make_pair(grid[x][y][j].first,d));
                  else
                    q.push(make_pair(grid[x][y][j].first ,grid[x][y][j].second));
                }
              }
              
            }
            
          }
          int orig_h = grid[mov_x][mov_y].size();
          while(!q.empty())
            {
              //pop_back으로 원래좌표 삭제            
              pair<int,int>pos = q.front();
              q.pop();
              int num = pos.first;
              int dir = pos.second;
              grid[mov_x][mov_y].push_back(make_pair(num,dir));
              //orig_h++;
              info[num] = make_tuple(mov_x,mov_y,dir,orig_h);
              orig_h++;
              grid[x][y].pop_back();
            }
          //print_info(k);
          if(grid[mov_x][mov_y].size()>=4)
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
      info[i] = make_tuple(a,b,c,0); //현재 인덱스 0
    }
  //print_info(K);
  cout<<play(K)<<endl;
}