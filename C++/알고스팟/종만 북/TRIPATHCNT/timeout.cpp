#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
#include <queue>
#include <string>
#include <map>
using namespace std;
/*
  TRIPATHCNT
  최대 경로의 수를 세는 프로그램
  맨 밑에 존재
*/
int C;
int n;
int arr[100][100];
int dx[2] = {1,1};
int dy[2] = {0,1};
int dat [100][100];
map<string,int> data;
int result = 0;
bool calc_range(int x,int y)
{
  if(x>=0 && x<n && y>=0 && y<n)
    return true;
  return false;
}
void find(int x, int y)
{
  if (result<= dat[x][y])
  {
    result = dat[x][y];
    data[to_string(dat[x][y])] +=1;
  }
  for(int d=0;d<2;d++)
    {
      int mov_x = x+dx[d];
      int mov_y = y+dy[d];
      if(calc_range(mov_x,mov_y))
      {
        int moving = dat[x][y] + arr[mov_x][mov_y];
        if(moving>= dat[mov_x][mov_y])
        {
          dat[mov_x][mov_y] = moving;
          find(mov_x,mov_y);
          
        }


        
      }



      
    }
  


  
}
int main() {
  cin>>C;
  for(int tc=0;tc<C;tc++)
    {
      cin>>n;
      memset(dat,0,sizeof(dat));
      result = 0;
      for(int i=0;i<n;i++)
        for(int c=0;c<i+1;c++)
          cin>>arr[i][c];
      dat[0][0] = arr[0][0];
      find(0,0);
      //cout<<result<<'\n';
      cout<<data[to_string(result)]<<'\n';
    }
}