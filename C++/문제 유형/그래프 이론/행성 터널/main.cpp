#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
using namespace std;
/*
  행성 터널
  왕국 N개 행성
  행성 3차원 좌표위 한점
  거리- 차이 최솟값
  N-1개 터널 건설
  터널 연결 최소 비용
  최소 신장트리?(cost를 알고 있어야 함)
  N*N개 거리
  조합 사용해서 거리?
  모든 거리를 보는것은 별로임
  각 축에 따라 다르게 정렬한 후
  x축 거리
  y축 거리
  z축 거리 따로
  아예 조합으로하면 n*(n-1)/2가 됨
  굳이 먼곳을 볼 필요 가 없음
*/
int calc(int x,int y, int z, int a, int b, int c )
{
  return min(abs(x-a),min(abs(y-b),abs(z-c)));
}
int parents[100001] = {0,};

int find_p(int a)
{
  if(parents[a] !=a)
    parents[a] = find_p(parents[a]);
  return parents[a];
}
void union_p(int a,int b)
{
  a = find_p(a);
  b = find_p(b);
  if(b>a)
    parents[b] = a;
  else
    parents[a] = b;
}
bool chk_p(int N)
{
  int chk = parents[0];
  for(int i=1;i<N;i++)
    {
      if(parents[i] != chk)
        return false;
      
    }
  return true;
}
int main() {
  int N;
  cin>>N;
  vector<pair<int,int>> x_planets;
  vector<pair<int,int>> y_planets;
  vector<pair<int,int>> z_planets;
  vector<tuple<int,int,int>> dist_planets;//x,y,z 저장 
  for(int i=0;i<N;i++)
    {
      parents[i] = i;
      int x,y,z;
      cin>>x>>y>>z;
      //planets.push_back(make_tuple(x,y,z));
      x_planets.push_back(make_pair(x,i));
      y_planets.push_back(make_pair(y,i));
      z_planets.push_back(make_pair(z,i));
    }
  sort(x_planets.begin(),x_planets.end());
  sort(y_planets.begin(),y_planets.end());
  sort(z_planets.begin(),z_planets.end());
  for(int i=0;i<N-1;i++)
    {
      dist_planets.push_back(make_tuple(abs(x_planets[i+1].first - x_planets[i].first) , x_planets[i].second,x_planets[i+1].second));
      dist_planets.push_back(make_tuple(abs(y_planets[i+1].first - y_planets[i].first) , y_planets[i].second,y_planets[i+1].second));
      dist_planets.push_back(make_tuple(abs(z_planets[i+1].first - z_planets[i].first) , z_planets[i].second,z_planets[i+1].second));

      
    }
  sort(dist_planets.begin(),dist_planets.end());
  int result =0;
  for(int i=0;i<dist_planets.size();i++)
    {
      int c = get<0>(dist_planets[i]);
      int a = get<1>(dist_planets[i]);
      int b = get<2>(dist_planets[i]);
      if(find_p(a) != find_p(b))
      {
        union_p(a,b);
        result+=c;
        
      }
    }
  cout<<result<<endl;
}