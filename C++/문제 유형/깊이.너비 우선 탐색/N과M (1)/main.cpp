#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int>path;
int visited[9] = {0,};
void dfs(int now)
{
  if(now == m)
  {
    for(int i=0;i<path.size();i++)
      {
        printf("%d ",path[i]);
      }
    printf("\n");
    return;
  }
  for(int i=1;i<=n;i++)
    {
      if(!visited[i])
      {
        visited[i] = 1;
      path.push_back(i);
      dfs(now+1);
      path.pop_back();
        visited[i] = 0;
      }
    }
  
}
int main() {
  scanf("%d %d" , &n,&m);
  dfs(0);
}