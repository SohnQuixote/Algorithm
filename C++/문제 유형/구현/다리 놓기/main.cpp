#include <iostream>
#include <vector>
using namespace std;
/*
  다리 놓기
  N,M
  N<=M
  서쪽 N 동쪽 M
  N개만큼 지을때 다리의 경우 의 수
  N은 무조건 다 채워야 하기에 M 기준으로 생각      
*/
const int MAX = 30;
int visited[MAX][MAX] = {0,};
int calc(int N,int M)
{
  if(visited[N][M])
    return visited[N][M];
  else if(N==0)
  {
    visited[N][M] = 1;
    return 1;
  }
  else if(N==M)
  {
    visited[N][M] = 1;
    return 1;
  }
  else if(N==1)
  {
    visited[N][M] = M;
    return M;
  }

  int result = calc(N-1,M-1) + calc(N,M-1);
  if(!visited[N][M])
    visited[N][M] = result;
  return result;
  
}
int main() {
  int T,N,M;
  cin>>T;
  vector<int>results;
  for(int i =0;i<T;i++)
    {
      cin>>N>>M;
      results.push_back(calc(N,M));
    }
  for(int i=0;i<T;i++)
    {
      cout<<results[i]<<endl;
    }
}