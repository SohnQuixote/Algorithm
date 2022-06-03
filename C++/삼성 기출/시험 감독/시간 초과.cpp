#include <iostream>
#include <vector>
using namespace std;
/*
  시험 감독
  총 N개 시험장
  각각 시험장 응시자
  감독 -총 부
  총 - B명 감시
  부 - C명 감시
  각각 시험장 - 총 1명
  부 - 여러명
  각 시험장 -> 감독관 수 최솟값
  총 감독관 무조건 1명씩
*/
int main() {
  int N;
  cin>>N;
  int B,C;
  int result = N; //총감독관 무조건 1명씩
  vector<int> test(N,0);
  for(int i=0;i<N;i++)
    {
      cin>>test[i];
    }
  cin>>B>>C;
  for(int i=0;i<N;i++)
    {
      test[i]-=B;
    }
  //총 감독관 1명씩
  for(int i=0;i<N;i++)
    {
      while(test[i] >0)
        {
          test[i] -=C;
          result++;
        }
      
    }
  cout<<result<<endl;
}