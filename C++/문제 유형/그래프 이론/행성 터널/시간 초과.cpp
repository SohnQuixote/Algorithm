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
int main() {
  int N;
  cin>>N;
  vector<tuple<int,int,int>> planets;
  vector<tuple<int,int,int>> dist_planets;
  vector<int> comb;
  for(int i=0;i<N;i++)
    {
      comb.push_back(0);
      parents[i] = i;
    }
  comb[0] = 1;
  comb[1] = 1;
  sort(comb.begin(),comb.end());
  //x,y,z 저장 
  for(int i=0;i<N;i++)
    {
      int x,y,z;
      cin>>x>>y>>z;
      planets.push_back(make_tuple(x,y,z));
      
      
    }
  
  do{
    vector<int> tmp_idx;
    tmp_idx.clear();
    for(int i=0;i<N;i++)
      {
        if(comb[i] == 1)
          tmp_idx.push_back(i);
        
      }
      int first = tmp_idx[0];
      int second = tmp_idx[1];
      int x = get<0>(planets[first]);
      int y = get<1>(planets[first]);
      int z = get<2>(planets[first]);
      int a = get<0>(planets[second]);
      int b = get<1>(planets[second]);
      int c = get<2>(planets[second]);
      int dist = calc(x,y,z,a,b,c);
      dist_planets.push_back(make_tuple(dist,first,second));
  }while(next_permutation(comb.begin(),comb.end()));
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