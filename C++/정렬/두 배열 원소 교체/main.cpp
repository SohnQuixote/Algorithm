#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
  두배열 원소 교체
  두개 배열 A,B
  두개 배열  N개 원소로 구성
  최대 K번의 바꿔치기
  목표 배열 A의 원소의 합이 최대
*/
int calc(vector<int>A,vector<int>B,int N, int K)
{
  for(int i=0;i<N;i++)
    {
      if(!K)
        break;
      if(A[i] < B[N-i-1])
      {
        int temp = A[i];
        A[i] = B[N-i-1];
        B[N-i-1] = temp;
        K--;
      }
      
    }
  return accumulate(A.begin(),A.end(),0);
}

int main() {
  int N,K;
  vector<int>A;
  vector<int>B;
  int temp;
  cin>>N>>K;
  for(int i=0;i<N;i++)
    {
      cin>>temp;
      A.push_back(temp);
    }
  for(int i=0;i<N;i++)
    {
      cin>>temp;
      B.push_back(temp);
    }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());

  cout<<calc(A,B,N,K)<<endl;
}