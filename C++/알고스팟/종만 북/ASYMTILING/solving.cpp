#include <iostream>
#include <cstring>
using namespace std;
/*
  ASYMTILING
  

*/

const int INF = 1000000007;
int C,n;
int cache[101][101];
int place(int start, int end)
{
  int &ret = cache[start][end];
  if(ret) return ret;
  if(end ==n-1 && start == n-1)
    return ret = 1;
  else if(end != n-1 &&end-start-1 ==2) return ret = 2;
  else if(end!= n-1 &&(end-start-1 ==1 || end-start-1 ==0)) return ret = 1;
  else if(end != n-1 && end-start -1 <0) return ret = 0;


  if(start ==0 &&end ==n-1)
    return ret = (place(start+1,end) - place(start+1,end-1) +place(start+2,end) - place(start+2,end-2))%INF;
  else if(start>0 && end==n-1)
    return ret = (place(start+1,end) + place(start+2,end)) % INF;
  else
    return ret = (place(start+1,end-1) +place(start+2,end-2) ) % INF;
  
}




int main() 
{
  cin>>C;
  for(int tc=0;tc<C;tc++)

    {
      cin>>n;
      memset(cache,0,sizeof(cache));
      cout<<place(0,n-1)<<'\n';
      //memset(a_cache,0,sizeof(a_cache));
    }

  
}
