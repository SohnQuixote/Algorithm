#include <iostream>
#include <string>
#include <cstring>
using namespace std;
/*
  PI 
  모든 숫자 같을 때 1
  숫자 1씩 단조 증가 감소 2
  숫자 번갈아가면서 4
  숫자 등차수열 5
  그외 10
  최소의 난이도를 계산
  3자리에서 5자리
  최소의 난이도의 합
  3개수열 난이도 + 나머지
  4개수열 난이도 + 나머지
  5개 수열 난이도 +나머지
  난이도를 누적
  코드 말고 풀이를 참조



*/
int C;
string pi;
int N;
int dat[10002];
int difficult(int s,int e)
{
  //s부터 e까지의 난이도를 반환하는 함수
  //1모든 숫자가 같을때 1
  //숫자가 1씩 단조 증가 단조감소 2
  //두개 숫자 번갈아가며 출현 4
  //숫자 등차 5
  bool same = true;
    for(int i=s;i<e;i++)
    {
      if(pi[i] != pi[i+1])
        same = false;
    }
    //하나라도 같으면
    if(same)
      return 1;
    bool inc_dec=true;
    for(int i=s+2;i<=e;i++)
      {
        if(pi[i] - pi[i-1] != pi[s+1] - pi[s])
          inc_dec = false;
      }
    if(inc_dec && abs(pi[s+1] - pi[s]) ==1)
      return 2;
    bool rpted = true;
    for(int i=s+2;i<=e;i++)
      {
        if(pi[s] != pi[s%2])
          rpted = false;
        
      }
    if(rpted)
      return 4;
    


  


  
  // 그외 10
  if(inc_dec)
    return 5;
  return 10;
  
}
int total_diff(int s)
{
  if(s==N)
    return 0;
  int &ret = dat[s];
  if(ret !=-1)
    return ret;
  ret = 987654321;
  for(int L=3;L<=5;L++)
    {
      if(s+L<=N)
        ret = min(ret,total_diff(s+L) + difficult(s,s+L-1));

      
    }
  //점화식이 아주 중요하다 
  return ret;
  
}


int main() {
  cin>>C;
  for(int tc=0;tc<C;tc++)
    {
      memset(dat,-1,sizeof(dat));
      cin>>pi;
      N = pi.length();
      cout<<total_diff(0)<<'\n';
    }
  
  
}