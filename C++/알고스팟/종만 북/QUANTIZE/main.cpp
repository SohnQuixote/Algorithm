#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
/*
  QUANTIZE
  넓은 범위를 갖는 값들을 작은 범위를 갖는 값들로 근사해 표현
  자료를 손실 압축
  최대 S종류 값 양자화 숫자 원래 수열에 없는 숫자 가능
  각 숫자별 오차제곱의 합을 최소화 양자화
  제한시간
  0초
  완전탐색 시간터질거 같음
  풀이의 과정

  반복되는 부분문제
  조건
  1. 양자화 시켜야 될 수의 범위 1000?
  2. 
  책 참고해서 풀기
  s개로 묶어야함
  quantize(from,parts) = min(minErr(from,from+size-1) + quantize(from+size , parts-1))
  평균값-> 오차 최소화 가능
  종만은...천재야!!!
*/
const int INF = 987654321;
int C;
int N;
int S;
int A[101],pS[101] , sqS[101];
void precalc()
{
  sort(A,A+N);
  pS[0] = A[0];
  sqS[0] = A[0] * A[0];
  //누적 행렬로 합과 제곱의 합을 구해놓음
  for (int i=1;i<N;i++)
    {
      pS[i] = pS[i-1] + A[i];
      sqS[i] = sqS[i-1] + A[i] * A[i];
    }
  
}

int minErr(int lo,int hi)
{  
  int sum = pS[hi] - (lo==0 ?0:pS[lo-1]);
  int sqSum = sqS[hi] -(lo==0 ?0 :sqS[lo-1]);
  int m = int(0.5 + (double)sum/(hi-lo+1));
  int ret = sqSum - 2*m*sum + m*m*(hi-lo+1);
  return ret;
}
int cache[101][11];

int quant(int from,int parts)
{
  if(from == N) return 0;
  if(parts ==0) return INF;
  int &ret = cache[from][parts];
  if(ret !=-1) return ret;
  ret = INF;
  for(int partSize =1;from+partSize<=N;partSize++)
    {
      ret = min(ret , minErr(from,from+partSize-1) + quant(from+partSize , parts-1));
    }

  return ret;
  

  
}




int main() {
  cin>>C;
  for(int tc=0;tc<C;tc++)
    {
      cin>>N>>S;
      for(int idx=0;idx<N;idx++)
        cin>>A[idx];
      memset(cache,-1,sizeof(cache));
      precalc();
      cout<<quant(0,S)<<'\n';
    }
  
}