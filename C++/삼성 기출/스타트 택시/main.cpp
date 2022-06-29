#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
/*
  스타트 택시
  최단 경로 구하는 알고리즘 필요
  (x,y) - (n,m)까지 바로 알 수 있어야함
  모든 승객 성공적으로 데려다 줄 수 있는 지 여부 + 남는 연료의양 
  4차원 배열 사용 
  완전 탐색을하면서 작을 때만 가기 -> 가는 양 -> 해당 좌표를 서로 뺀 값의 절댓값
  매번 경로 구하면 시간초과 예상
  모든 경로 최대 16만번
  값이 같을 경우 -> (0,0)에서 출발이라서 일단 도달 가능 -> 행-열 빼기 해서 경로거리 구하기
  벽으로 둘러쌓인곳에서 이동할 경우 
*/
int N,M;
const int MAX = 20;
const int INF = 987654321;
vector<tuple<int,int,int,int>> customers;
vector<vector<vector<vector<int>>>>route(MAX,vector<vector<vector<int>>>(MAX,vector<vector<int>>(MAX,vector<int>(MAX,INF))));
vector<vector<int>> map(MAX,vector<int>(MAX,1));
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void print_route(int x,int y)
{
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          if(route[x][y][i][j] == INF)
            cout<<-1<<' ';
          else
            cout<<route[x][y][i][j]<<' ';
        }
      cout<<endl;
      
    }
  
}
bool calc_range(int a)
{
  if(a>=0 && a<N)
    return  true;
  return false;
}
bool cmp(tuple<int,int,int,int> a, tuple<int,int,int,int> b)
{
  int a_x,a_y;
  int b_x,b_y;
  a_x = get<0>(a);
  a_y = get<1>(a);
  b_x = get<0>(b);
  b_y = get<1>(b);
  if(a_x<b_x)
  {
    return true;
  }
  if(a_x == b_x)
  {
    if(a_y<b_y)
      return true;
    else 
      return false;
  }
  else
  {
    return false;
  }
}
void calc_route(int f_x,int f_y)
{
  //시작점
  queue<pair<int,int>>q;
  q.push(make_pair(f_x,f_y));
  route[f_x][f_y][f_x][f_y] = 0;
  while(!q.empty())
    {
      pair<int,int> pos = q.front();
      q.pop();
      int x = pos.first;
      int y = pos.second;
      for(int i=0;i<4;i++)
        {
          int mov_x = x+dx[i];
          int mov_y = y+dy[i];
          if(calc_range(mov_x) && calc_range(mov_y) && map[mov_x][mov_y] != 1)
          {
            //범위 안에 있고 벽이 아닐 때
            if(route[f_x][f_y][mov_x][mov_y] > route[f_x][f_y][x][y] +1)
            {
              route[f_x][f_y][mov_x][mov_y] = route[f_x][f_y][x][y] +1;
              q.push(make_pair(mov_x,mov_y));
            }            
          }
          
        }

      
    }
  // x,y - n,m 경로 -> |route[x][y] - route[n][m]|
  
}
int move(int x, int y, int fuel)
{
  int result = -1;
  
  vector<bool>visit(M,false);
  int taken = 0;

  int moving_mem;
  while(fuel >0 && taken != M)
    {
      //cout<<x<<' '<<y<<endl;
      int c_x, c_y;
      int d_x,d_y;
      //cout<<customers.size()<<endl;
      vector<int>dist(customers.size(),INF);
    for(int i=0;i<customers.size();i++)
    {
      c_x = get<0>(customers[i]);
      c_y = get<1>(customers[i]);
      dist[i] = route[x][y][c_x][c_y];
      //cout<<c_x<<' '<<c_y<<' '<<route[c_x][c_y]<<endl;
    }
      moving_mem = -1;
      int moving_dist = INF;
      for(int i=0;i<customers.size();i++)
        {
          //cout<<dist[i]<<' '<<endl;
          if(moving_dist>dist[i])
          {
            moving_mem = i;
            moving_dist = dist[i];
          }
        }
      //cout<<moving_dist<<endl;
      fuel -= moving_dist;
      if(fuel<=0|| moving_dist== INF)
      {
        result = -1;
        break;
      }
      c_x = get<0>(customers[moving_mem]);
      c_y = get<1>(customers[moving_mem]);
      d_x = get<2>(customers[moving_mem]);
      d_y = get<3>(customers[moving_mem]);
      int taking_dist = route[c_x][c_y][d_x][d_y];
      fuel -= taking_dist;
      //cout<<endl<<x<<' '<<y<<' '<<c_x<<' '<<c_y<<' '<<moving_dist<<' '<<taking_dist<<endl;
      if(fuel<0 || taking_dist == INF)
      {
        result = -1;
        break;
      }
      fuel+= 2*taking_dist;
      x = d_x;
      y = d_y;
      taken++;
      customers.erase(customers.begin()+moving_mem);
      visit[moving_mem] = true;
      
      result = fuel;
    }
  //cout<<"printing::"<<result<<endl;
  return result;
}
int main() {
  int fuel = 0;
  int x,y;
  cin>>N>>M>>fuel;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      cin>>map[i][j];
  cin>>x>>y;
  x--;
  y--;
  calc_route(x,y);
  bool can_go = true;
  for(int i=0;i<M;i++)
    {
      int a,b,c,d;
      
      cin>>a>>b>>c>>d;
      a--;
      b--;
      c--;
      d--;
      customers.push_back(make_tuple(a,b,c,d));      
    }
    sort(customers.begin(),customers.end(),cmp);
    
    vector<vector<bool>> visit(N,vector<bool>(N,false));
    for(int i=0;i<M;i++)
      {
        int s_x,s_y,d_x,d_y;
        s_x = get<0>(customers[i]);
        s_y = get<1>(customers[i]);
        d_x = get<2>(customers[i]);
        d_y = get<3>(customers[i]);
        if(!visit[s_x][s_y])
        {
          calc_route(s_x,s_y);
          visit[s_x][s_y] = true;
          
        }
        if(!visit[d_x][d_y])
        {
          calc_route(d_x,d_y);
          visit[d_x][d_y] = true;
        }
      }
    //print_route(2,4);
   cout<<move(x,y,fuel)<<endl;
}