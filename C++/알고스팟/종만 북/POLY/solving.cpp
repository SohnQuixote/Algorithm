#include <iostream>
#include <cstring>
using namespace std;

/*
  폴리오미노
  n개의 정사각형 구성 폴리오미노 만들려함
  세로로 단조인 폴리오미노의 수
  가로줄 한줄 두개 교차 안하면 됨

*/
const int MOD = 10000000;
int C,n;




int cache[101][101];
int place(int lvl,int left)
{
  if(left <=1)
    return 1;
  int &ret = cache[lvl][left];
  if(ret) return ret;

  return ret = (place(lvl,left-1) + place(lvl+1,left-1)) %MOD;
}




int main() {
  cin>>C;
  for(int tc=0;tc<C;tc++)
    {
      cin>>n;
              
      memset(cache,0,sizeof(cache));
      int result= place(0,n);
      

      result = (result>=MOD)?(result%MOD):result;
      cout<<result<<'\n';

      
    }
}