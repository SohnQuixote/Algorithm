#include <iostream>
using namespace std;
/*
  플로이드 워셜
*/
const int MAX = 1000;
const int INF = 987654321;
int maps[MAX][MAX] = {0,};
int main() {
  int N,M;
  cin>>N>>M;
  for(int i=1;i<N+1;i++)
    for(int j=1;j<N+1;j++)
      {
        if(i==j)
          maps[i][j] = 0;
        else
          maps[i][j] = INF;
      }
  for(int i=0;i<M;i++)
    {
      int a,b,c;
      cin>>a>>b>>c;
      maps[a][b] = c;
    }
  for(int i=1;i<N+1;i++)
    {
      for(int j=1;j<N+1;j++)
        {
          for(int k=1;k<N+1;k++)
            {
              maps[j][k] = min(maps[j][k], maps[j][i]+maps[i][k]);
            }
        }
    }
  for(int i=1;i<N+1;i++)
    {
    for(int j=1;j<N+1;j++)
  {
    cout<<maps[i][j]<<' ';
  }
      cout<<endl;
      }
}