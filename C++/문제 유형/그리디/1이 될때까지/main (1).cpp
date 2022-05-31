#include <iostream>
/*
1이 될때까지

  */
int calc(int N,int K){
  int result = 0;
  for (result = 0;;)
    {
    if(N==1)
    {
      break;
    }
  if(N%K ==0)
  {
    N/=K;
    result++;
  }
  else
  {
    N-=1;
    result++;
  }
      
      }
  return result;
}
int main() {
  int N,K;
  std::cin>>N>>K;
  std::cout<<calc(N,K)<<std::endl;
}