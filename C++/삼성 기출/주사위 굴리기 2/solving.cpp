#include <iostream>
#include <vector>
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
void move_hor(int dir)
{
  int t,r,b,l;
  t = chr.top;
  r = chr.right;
  b = chr.bottom;
  l = chr.left;
  if(dir == 1)
  {
    
  }
  if(dir == 3)
  {
    
  }
}
int main() {
  int K;
  cin>>N>>M>>K;
  for(int i=0;i<N;i++)
    for(int j=0;j<M;j++)
      cin>>map[i][j];
}