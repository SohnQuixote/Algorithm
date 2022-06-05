#include <iostream>
#include <vector>
using namespace std;
/*
  로봇 청소기
  각각의 칸 -> 벽/빈칸
  로봇 청소기
  -> 현재 위치 청소
  -> 현재 위치 왼쪽 청소 빈칸 왼쪽 회전뒤 한칸 전진 청소로 돌아감
  빈칸 0
  벽 1  
  청소한칸 2
*/
int N,M;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int rotate_left(int a)
{
  a-=1;
  if(a<0)
    return a+4;
  else
    return a %4;
}
vector<vector<int>> map(50,vector<int>(50,0));
int clean(int x, int y, int d)
{
  while(true)
    {
      //현재 위치 청소
      map[x][y] = 2;
      //바라보고 있는 왼쪽 청소 안한 빈공간
      int rotating_time = 0;
      while(true)
        {
          d = rotate_left(d);
          rotating_time++;
          int moving_x = x+ dx[d];
          int moving_y = y+dy[d];
          if(map[moving_x][moving_y] == 0)
          {
            x = moving_x;
            y = moving_y;
            break;
            
          }
      if(rotating_time == 4)
      {
        int back_d = d;
        back_d = rotate_left(back_d);
        back_d = rotate_left(back_d);
        int moving_x = x+dx[back_d];
        int moving_y= y+dy[back_d];
        
        if(map[moving_x][moving_y] == 1)
        {
          return 0;
        }
        else
        {
          x = moving_x;
          y = moving_y;
          rotating_time = 0;
        }
          
        }
      }
      //그렇지 않을 경우
        
      
      

      
    }
  return 0;
}
int main() {
  int result = 0;
  
  int x,y,d;
  cin>>N>>M;
  cin>>x>>y>>d;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        {
          cin>>map[i][j];
        }
      
    }
  clean(x,y,d);
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++) 
        {
          //cout<<map[i][j]<<' ';
          if(map[i][j] == 2)
            result +=1;
        }
      //cout<<endl;
    }
    cout<<result<<endl;
  return 0;
}