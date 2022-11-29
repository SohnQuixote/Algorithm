#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
  도로 네트워크 위해서는 토대가 되는 문제부터 풀 필요가 존재
  LSA1
  LEVEL이 다를 때는 동시에 거슬러 올라가면 안됨
  최소 공통 조상 -> 트리 구조에서 임의의 두정점이 갖는 가장 가까운 조상 정점
  거슬러 올라가기 전에 두 정점의 깊이를 동일하게 맞춰야함
  노베이스로 짜기 어려우니까 일단 클론코딩으로 하기
  이해 완료
*/
int N;
int M;
vector<int> graph[100001];
int parent[100001],level[100001];


int lca(int a,int b)
{
  //재귀는 아님
  //a가 더 높게 맞추기
  if(level[a]<level[b]) swap(a,b);
  while(level[a] != level[b])
    {
      a = parent[a];
    }
    while(a!=b)
      {
        a= parent[a];
        b= parent[b];

        
      }
  //선형으로 그냥 계속 부모로 올라감
  return a;


  
}




void set_tree(int node,int pnode)
{
  //부모 하기
  parent[node] = pnode;
  level[node] = level[pnode]+1;
  //현재 부모보다 1내려와 있음
  for(int i=0;i<graph[node].size();i++)
    {
      //연결되어 있음 

      //양방향이기때문에 이미 부모로 설정 되어 있으면 pass필
      int child = graph[node][i];
      if(parent[node] == child)
        continue;
      set_tree(child,node);
      //재귀적으로 내려가기


      
    }


  
}


int main() {
  cin>>N;
  for(int i=0;i<N-1;i++)
    {
      int a,b;
      cin>>a>>b;
      graph[a].push_back(b);
      graph[b].push_back(a);
      
    }
  set_tree(1,0);
  cin>>M;
  for(int i=0;i<M;i++)
    {
      int a,b;
      cin>>a>>b;
      cout<<lca(a,b)<<'\n';
      
    }
}