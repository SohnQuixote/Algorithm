#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
  상근이의 여행
  간단한 BFS로 보임
  그냥 모두 들렀을 때 BFS 값 반환
*/
int n,m;
int BFS(vector<int> g[])
{
  //모든 출발지?
  int min_result = 987654321;
  for(int i=1;i<=n;i++)
    {
      int visited[1001] = {0,};
      int dist[1001] = {0,};
      visited[i] = 1;
      dist[i] = 1;
      queue<int>q;
      q.push(i);
      int tmp = 0;
      //cout<<"start:"<<i<<endl;
      while(!q.empty())
        {
          int now = q.front();
          //cout<<"path:"<<now<<endl;
          q.pop();
          for(int j=0;j<g[now].size();j++)
            {
              int next= g[now][j];
              if(!visited[next])
              {
                visited[next] = 1;
                q.push(next);
                dist[next] = dist[now]+1;
                tmp+=1; //이동한 간선마다 더하기
                
              }

              
            }



          
        }



      min_result = min(min_result,tmp);



      
    }



  return min_result;
}


int main() {
  int t;
  cin>>t;
  for(int i=0;i<t;i++)
    {
      cin>>n>>m;
      vector<int> graphs[1001];
      for(int i=0;i<m;i++)
        {
          int a,b;
          cin>>a>>b;
          graphs[a].push_back(b);
          graphs[b].push_back(a);
        }
        cout<<BFS(graphs)<<'\n';
      
    }
}