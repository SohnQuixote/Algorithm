#include <iostream>
#include <cstring>
using namespace std;
/*
  SNAIL
  깊이 n미터 달팽이
  비내리면 2미터
  맑으면 1미터
  m일간 비가 올 확률 75%
  달팽이가 끝까지 올라갈 확률 계산 프로그램
  올라간 높이 , 현재 확률 
  모든 경우의 수를 고려한 다음 n미터 이상 올라갈 확률
  최대 경우의 수 -> 3개와 1개임
  매번 4개 선택지
  4의 m승
  모든 경우의 수를 배열로 고려하는 것은 비효율적이며 많은 시간 필요로함
  

*/
double cache[1001][2001];
int C,n,m;
double climb(int days,int climbed)
{
  double &ret = cache[days][climbed];
  if(days==m) return ret = (climbed>=n) ? 1 : 0;
  if(ret != -1) return ret;
  return ret = 0.75 *climb(days+1, climbed+2) + 0.25 * climb(days+1,climbed+1);

  
}

int main() {
  cin>>C;

  if(C>50 || C<1)
    return 0;
  
  for(int tc=0;tc<C;tc++)
    {
      cin>>n>>m;
      if(n<=0 || n>=1001)
        return 0;
      if(m<=0 || m>=1001)
        return 0;
      for(int i=0;i<1001;i++)
        for(int j=0;j<2001;j++)
          cache[i][j] = -1;
      //memset(cache,0,sizeof(cache));
      printf("%.10f\n" ,climb(0,0) );


      
    }

  
}