#include <iostream>
#include <algorithm>

using namespace std;
/*
  게임 횟수 - X
  이긴 게임 - Y
  Z - (Y/X) *100 소숫점 버림
  (Y+N)/(X+N) -> N이 몇이여야지 Z가 변하느냐
  순차적으로 증가하면 무조건 안됨
 오버헤드 일어나는거 같음 
  범위 때문에 문제 발생하는거 같음
  자료형때문에 틀린걸로 추정
*/
const int RANGE = 1000000000;
const int IMPOSSIBLE = -1;
int calc(long long X,long long Y,int Z)
{
  if(Z>=99)
    return -1;
  int start = 0;
  int result = IMPOSSIBLE;
  int end = RANGE;
  while(start<=end)
    {
      int mid = (start+end)/2;

      int temp_i_Z = (100*(Y+mid))/(X+mid);
      if(temp_i_Z <= Z)
      {
        result = mid +1;
        start = mid+1;
        //작으면 증가해야됨
      }
      else
        end = mid-1;
      //크면 감소
    }
  return result;
  
}
int main() {
  long long X,Y;
  cin>>X>>Y;
  int Z = (Y*100) / X;
  //cout<<ZZ<<Z<<endl;
  cout<<calc(X,Y,Z)<<endl;
}