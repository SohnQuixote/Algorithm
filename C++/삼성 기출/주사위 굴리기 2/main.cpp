#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
  주사위 굴리기 2 
  지도 N*M 
*/
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
//상우하좌

vector<vector<int>>map(20,vector<int>(20,0));
pair<int,int> pos = make_pair(0,0);


typedef struct dice
{
  int top = 1;
  int bottom = 6;
  int left = 4;
  int right = 3;
  int front = 5;
  int back = 2;
}dice;
dice chr;
int N,M;
bool calc_range(int x,int y)
{
  if(x>=0 && x<N && y>=0 && y<M)
    return true;
  return false;
}
void move_hor(int dir)
{
  int t,r,b,l;
  t = chr.top;
  r = chr.right;
  b = chr.bottom;
  l = chr.left;
  if(dir == 1)
  {//우
    chr.bottom = r;
    chr.right = t;
    chr.top =l;
    chr.left = b;
    
  }
  else if(dir == 3)
  {//좌
    chr.top = r;
    chr.right = b;
    chr.bottom = l;
    chr.left = t;
    
  }
  pos.first +=dx[dir];
  pos.second +=dy[dir];
}
void move_ver(int dir)
{
  int f = chr.front;
  int t = chr.top;
  int ba = chr.back;
  int bo = chr.bottom;
  if(dir==0)
  {
    //상
    chr.top = f;
    chr.back = t;
    chr.bottom = ba;
    chr.front = bo;
  }
  else if(dir == 2)
  {
    //하
    chr.top = ba;
    chr.front = t;
    chr.bottom = f;
    chr.back =bo;
  }
  pos.first +=dx[dir];
  pos.second+=dy[dir];
}
int chg_dir(int a, int dir)
{
  int result;
  if(a==0)
  {
    //시계 회전
    result = dir+1;
    result %= 4;
  }
  else if(a==1)
  {
    //반시계
    result = dir-1;
    if(result<0)
      result+=4;
    result %=4;
  }
  else
  {
    //이동 반전
    result = (dir+2) %4;
  }
  return result;
}
int scoring()
{
  int result = 1;
  vector<vector<bool>>visited(N,vector<bool>(M,false));
  int x = pos.first;
  int y = pos.second;
  int num = map[x][y];
  visited[x][y] = true;
  queue<pair<int,int>>q;
  q.push(make_pair(x,y));
  while(!q.empty())
    {
      pair<int,int>p = q.front();
      q.pop();
      x = p.first;
      y = p.second;
      for(int d=0;d<4;d++)
        {
          int mov_x = x+dx[d];
          int mov_y = y+dy[d];
          if(calc_range(mov_x,mov_y) && !visited[mov_x][mov_y] && map[mov_x][mov_y] == num)
          {
            result++;
            visited[mov_x][mov_y] = true;
            q.push(make_pair(mov_x,mov_y));
            
          }
          
        }

      
    }
  result *=num;
  return result;
}
int move(int K)
{
  int score = 0;
  int dir = 1;

  for(int i=0;i<K;i++)
    {
      int x = pos.first;
      int y = pos.second;
      
      int mov_x = x+dx[dir];
      int mov_y = y+dy[dir];
      if(!calc_range(mov_x,mov_y))
      {
        dir = chg_dir(2,dir);
      }
      if(dir%2 == 1)
        move_hor(dir);
      else
        move_ver(dir);
      score+=scoring();
      int cur_x = pos.first;
      int cur_y = pos.second;
      if(chr.bottom> map[cur_x][cur_y])
        dir = chg_dir(0,dir);
      else if(chr.bottom < map[cur_x][cur_y])
        dir = chg_dir(1,dir);
      //cout<<cur_x<<' '<<cur_y<<' '<<chr.bottom<<endl;
    }
  return score;
}
int main() {
  int K;
  cin>>N>>M>>K;
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      cin>>map[i][j];
  cout<<move(K)<<endl;
}