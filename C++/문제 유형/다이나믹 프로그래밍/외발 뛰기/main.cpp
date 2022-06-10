#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
  JUMPGAME
  0,0 -> (n-1,n-1)
  각 칸에 적혀있는 숫자만큼 아래나 우측 이동 가능
  완전탐색 구현
  부분문제 한번만 계산 하도록 메모이제이션 적용
*/
int N;
const int MAX = 50;
vector<vector<int>>map(MAX,vector<int>(MAX,0));
vector<vector<int>> cache(MAX,vector<int>(MAX,-1));
bool jmp(int y, int x)
{
  if(y>=N || x>=N)
    return false;
  if(y== N-1 && x== N-1)
    return true;
  int jmp_size = map[y][x];
  return jmp(y+jmp_size,x) || jmp(x+jmp_size,y);
  //완전 탐색 코드
}
int jmp_2(int y, int x)
{
  
  if(y>=N || x>=N)
    return 0;
  if(y== N-1 && x== N-1)
    return 1;
  int &ret = map[y][x];
  if(ret != -1)
    return ret;
  int jmp_size = map[y][x];
  return ret =  (jmp_2(y+jmp_size,x) || jmp_2(x+jmp_size,y));
}
bool calc_range(int a)
{
  if(a>N)
    return false;
  return true;
}
bool calc_possible(int N)
{
  bool result = false;
  queue<pair<int,int>> q;
  q.push(make_pair(0,0));
  //bfs
  while(!q.empty())
    {
      pair<int,int> pos = q.front();
      q.pop();
      int y = pos.first;
      int x = pos.second;
      if(x==N-1 && y== N-1)
        return true;
      int jmp_size = map[y][x];
      int mov_y = y+jmp_size;
      int mov_x = x+jmp_size;
      if(calc_range(mov_y))
      {
        q.push(make_pair(mov_y,x));
        
      }
      if(calc_range(mov_x))
      {
        q.push(make_pair(y,mov_x));      
      }
    }
  return result;  
}
int main() {
  //int N;
  cin>>N;
  for(int r= 0;r<N;r++)
    {
    for(int c=0;c<N;c++)
      {
        cin>>map[r][c];
      }
    }
}