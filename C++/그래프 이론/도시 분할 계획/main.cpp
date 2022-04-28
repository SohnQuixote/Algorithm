#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
/*
  도시 분할 계획
  마을 N개 집 M개 길
  사이클 찾기 위해 서로소 집합
  마을 두개로 하면서 최소 유지비
  최소신장트리 만들고 가장 큰 가중치 지우면 됨
*/
const int MAX = 100001;
vector<tuple<int,int,int>>graphs;
vector<int>results;
int cycles[MAX] = {0,};
int find_v(int a)
{
  if(a != cycles[a])
    cycles[a] = find_v(cycles[a]);
  return cycles[a];
}
void union_v(int a,int b)
{
  a = find_v(a);
  b = find_v(b);
  if(a<b)
    cycles[b] = a;
  else
    cycles[a] = b;
}
int calc(int N,int M)
{
  int result =0;
  for(int i=0;i<graphs.size();i++)
    {
      int cost,a,b;
      cost = get<0>(graphs[i]);
      a = get<1>(graphs[i]);
      b = get<2>(graphs[i]);
      if(find_v(a) != find_v(b))
      {
        union_v(a,b);
        result+= cost;
        results.push_back(cost);
      }
    }
  return (result-*max_element(results.begin(),results.end()));
}
int main() {
  int N,M;
  cin>>N>>M;
  for(int i=1;i<N+1;i++)
    cycles[i] = i;
  for(int i=0;i<M;i++)
    {
      int cost,a,b;
      cin>>a>>b>>cost;
      graphs.push_back(make_tuple(cost,a,b));
    }
  sort(graphs.begin(),graphs.end());
  cout<<calc(N,M)<<endl;
}