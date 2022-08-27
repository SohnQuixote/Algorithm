#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

//bool arr[100001][100001] = {0,};
struct info{
long long a;
long long b;
};
bool operator <(info x,info y)
{
  //가장 끝시간이 짧은것 부터 하기
  //다음 시작시간이 끝 시간 보다 이상이어야함
  if(x.b>y.b)
    return true;
  if(x.b== y.b)
  {
    //0인것이 그냥 먼저 오게함?
    //카운트 안하기
    if(x.a>y.a)
      return true;
    return false;
  }
  return false;  
}

//불가능 시작시간을 갱신
//bool alreadyed[2147649] = {0,};
int n,m;
long long times;
int main() {
  cin>>n;
  priority_queue<info,vector<info>>pq;
  for(int i=0;i<n;i++)
    {
      long long start,end;
      cin>>start>>end;
      pq.push({start,end});
    }
    times = pq.top().b;
    pq.pop();
    int cnt=1;
    //그리디 같은 경우 조건을 잘 알아야함
    while(!pq.empty())
      {
        info now = pq.top();
        pq.pop();
        if(now.a>=times)
        {
          times = now.b;
          cnt++;
        }


        
      }
    cout<<cnt;
}