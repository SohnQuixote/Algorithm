#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;
const int MAX = 101;
int parents[MAX] = {0,};
int degree[MAX] = {0,};
vector<int> graph[MAX];
//최소 신장 트리 - 크루스칼 알고리즘
int find_parent(int child)
{
  if(parents[child] != child)
    parents[child] = find_parent(parents[child]);
  return parents[child];
}
void union_parent(int child_a, int child_b)
{
  int parent_a = find_parent(child_a);
  int parent_b = find_parent(child_b);
  //cout<<parent_a<<' '<<parent_b<<endl;
  if(parent_a < parent_b)
  {
    parents[parent_b] = parent_a;
  }
  else
  {
    parents[parent_a] = parent_b;
  }
}
//위상 정렬
void topology_sort(int V)
{
  vector<int>results;
  queue<int> q;
  for(int i=1;i<V+1;i++)
    {
      //cout<<degree[i]<<' ';
      if(degree[i] ==0)
        q.push(i);
    }
    cout<<endl;
    while(!q.empty())
      {
        int now = q.front();
        q.pop();
        results.push_back(now);
        for(int i=0;i<graph[now].size();i++)
          {
            degree[graph[now][i]]--;
            if(degree[graph[now][i]] == 0 )
              q.push(graph[now][i]);
          }
      }
  for(int i=0;i<results.size();i++)
    cout<<results[i]<<' ';
  cout<<endl;
}
int main() {
  int V,E;
  vector<tuple<int,int,int>>array;
  cin>>V>>E;
  for(int i=1;i<V+1;i++)
    {parents[i] = i; degree[i] = 0;}
  for(int i=0;i<E;i++)
    {
      /*int a,b,cost;
      cin>>a>>b>>cost;
      array.push_back(make_tuple(cost,a,b));*/
      int a,b;
      cin>>a>>b;
      graph[a].push_back(b);
      degree[b]+=1;
    }
  topology_sort(V);
  return 0 ;
  sort(array.begin(),array.end());
  int result = 0;
  for(int i=0;i<array.size();i++)
    {
      int cost,a,b;
      cost = get<0>(array[i]);
      a = get<1>(array[i]);
      b = get<2>(array[i]);
      //cout<<cost<<' '<<a<<' '<<b<<endl;
      if(find_parent(a) != find_parent(b))
      {
        union_parent(a,b);
        result+=cost;
      }
    }
  cout<<result<<endl;
}