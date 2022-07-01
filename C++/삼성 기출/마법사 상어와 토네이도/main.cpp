#include <iostream>
#include <vector>
using namespace std;
/*
  마법사 상어와 토네이도
  가운데 칸 토네이도 이동 시작
  한번에 한칸
  중심점 - (N/2) , (N/2)
  스텝 -> 홀수 ->
  1. 해당 위치에서 (0,-1) * 스텝 만큼
  2. 한 위치에서 (1,0) * 스텝 만큼
  스텝 짝수 ->
  1. 현재 위치에서 (0,1) * 스텝 수
  2. 한 위치에서 ()
*/
int spreaded = 0;
int N;
vector<vector<int>>map(500,vector<int>(500,0));
bool calc_range(int a,int b)
{
  if(a>=0 && a<N && b>=0 && b<N)
    return true;
  return false;
}
void print_map(int a,int b)
{
  cout<<"printing::"<<a<<' '<<b<<endl;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          cout<<map[i][j]<<' ';
        }
        cout<<endl;
      
    }
  cout<<spreaded<<endl;
}
void dust_spread(double r, int &full, int x, int y,double origin)
{
  //cout<<x<<' '<<y<<endl;
  if(calc_range(x,y))
  {
    map[x][y] += static_cast<int>(origin*r);
  }
  else{
    spreaded+= static_cast<int>(origin*r);
  }
  full-= static_cast<int>(origin*r);
}
void spread_left(int &x,int &y)
{
  //토네이도 위치 (x,y)
  //움직이는 먼지 위치 (x,y-1)
  int full = map[x][y-1];
  const double origin = map[x][y-1];
  int mov_x,mov_y;
  double ratio;
  for(int d = -2;d<=2;d++)
    {
      mov_x = x+d;
      if(d==-2|| d==2)
      {
        mov_y = y-1;
       ratio = 0.02; dust_spread(ratio,full,mov_x,mov_y,origin);
        
      }
      else if(d==-1 || d==1)
      {
        for(int d_y = -2;d_y<=0;d_y++)
          {
            mov_y = y+d_y;
            if(d_y == -2 )
            {
              ratio = 0.1;
              
            }
            else if(d_y ==-1)
            {
              ratio = 0.07;
            }
            else if(d_y ==0)
            {
              ratio = 0.01;
            }
            dust_spread(ratio,full,mov_x,mov_y,origin);
          }
        
      }
      else if(d ==0)
      {
        mov_x =x;
        mov_y= y-3;
        ratio = 0.05;
        dust_spread(ratio,full,mov_x,mov_y,origin);
        
      }
      
    }
  mov_x = x;
  mov_y = y-2;
  if(calc_range(mov_x,mov_y))
    map[mov_x][mov_y] += full;
  else
    spreaded+=full;
  y--;
  map[x][y] = 0;
}
void spread_right(int &x,int &y)
{
  //토네이도 위치 (x,y)
  //움직이는 먼지 위치 (x,y-1)
  int full = map[x][y+1];
  const int origin = map[x][y+1];
  int mov_x,mov_y;
  double ratio;
  for(int d = -2;d<=2;d++)
    {
      mov_x = x+d;
      if(d==-2|| d==2)
      {
        mov_y = y+1;
       ratio = 0.02; 
        dust_spread(ratio,full,mov_x,mov_y,origin);
        
      }
      else if(d==-1 || d==1)
      {
        for(int d_y = 0;d_y<=2;d_y++)
          {
            mov_y = y+d_y;
            if(d_y == 0 )
            {
              ratio = 0.01;
              
            }
            else if(d_y ==1)
            {
              ratio = 0.07;
            }
            else if(d_y ==2)
            {
              ratio = 0.1;
            }
            dust_spread(ratio,full,mov_x,mov_y,origin);
          }
        
      }
      else if(d ==0)
      {
        mov_x =x;
        mov_y= y+3;
        ratio = 0.05;
        dust_spread(ratio,full,mov_x,mov_y,origin);
        
      }
      
    }
  mov_x = x;
  mov_y = y+2;
  if(calc_range(mov_x,mov_y))
    map[mov_x][mov_y] += full;
  else
    spreaded+=full;
  y++;
  map[x][y] = 0;
}
void spread_up(int &x,int &y)
{
  //토네이도 위치 (x,y)
  //움직이는 먼지 위치 (x,y-1)
  int full = map[x-1][y];
  const int origin = map[x-1][y];
  int mov_x,mov_y;
  double ratio;
  for(int d = -2;d<=2;d++)
    {
      mov_y = y+d;
      if(d==-2|| d==2)
      {
        mov_x = x-1;
        ratio = 0.02; 
        dust_spread(ratio,full,mov_x,mov_y,origin);
        
      }
      else if(d==-1 || d==1)
      {
        for(int d_x = -2;d_x<=0;d_x++)
          {
            mov_x = x+d_x;
            if(d_x == -2 )
            {
              ratio = 0.1;
              
            }
            else if(d_x ==-1)
            {
              ratio = 0.07;
            }
            else if(d_x ==0)
            {
              ratio = 0.01;
            }
            dust_spread(ratio,full,mov_x,mov_y,origin);
          }
        
      }
      else if(d ==0)
      {
        mov_x = x-3;
        mov_y =y;
        ratio = 0.05;
        dust_spread(ratio,full,mov_x,mov_y,origin);
        
      }
      
    }
  mov_x= x-2;
  mov_y =y;
  if(calc_range(mov_x,mov_y))
    map[mov_x][mov_y] += full;
  else
    spreaded+=full;
  x--;
  map[x][y] = 0;
}
void spread_down(int &x,int &y)
{
  //토네이도 위치 (x,y)
  //움직이는 먼지 위치 (x,y-1)
  int full = map[x+1][y];
  const int origin = map[x+1][y];
  int mov_x,mov_y;
  double ratio;
  for(int d = -2;d<=2;d++)
    {
      mov_y = y+d;
      if(d==-2|| d==2)
      {
        mov_x = x+1;
        ratio = 0.02; 
        dust_spread(ratio,full,mov_x,mov_y,origin);
        
      }
      else if(d==-1 || d==1)
      {
        for(int d_x = 0;d_x<=2;d_x++)
          {
            mov_x = x+d_x;
            if(d_x == 0 )
            {
              ratio = 0.01;
              
            }
            else if(d_x ==1)
            {
              ratio = 0.07;
            }
            else if(d_x ==2)
            {
              ratio = 0.1;
            }
            dust_spread(ratio,full,mov_x,mov_y,origin);
          }
        
      }
      else if(d ==0)
      {
        mov_x = x+3;
        mov_y = y;
        ratio = 0.05;
        dust_spread(ratio,full,mov_x,mov_y,origin);
        
      }
      
    }
  mov_x= x+2;
  mov_y =y;
  if(calc_range(mov_x,mov_y))
    map[mov_x][mov_y] += full;
  else
    spreaded+=full;
  x++;
  map[x][y] = 0;
}
void tornado(int x, int y)
{
  int steps = 1;
  while(x!=0 || y!=0)
    {
      if(steps%2 == 1)
      {
        for(int i=0;i<steps;i++)
          {
            spread_left(x,y);
            //print_map(x,y);
          if(x==0 && y==0)
            return;
          }
        for(int i=0;i<steps;i++)
          {
            spread_down(x,y);
            //print_map(x,y);
          if(x==0 && y==0)
            return;
          }
      }
      else
      {
        for(int i=0;i<steps;i++)
          {
            spread_right(x,y);
            //print_map(x,y);
          if(x==0 && y==0)
            return;
          }
        for(int i=0;i<steps;i++)
          {
            spread_up(x,y);
            //print_map(x,y);
          if(x==0 && y==0)
            return;
          }
        
      }
      steps++;
      
    }
  return;
}
int main() {
  cin>>N;
  for(int i=0;i<N;i++)
      for(int j=0;j<N;j++)
        cin>>map[i][j];
  int x = N/2;
  int y = N/2;
  tornado(x,y);
  cout<<spreaded<<endl;
}