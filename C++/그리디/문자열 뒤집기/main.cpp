#include <iostream>
#include <string>
using namespace std;
/*
  문자열 뒤집기
  다솜이 0과 1로만 이루어진 문자열 S
  모든숫자 전부 같게 연속된 하나 이상 숫자 전부 뒤집기
  뒤집는 최소횟수
*/
int calc(string S)
{
  int one = 0;
  int zero = 0;
  for(int i=0;i<S.size();i++)
    {
      int temp = S[i] - 48;
      if(temp ==0 &&((S[i+1] - 48) == 1 || (i+1) == S.size() ) )
        one +=1;
      if(temp == 1 && ((S[i+1]-48) == 0 || (i+1) == S.size()) )
        zero+=1;
    }
  if(one>zero)
    return zero;
  else
    return one;
}
int main() {
  string S;
  cin>>S;
  cout<<calc(S)<<endl;
}