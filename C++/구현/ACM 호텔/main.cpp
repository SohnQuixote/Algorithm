#include <iostream>
using namespace std;
/*
  ACM 호텔
  H,W
  H층 W개방
  손님 엘베 거리 신경 안씀
  가까운 거리에 손님 배정
  입력 T 테스트 데이터
  테스트 데이터
  H,W,N 층수 방수 손님수
  출력 - 방번호
*/
int calc(int H,int W,int N)
{
  int result = 0;
  if((N%H) == 0)
  {
    result+= 100 *H;
    result+= (int)(N/H);
  }
  else{
  result+= 100*(N%H);
    result+= (int)(N/H)+1;
    }
  return result;
}
int main() {
  int T,H,W,N;
  cin>>T;
  int *results = new int[T];
  for (int i=0;i<T;i++)
    {
      cin>>H>>W>>N;
      results[i] = calc(H,W,N);
    }
  for(int i= 0;i<T;i++)
    {
      cout<<results[i]<<endl;
    }
  delete[] results;
}