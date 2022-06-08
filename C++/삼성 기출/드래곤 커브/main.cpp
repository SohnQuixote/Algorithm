#include <iostream>
#include <vector>
using namespace std;
/*
  드래곤 커브
  x축 -> 
  y축 | 
  세가지 속성 -> 시작점, 시작 방향, 세대
  K세대 드래곤 커브 -> K-1 세대 끝점 기준 90도 시계방향 회전 -> 끝점에 붙이기
  K세대 드래곤 커브 만들기 -> 시계방향 회전
  격자 변 자료구조 필요
*/
vector<vector<int>>grid(101,vector<int>(101,0));
//드래곤 커브 점이 있으면 +1
//[y][x]
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
//점을 모두 grid에 추가
vector<pair<int,int>> draw_d_curve(vector<pair<int,int>>c)
{
  //끝점 시계방향 회전 후 엣지 덧붙여서 반환
  //새로 추가된 점 grid에 추가
  //현재 edges사이즈보다 1적은 점 추가
  //무조건 맨앞원소가 맨 뒤로 감
  int x_1,y_1,x_2,y_2,x_3,y_3,x_4,y_4;
  pair<int,int> gijoon = c.back();
  x_1 = gijoon.first;
  y_1 = gijoon.second;
  //cout<<x_1<<' '<<y_1<<endl;
  vector<pair<int,int>> tmp;
  for(int i=0;i<c.size()-1;i++)
    {
      x_2 = c[i].first;
      y_2 = c[i].second;
      x_3 = x_2 - x_1;
      y_3 = y_2 - y_1;
      x_4 = -y_3;
      y_4 = x_3;
      int f_x = x_4+x_1;
      int f_y = y_4+y_1;
      grid[f_y][f_x] = 1;
      tmp.push_back(make_pair(f_x,f_y));
    }
  for(int i=tmp.size()-1;i >=0;i--)
    {
      c.push_back(tmp[i]);
    }
  //c.push_back(tmp[0]);    
  return c;
}
void print_grid(int N)
{
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          cout<<grid[i][j]<<' ';
        }
      cout<<endl;
    }
}
void make_d_curve(int x, int y, int d, int g)
{
  vector<pair<int,int>>edges;
  int moving_x = x+dx[d];
  int moving_y =y+dy[d];
  grid[y][x] = 1;
  grid[moving_y][moving_x] = 1;
  edges.push_back(make_pair(x,y));
  edges.push_back(make_pair(moving_x,moving_y));
  for(int i=0;i<g;i++)
    {
    
      //cout<<endl<<"printing grid::"<<endl;
      //cout<<x<<' '<<y<<endl;
      
      edges = draw_d_curve(edges);
      //print_grid(7);
    }
}
int chk_rect()
{
  int result = 0;
  for(int i=0;i<100;i++)
    {
      for(int j=0;j<100;j++)
        {
          if(grid[i][j] && grid[i+1][j] && grid[i+1][j+1] && grid[i][j+1])
            result++;
          
        }
      
    }
  return result;
}
int main() {
  int N;
  cin>>N;
  for(int i=0;i<N;i++)
    {
      int x,y,d,g;
      cin>>x>>y>>d>>g;
      make_d_curve(x,y,d,g);
      
    }
  cout<<chk_rect()<<endl;
}