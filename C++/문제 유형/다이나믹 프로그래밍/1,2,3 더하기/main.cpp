#include <iostream>
#include <vector>
using namespace std;
/*
  1,2,3 더하기
  간단한 재귀식 -> (시간초과?)
*/
int calc(int tmp)
{
  if(tmp == 0)
    return 1;
  if(tmp<0)
    return 0;
  int result =0;
  result+=calc(tmp-1)+calc(tmp-2)+calc(tmp-3);

  return result;
}
int main() {
  int T;
  cin>>T;
  for(int i=0;i<T;i++)
    {
      int tmp;
      cin>>tmp;
      cout<<calc(tmp)<<endl;
    }
  
}