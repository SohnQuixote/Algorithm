#include <iostream>
using namespace std;
/*
  바닥 공사
  가로길이 N 세로길이 2
  (1*2) (2*1) (2*2)
  바닥 채우는 모든 경우의 수
  순차적으로 빼가면서 해결
  다이나믹은 점화식이 중요
*/
const int MAX = 1001;
int floor[MAX] = {0,};
int calc(int N)
{
  floor[1] =1;
  floor[2] = 3;
  for(int i=3;i<N+1;i++)
    floor[i] = (floor[i-1] +(2*floor[i-2])) % 796796;
  return 0;
}
int main() {
  int N;
  cin>>N;
  calc(N);
  cout<<floor[N]<<endl;
}