#include <iostream>
using namespace std;
/*
  볼링공 고르기
  A,B 서로 무게 다른 볼링공 고르려 함
  볼링공 갯수 N 무게 1부터 M까지
  볼링공을 고르는 총 경우의 수 출력
  조합이니 순서 상관 없음
  다른걸 골라야 해서 그냥 조합은 안됨
*/
//const int MAX = 1001;
//int balls[MAX] = {0,};
int chosen_balls[11] = {0,};
//int B_balls[11] = {0,};
int calc()
{
  int result =0;
  for(int i=1;i<11;i++)
    {
      if(chosen_balls[i])
      {
        for(int j = i+1;j<11;j++)
          {
            result+=chosen_balls[i] * chosen_balls[j];
          }
        chosen_balls[i] = 0;
      }
      
      
    }

  return result;
}
int main() {
  int N,M;
  cin>>N>>M;
  for(int i=0;i<N;i++)
    {
      int temp;
      cin>>temp;
      chosen_balls[temp]++;
    }
  cout<<calc()<<endl;
}