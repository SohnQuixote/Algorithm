/*
큰수의 법칙
N = 배열 크기
M = 숫자가 더해지는 횟수
K = 연속으로 더해질 수 있는 수

e.g., {2,4,5,4,6} ->46
  */
#include <iostream>
#include <algorithm>

using namespace std;
int calc(int* array,int N, int M,int K){
  int result = 0;
  int max = array[N-1];
  int sec_max = array[N-2];
  //wrong
  //int iteration = (int)(M/K);
  //iteration *=K;
  //
  //correct
  int iteration = (int)(M/(K+1))*K;
  iteration += M%(K+1);
  result += iteration *max;
  result += (M-iteration) * sec_max;
  
  return result;
}
int main() {
  int N,M,K;
  std::cin>>N;
  std::cin>>M;
  std::cin>>K;
  int *array = (int*)malloc(sizeof(int)*N);
  int i=0;
  for (i=0;i<N;i++)
    {
      cin>>array[i];
    }
  sort(array,array+N);
  
  std::cout<<calc(array,N,M,K)<<endl;
}