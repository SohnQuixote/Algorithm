#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
/*
  PI
*/
int C;
int dat[10000];
string pi;
const int INF = 987654321;
int difficult(int s, int e)
{
  char a = pi[s];
  int d = pi[s+1] - pi[s];
  //char o = pi[1];
  //char k = pi[0];
  
  bool all_same = true;
  bool inc_dec = true;
  bool rpted = true;
  for(int i=s;i<=e;i++)
    if(pi[i] != a)
      all_same = false;
  if(all_same)
    return 1;
  for(int i=s;i< e;i++)
    if(pi[i+1] - pi[i] != d)
      inc_dec = false;
  if(inc_dec && abs(d) ==1)
    return 2;
  string chk = pi.substr(s,e-s+1);
  for(int i=0;i<chk.size();i++)
    {
      if(chk[i] != chk[i%2])
        rpted = false;
    }

  if (rpted)
    return 4;
  if(inc_dec)
    return 5;
  return 10;
  


  
}
int chk(int s)
{
  if(s==pi.size())
    return 0;
  int &ret = dat[s];
  if(ret!=-1)
    return ret;
  ret = INF;
  for(int l=3;l<=5;l++)
    {
      if(s+l <=pi.size())
        ret = min(ret , (chk(s+l) + difficult(s,s+l-1)) );

      
    }

  return ret;
}

int main() {
  cin>>C;
  for(int tc=0;tc<C;tc++)
    {
      memset(dat,-1,sizeof(dat));
      cin>>pi;
      cout<<chk(0)<<'\n';
      
    }
  
  
}