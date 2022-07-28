#include <iostream>
#include <vector>
using namespace std;
/*
  네트워크 바이러스
*/
vector<int> graphs[101];//1~100
int visited[101] = {0,};
int n,m;
int cnt = 0;
void dfs(int now)
{
  for(int i=0;i<graphs[now].size();i++)
    {
      if(!visited[graphs[now][i]])
      {
        cnt++;
        visited[graphs[now][i]]=1;
        dfs(graphs[now][i]);
      }
      
    }

  
}
int main() {
  cin>>n>>m;
  for(int i=0;i<m;i++)
    {
      int a,b;
      cin>>a>>b;
      graphs[a].push_back(b);
      graphs[b].push_back(a);
    }
  visited[1] = 1;
  //cnt++;
  dfs(1);
  cout<<cnt;//1번 제거
}