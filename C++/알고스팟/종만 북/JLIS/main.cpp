#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int c,n,m;
int A[100];
int B[100];
int cache[101][101];
const long long NEGINF = INT64_MIN;
/*
  A[indexA] , A[index]

*/
int jlis(int i_a,int i_b)
{
  int &ret = cache[i_a+1][i_b+1];
  if(ret != -1) return ret;
  //-1부터 시작해서 같을 수가없음
  //모든 인덱스를 다 탐사하기 때문에
  ret =0;
  long long a,b;
  
  if(i_a == -1)
  {
    a = NEGINF;
  }
  else{
    a = A[i_a];
  }
  if(i_b ==-1)
  {
    b = NEGINF;
  }
  else
  {
    b = B[i_b];
  }
  long long max_ele = max(a,b);
  for(int na = i_a+1;na<n;na++)
    if(max_ele < A[na])
      ret = max(ret , jlis(na,i_b)+1);
  for(int nb = i_b+1;nb<m;nb++)
    if(max_ele <B[nb])
      ret = max(ret , jlis(i_a,nb) +1);
  return ret;
  
}
int main() {
  cin>>c;
  for(int tc=0;tc<c;tc++)
    {
      memset(cache,-1,sizeof(cache));
      cin>>n>>m;
      for(int i=0;i<n;i++)
        cin>>A[i];
      for(int i=0;i<m;i++)
        cin>>B[i];
      //cache[0][0] = NEGINF;
      cout<<jlis(-1,-1)<<'\n';
      
    }
  
}