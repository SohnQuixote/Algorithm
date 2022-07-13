#include <iostream>
#include <vector>
using namespace std;
/*
  두 개의 숫자열
  A N개 숫자열
  B M개 숫자열
  서로 마주보는 숫자 곱한뒤 더할때 최댓값
  작은 배열 있어야함
*/
int calc(vector<int> A, vector<int> B, int N, int M)
{
  int result = -1;
  if(N==M)
  {
    result = 0;
    for(int i=0;i<N;i++)
      {
        result += A[i] * B[i];
      }
  }
  else if(N>M)
  {
    int diff = N-M;
    for(int s = 0;s<=diff;s++)
      {
        int tmp = 0;
        for(int i=0;i<M;i++)
          {
            tmp+= B[i]*A[i+s];
            
          }
        result = max(result ,tmp);
        
      }
  }
  else
  {
    int diff = M-N;
    for(int s = 0;s<=diff;s++)
      {
        int tmp = 0;
        for(int i=0;i<N;i++)
          {
            tmp+= A[i]*B[i+s];
            
          }
        result = max(result ,tmp);
        
      }
    
  }
  return result;
}
int main()
{
  int T;
  cin>>T;

  vector<int> result;
  for(int i=0;i<T;i++)
    {
      int N,M;
      cin>>N>>M;
      vector<int>A(N,0);
      vector<int>B(M,0);
      for(int j=0;j<N;j++)
        cin>>A[j];
      for(int j=0;j<M;j++)
        cin>>B[j];
      result.push_back(calc(A,B,N,M));
      
    }
  for(int i=0;i<T;i++)
    cout<<"#"<<i+1<<' '<<result[i]<<endl;
}