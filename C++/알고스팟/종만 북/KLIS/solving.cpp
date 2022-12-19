#include <iostream>
using namespace std;
/*
  KLIS

  단조 증가 할때 
  이중 가장 긴것을 LIS
  LIS 두개 이상 가능
  중복 숫자 없는 수열 주어질 때 사전 순서대로 맨 앞에서 K번째 있는 LIS 구하기
  모든 숫자가 서로 다른 수열이 주어짐
  이 수열중 사전순서대로 맨앞에서 K번째에 있는 LIS를 구하기
  LIS는 어떻게 구했지?
  -> 재귀 호출 -> 동적 계획법
  
*/
int C;
int N,K;

int arr[500];
int main() {
  cin>>C;
  for(int tc=0;tc<C;tc++)
    {
      cin>>N>>K;
      for(int i=0;i<N;i++)
        cin>>arr[i];
      
    }
}