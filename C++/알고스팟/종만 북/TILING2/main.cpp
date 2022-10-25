#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
#include <queue>
#include <string>
#include <map>
using namespace std;
/*
  TILING2
  2*n크기의 사각형
  2*1크기 사각형 빈틈없이 채우기
*/
const long long MOD = 1000000007;
int C,N;
long long cache[101];


long long calc(int n)
{
  if(n==0)
    return 1;
  //꽉 채운것
  if(n<0)
    return 0;
  //최댓값도 아닌 경우의 수임
  long long &ret = cache[n];
  if(ret)
    return ret;
  //중간에 오버플로 가능
  ret = (calc(n-1) + calc(n-2)) %MOD;

  return ret;

  
}
int main() {
  cin>>C;
  for(int tc=0;tc<C;tc++)
    {
      cin>>N;
      //memset(cache,0,sizeof(cache));
      cout<<calc(N) % MOD<<'\n';

      
    }




  
}