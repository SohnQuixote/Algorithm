#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
/*
  온풍기 안녕
  먹은 초콜릿의 수 - 스텝 수
  조사하는 칸 K이상이면 종료
*/
int R,C,K;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
vector<vector<int>>room(20,vector<int>(20,0));
int spread_dir[4][3][2] = {{{-1,-1},{-1,0},{-1,1}},{{-1,1},{0,1},{1,1}},{{1,1},{1,0},{1,-1}},{{1,-1},{0,-1},{-1,-1}}};
vector<vector<vector<bool>>>wall(4,vector<vector<bool>>(20,vector<bool>(20,false))); //x,y에서 해당 방향 못감
vector<vector<bool>>inspect(20,vector<bool>(20,false));
vector<vector<int>>device(20,vector<int>(20,-1));
int chocolate = 0;
int mod_fo(int a, int b)
{
  int result = a+b;
  if(result<0)
    result+=4;
  return result%4;
}

bool calc_range(int x,int y)
{
  if(x>=0 && x<R && y>=0 && y<C)
    return true;
  return false;
}
void print_map()
{
  cout<<endl<<"printing::"<<endl;
  for(int i=0;i<R;i++)
    {
    for(int j=0;j<C;j++)
      {
        cout<<room[i][j]<<' ';
  
        
      }
      cout<<endl;
    }
  
  
}
bool ins()
{
  bool result = true;
  for(int i=0;i<R;i++)
    {
      for(int j=0;j<C;j++)
        {
          if(inspect[i][j] && room[i][j] < K)
            result = false;
          
        }
      
    }
  return result;
  
}
void wind_spread(int x, int y, int dir)
{
  int wind_strong = 5;
  vector<vector<bool>> visited(R,vector<bool>(C,false));
  visited[x][y] = true;
  int mov_x = x+dx[dir];
  int mov_y = y+dy[dir];
  queue<tuple<int,int,int>>q;
  if(calc_range(mov_x,mov_y))
  {
    visited[mov_x][mov_y] = true;
    q.push(make_tuple(mov_x,mov_y,wind_strong));
  }
  while(!q.empty())
    {
      int x = get<0>(q.front());
      int y = get<1>(q.front());
      int strong = get<2>(q.front());
      q.pop();
      room[x][y] += strong;
      for(int i=0;i<3;i++)
        {
          int mov_x = x+spread_dir[dir][i][0];
          int mov_y = y+spread_dir[dir][i][1];
          if(calc_range(mov_x,mov_y))
          {
            if(!visited[mov_x][mov_y] )
            {
              if((strong-1) > 0)
              {
                if(wall[(dir+2) %4][mov_x][mov_y])
                {


                }
                else
                {
                  if(i == 0)
                  {
                    int chk_dir = mod_fo(dir,-1);
                    int chk_x = x+dx[chk_dir];
                    int chk_y = y+dy[chk_dir];
                    if(!wall[(mod_fo(chk_dir,2))][chk_x][chk_y])
                    {
                      visited[mov_x][mov_y] = true;
                      q.push(make_tuple(mov_x,mov_y,strong-1));
                      
                    }
                  }
                  else if(i==2)
                  {
                    int chk_dir = mod_fo(dir,1);
                    int chk_x = x+dx[chk_dir];
                    int chk_y = y+dy[chk_dir];
                    if(!wall[mod_fo(chk_dir,2)][chk_x][chk_y])
                    {
                      visited[mov_x][mov_y] = true;
                      q.push(make_tuple(mov_x,mov_y,strong-1));
                    }
                    
                  }
                  else{

                      visited[mov_x][mov_y] = true;
                      q.push(make_tuple(mov_x,mov_y,strong-1));
                    }
              

                  
                }


                
              }
              

              
            }


            
          }


          
        }
      
    }
}
void stab_temp()
{
  vector<vector<int>>how_many(R,vector<int>(C,0));
  for(int i=0;i<R;i++)
    {
      for(int j=0;j<C;j++)
        {
          for(int d = 0;d<4;d++)
            {
              int mov_i = i+dx[d];
              int mov_j = j+dy[d];
              if(calc_range(mov_i,mov_j) && !wall[d][i][j])
              {
                if(room[i][j]>room[mov_i][mov_j])
                {
                  how_many[i][j] -= (room[i][j] - room[mov_i][mov_j])/4;
                  
                   how_many[mov_i][mov_j] += (room[i][j] - room[mov_i][mov_j])/4;
                }
                
              }


              
            }


          
        }


      
    }

  for(int i=0;i<R;i++)
    for(int j=0;j<C;j++)
      room[i][j] += how_many[i][j];
  
}
void operate()
{
  while(!ins() && chocolate<102)
    {
      //1
      for(int i=0;i<R;i++)
        {
          for(int j=0;j<C;j++)
            {
              if(device[i][j]>= 0 )
              {
                wind_spread(i,j,device[i][j]);
                 //print_map();
              }

              
            }

          
        }
      //print_map();
      //2
      stab_temp();
      //print_map();
      //3
      for(int i=0;i<C;i++)
        if(room[0][i] > 0)
          room[0][i]--;
      for(int i=0;i<C;i++)
        if(room[R-1][i] >0)
          room[R-1][i]--;
      for(int i=1;i<R-1;i++)
        {
          if(room[i][0] >0 )
            room[i][0]--;
          if(room[i][C-1]>0)
            room[i][C-1]--;
        }
      //print_map();
      chocolate++;
    }
}
int main() {
  int W;
  cin>>R>>C>>K;
  for(int i=0;i<R;i++)
    {
    for(int j=0;j<C;j++)
      {
        int tmp;
        cin>>tmp;
        if(tmp == 5)
          inspect[i][j] = true;
        else if(tmp == 1)
          device[i][j] = tmp;
        else if(tmp ==2)
          device[i][j] =3;
        else if(tmp ==3)
          device[i][j] = 0;
        else if(tmp == 4)
          device[i][j] = 2;
        
      }
    }
  cin>>W;
  for(int i=0;i<W;i++)
    {
      int a,b,c;
      cin>>a>>b>>c;
      a--;
      b--;
      if(c == 0)
      {
        //x,y - x-1,y
        wall[0][a][b] = true;
        wall[2][a-1][b] = true;
      }
      else
      {
        //x,y x,y+1
        wall[1][a][b] = true;
        wall[3][a][b+1] = true;
      }
    }
  operate();
  if(chocolate>100)
    chocolate = 101;
  cout<<chocolate<<endl;
}