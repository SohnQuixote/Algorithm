#include <iostream>
#include <vector>
using namespace std;
int n,m;
vector<int>path;
int visited[9] = {0,};
void dfs(int now , int depth)
{
  if(now == m)
  {
    for(int i=0;i<path.size();i++)
      {
        printf("%d ", path[i]);
      }
    printf("\n");
    return;
  }
  else if (depth == n+1)
  {
    return;
  }
  else{
    for(int i=depth;i<=n;i++)
      {
        if(!visited[i])
        {
          path.push_back(i);
          visited[i] =1;
          dfs(now+1,i+1);
          visited[i] = 0;
          path.pop_back();
          
        }
        //dfs(now,i+1);
      }

    
  }
  //nCm -> n-1Cm-a + n-1Cm  
  
}
int main() {
  scanf("%d %d" , &n,&m);
  dfs(0,1);
}