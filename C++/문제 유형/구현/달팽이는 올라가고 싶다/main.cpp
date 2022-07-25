#include <iostream>
using namespace std;
/*
  달팽이는 올라가고 싶다
  달팽이 V미터
  낮 +A미터 밤 -B미터
  시간제한 0.15초
  (V-A)/ (A-B) 만큼 간 후 A만큼 또가면 다감
*/
int calc(int A,int B,int V)
{
  if(A>=V)
    return 1;
  int result = 1;
  result += (V-A) /(A-B);
  if((V-A) % (A-B) != 0)
    result++;
  return result;
}
int main() {
  int A,B,V;
  cin>>A>>B>>V;
  cout<<calc(A,B,V)<<endl;
}