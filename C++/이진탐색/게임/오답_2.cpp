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
*/
const int RANGE = 1000000000;
const int IMPOSSIBLE = -1;
int calc(int X,int Y,int Z)
{
  int start = 1;
  int result = IMPOSSIBLE;
  int end = RANGE;
  while(start<=end)
    {
      int mid = static_cast<int>((start+end)/2);
      double d_mid = static_cast<double>(mid);
      double d_Y = static_cast<double>(Y);
      double d_X = static_cast<double>(X);
      double temp_Z = (d_Y+d_mid) / (d_X+d_mid);
      
      int temp_i_Z = static_cast<int>(temp_Z * 100);
      if(temp_i_Z != Z)
      {
        result = mid;
        end = mid-1;
      }
      else if(temp_i_Z == Z)
        start = mid+1;
    }
  return result;
  
}
int main() {
  double ZZ;
  int X,Y,Z;
  cin>>X>>Y;
  ZZ =static_cast<double>(Y)/static_cast<double>(X);
  ZZ *= 100;
  Z = static_cast<int>(ZZ);
  //cout<<ZZ<<Z<<endl;
  cout<<calc(X,Y,Z)<<endl;
}