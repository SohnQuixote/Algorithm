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
    bool chk = true;
    if(m>=2)
    {
    for(int i=0;i<path.size()-1;i++)
      {
        if(path[i] > path[i+1])
          chk = false;
      }
    }
    if(!chk)
      return;
    for(int i=0;i<path.size();i++)
      printf("%d ",path[i]);
    printf("\n");
    return;
  }
  for(int i=1;i<=n;i++)
    {
      path.push_back(i);
      dfs(now+1);
      path.pop_back();
    }
  
  
}
int main() {
  scanf("%d %d" , &n,&m);
  dfs(0);
}