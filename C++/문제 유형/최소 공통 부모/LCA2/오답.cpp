#include <iostream>
#include <vector>
using namespace std;
/*
  LCA2 
  N과 M의 범위가 많이 큼
  자신의 부모를 갖고있는 배열 parents
  루트는 무조건 1
  두개의 공통 부모를 찾는 find_same
  트리구조를 만드는 make(child,parent)
  연결 정보를 나타내는 vector<int>graph[MAX_INF]
  선행 시간이면 많이 길수 있나?
  기억을 되새기며 구현해보기
  level이 필요하다
  parent를 2차원으로 두기
  parent[x][k] = x번 정점의 2^k번째 조상 노드의 번호

*/
int N,M;
const int MAX_INF = 100001;
int parents[MAX_INF][20] = {0,};
int levels[MAX_INF] = {0,};
vector<int>graph[MAX_INF];
int max_lvl = 16;//10000개 트리의 최대 높이
int find_parent(int a, int b)
{
  if(a==1 || b==1) return 1;
  if(levels[a]<levels[b])
    swap(a,b);
    if(levels[a] != levels[b])
    {
      for(int i=max_lvl;i>=0;i--)
        {
          if(levels[parents[a][i]] >= levels[b])
            a = parents[a][i];
        }  
    }
    if(a!=b)
    {
      for(int i=max_lvl;i>=0;i--)
        {
          if(parents[a][i] !=parents[b][i])
          {
            a = parents[a][i];
            b = parents[b][i];
          }
        }
    }
  return a;

  
}


//잘 됨
void make_parent(int child,int parent)
{
  if(parent !=0)
  {
    parents[child][0] = parent;
    levels[child] = levels[parent] +1;  
  }
  for(int i=1;i<=max_lvl;i++)
    {
      parents[child][i] = parents[parents[child][i-1]][i-1];
    }
  for(int i=0;i<graph[child].size();i++)
    {
      
      if(parents[graph[child][i]][0]) continue;
      make_parent(graph[child][i],child);
      
    }
}







int main() {
  cin>>N;
  for(int i=0;i<N-1;i++)
    {
      int p,c;
      cin>>p>>c;
      graph[p].push_back(c);
      graph[c].push_back(p);



      
    }
  for(int i=max_lvl;i>=0;i--)
    parents[1][i] = 1;
  make_parent(1,0);
  cin>>M;
  for(int i=0;i<M;i++)
    {
      int a,b;
      cin>>a>>b;
      cout<<find_parent(a,b)<<'\n';


      
    }
}