#include <iostream>
using namespace std;
/*
  1번부터 N번까지 회사
  서로 연결
  시작지 1번 목표 X번회사
  양방향 그래프 1만큼의 시간
  중간에 K번회사 소개팅에 들름
  1-K-X 최소 이동시간
  플로이드 워셜 사용 (범위 작으니 O(N3))도 충분
  만약 도달할 수 없으면 -1 maps[i][k] == INF or maps[k][x] == INF
*/
const int MAX = 101;
const int INF = 987654321;
int companys[MAX][MAX] = {0,};
int calc(int X,int K,int N)
{
   for(int k=1;k<N+1;k++)
     {
       for(int i=1;i<N+1;i++)
         {
          for(int j=1;j<N+1;j++)
            {
              companys[i][j] = min(companys[i][j] , companys[i][k] + companys[k][j]);
              
            }
           
         }
     }
  if(companys[1][K] == INF || companys[K][X] == INF)
    return -1;
  return companys[1][K] + companys[K][X];
}
int main() {
  int N,M;
  int X,K;
  cin>>N>>M;
  for(int i=1;i<N+1;i++)
    {
      for(int j=1;j<N+1;j++)
        {
          if(i!=j)
            companys[i][j] = INF;
          else
            companys[i][j] = 0;
        }
    }
  for(int i=0;i<M;i++)
    {
      int a,b;
      cin>>a>>b;
      companys[a][b] = 1;
      companys[b][a] = 1;
    }
  cin>>X>>K;
  cout<<calc(X,K,N)<<endl;
}