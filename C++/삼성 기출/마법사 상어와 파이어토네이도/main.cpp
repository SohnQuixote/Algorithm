#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;
/*
  마법사 상어와 파이어스톰
  2^N 격자 - 2^L로 각자 시계방향 90도 회전후 얼음이 1줄어듬
  줄어드는 조건 -> (r,c) - 상하좌우 얼음 2개이하
  0행이 끝열로
*/
vector<vector<int>>map(64,vector<int>(64,0));
int N,Q;
int map_size = 0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int big_ice = 0;

bool calc_range(int a, int b)
{
  if(a>=0 && a<map_size && b>=0 && b<map_size)
    return true;
  return false;
}
void print_map()
{
  cout<<endl<<"printing::"<<endl;
  for(int i=0;i<map_size;i++)
    {
      for(int j=0;j<map_size;j++)
        {
          cout<<map[i][j]<<' ';
        }
      cout<<endl;
    }
  
}
void spin(int x,int y, int size)
{
  vector<vector<int>> tmp(size,vector<int>(size,0));
  for(int i=x;i<x+size;i++)
    {
      for(int j = y;j<y+size;j++)
        {
          tmp[i-x][j-y] = map[i][j];
        }
    }
  for(int i=0;i<size;i++)
    {
      for(int j=0;j<size;j++)
        {
          map[x+j][y+size-1-i] = tmp[i][j];
        
        }
      
    }
  //임시 저장후 0행부터 순차적으로 끝열에 대입
  
}
bool melt(int x, int y)
{
  int iced = 0;
  for(int d=0;d<4;d++)
    {
      int chk_x = x+dx[d];
      int chk_y = y+dy[d];
      if(calc_range(chk_x,chk_y))
      {
        if(map[chk_x][chk_y] !=0)
          iced++;
      }
    }
  if(iced<=2)
    return true;
  return false;
}
void cast(int a)
{
  //회전 먼저
  int size = pow(2,a);
  //전체 회전
  for(int i=0;i<map_size;i+=size)
    {
      for(int j=0;j<map_size;j+=size)
        {
          //cout<<i<<' '<<j<<endl;
          if(size>1)
            spin(i,j,size);
        }
    }
  //녹음
  vector<vector<bool>>melt_flag(map_size,vector<bool>(map_size,false));
  for(int i=0;i<map_size;i++)
    {
      for(int j=0;j<map_size;j++)
        {
          if(map[i][j] >0)
          {
             melt_flag[i][j] = melt(i,j);
          }
        }
    }
  for(int i=0;i<map_size;i++)
    {
      for(int j=0;j<map_size;j++)
        {
          if(melt_flag[i][j])
          {
            map[i][j]--;
          }
        }
      
    }
}
int calc_ice()
{
  int result =0;
  for(int i=0;i<map_size;i++)
    for(int j=0;j<map_size;j++)
      result+=map[i][j];
  return result;
}
int dfs(int x, int y, vector<vector<bool>> & chk)
{
  queue<pair<int,int>>q;
  int result = 1;
  q.push(make_pair(x,y));
  chk[x][y] = true;
  while(!q.empty())
    {
      pair<int,int> pos = q.front();
      q.pop();
      //result++;
      int x = pos.first;
      int y = pos.second;
      //chk[x][y] = true;
      
      for(int d = 0;d<4;d++)
        {
          int mov_x = x+dx[d];
          int mov_y = y+dy[d];
          if(calc_range(mov_x,mov_y) && !chk[mov_x][mov_y] && map[mov_x][mov_y] != 0)
          {
            q.push(make_pair(mov_x,mov_y));
            chk[mov_x][mov_y] = true;
            result++;
          }
          
        }
      
    }
    return result;
}
void calc_big()
{ vector<vector<bool>>chk(map_size,vector<bool>(map_size,false));
  for(int i=0;i<map_size;i++)
    {
      for(int j=0;j<map_size;j++)
        {
          if(chk[i][j] == false && map[i][j] != 0)
          {
            big_ice = max(big_ice,dfs(i,j,chk));
          }
          
        }

      
    }
}
int main() {
    cin>>N>>Q;
    map_size = pow(2,N);
    for(int i=0;i<pow(2,N);i++)
      {
        for(int j=0;j<pow(2,N);j++)
          {
            cin>>map[i][j];
          }
      }
    for(int i=0;i<Q;i++)
      {
        int tmp;
        cin>>tmp;
        cast(tmp);
        //print_map();
      }
  cout<<calc_ice()<<endl;
  calc_big();
  cout<<big_ice<<endl;
    
}