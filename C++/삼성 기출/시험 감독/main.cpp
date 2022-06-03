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
  O(lgn) 만들어야 시간초과 X?  
  변수 범위 언제나 고려
*/
int main() {
  int N;
  cin>>N;
  long long B,C;
  long long result = N; //총감독관 무조건 1명씩
  vector<long long> test(N,0);
  for(int i=0;i<N;i++)
    {
      cin>>test[i];
    }
  cin>>B>>C;
  for(int i=0;i<N;i++)
    {
      test[i]-=B;
      if(test[i] > 0)
      {
        long long tmp = 0;
        tmp  =test[i]/C;
        if(test[i] % C !=0)
        {
          tmp++;
        }
        result += tmp;
      }
    }
  //총 감독관 1명씩
  cout<<result<<endl;
}