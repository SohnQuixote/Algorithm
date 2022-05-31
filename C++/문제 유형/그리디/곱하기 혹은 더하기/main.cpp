#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/*
  곱하기 혹은 더하기
*/
int calc(string S)
{
  //int result = 0;
  int temp = S[0]-48;
  for(int i=1;i<S.size();i++)
    {
      //cout<<temp<<endl;
      int stointeger = S[i] -48;
      if((temp + stointeger) > (temp *stointeger))
      {        
        temp = temp + stointeger;
      }
      else
        temp *= stointeger;
    }
  return temp;
}
int main() {
  string S;
  cin>>S;
  cout<<calc(S)<<endl;
}