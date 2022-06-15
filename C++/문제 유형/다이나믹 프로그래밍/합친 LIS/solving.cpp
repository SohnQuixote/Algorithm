#include <iostream>
#include <vector>
using namespace std;
int n,m;
/*
  합친 LIS
  그냥 두개 합쳐서 LIS 찾기?
    
*/
const long long NEGINF = -987654321;
vector<int>A(200,0);
vector<int>cache(202,-1);
vector<vector<int>>caches(101,vector<int>(101,-1));
vector<int>B(100,0);
vector<int>C(100,0);
int jlis(int i_b,int i_c)
{
  int &ret = caches[i_b+1][i_c+1];
  if(ret!=-1) return ret;
  ret = 2;
  long long b = (i_b == -1? NEGINF : B[i_b]);
  long long c = (i_c == -1? NEGINF : C[i_c]);
  long long max_element = max(b,c);
  if(b==NEGINF && c== NEGINF)
    ret =0;
  else if(b==c)
    ret =1;
  //같으면 하나임
  for(int nextb = i_b+1;nextb<n;nextb++)
    {
      if(max_element<B[nextb])
        ret = max(ret,jlis(nextb,i_c)+1);
      
    }
  for(int nextc = i_c+1;nextc<m;nextc++)
    {
      if(max_element<C[nextc])
        ret = max(ret,jlis(i_b,nextc)+1);
      
    }
  return ret;
}
int LIS(int start)
{
  int &ret = cache[start];
  if(ret != -1) return ret;
  ret = 1;
  for(int next =start+1;next<n+m;next++)
    {
      if(A[next] > A[start])
        ret = max(ret,LIS(next)+1);
    }
  return ret;
}
int main() {
  cin>>n>>m;
  /*for(int i=0;i<n+m;i++)
    {
      cin>>A[i];
    }
  int result = 0;
  for(int i=0;i<n+m;i++)
    result = max(result,LIS(i));
  */
  for(int i=0;i<n;i++)
    {
      cin>>B[i];
    }
  for(int i=0;i<m;i++)
    {
      cin>>C[i];
    }
  int result = 0;
  result = jlis(-1,-1);
  cout<<result<<endl;
  //cout<<LIS(0)<<endl;
}