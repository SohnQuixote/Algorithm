#include <iostream>
#include <vector>
using namespace std;
/*
  도로 네트워크
  N개 도시 N-1개 도로
  도시 연결 유일 경로
  플로이드 워셜 사용해서 긴경로 짧은 경로 두개 다 저장
  K개 경로
*/
const int MAX = 101;
const int INF = 987654;
int roads[MAX][MAX];
int gin_roads[MAX][MAX];
int calc(int N)
{
  for(int i=1;i<N+1;i++)
    {
    for(int j=1;j<N+1;j++)
      {
      for(int k=1;k<N+1;k++)
        {
          roads[i][j] = min(roads[i][j] , roads[i][k] + roads[k][j]);

          gin_roads[i][j] = max(gin_roads[i][j] , gin_roads[i][k] + gin_roads[k][j]);
        }
      
        
      }
    }
  return 0;
}
int main() {
  int N,K;
  cin>>N;
  vector<pair<int,int>> results;
  for(int i=1;i<N+1;i++)
    {
      for(int j=1;j<N+1;j++)
        {
          if(i==j)
          {
            roads[i][j] = 0;
            gin_roads[i][j] = 0;
          }
          if(i!=j)
          {
          roads[i][j] = INF;
          //roads[j][i] = INF;
          gin_roads[i][j] = -INF;
          //gin_roads[j][i] = -INF;
          }
        }
      
    }
  for(int i=0;i<N-1;i++)
    {
      int a,b,c;
      cin>>a>>b>>c;
      roads[a][b] = c;
      roads[b][a] = c;
      gin_roads[a][b] = c;
      gin_roads[b][a] = c;
    }
  cin>>K;
  calc(N);
  for(int i=0;i<K;i++)
    {
      int a,b;
      cin>>a>>b;
      results.push_back(make_pair(roads[a][b],gin_roads[a][b]));
    }
  for(int i=0;i<K;i++)
    {
      cout<<results[i].first<<' '<<results[i].second<<endl;
    }
}