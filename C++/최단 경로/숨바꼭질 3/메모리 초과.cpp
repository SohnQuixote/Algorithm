#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
  숨바꼭질 3
  수빈이 위치 N
  동생 위치 K
  수빈이 걸을때 X-1 X+1 1초
  수빈이 순간이동 2*X 0초
*/
const int MAX = 100001;
const int INF = 987654321;
int maps[MAX] = {0,};
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//vector<pair<int,int>> graphs[MAX];
int calc(int N,int K)
{
   if(N>=K)
     return (N-K);
  for(int i=0;i<MAX;i++)
    {
      maps[i] = INF;
    }
  maps[N] = 0;
  pq.push(make_pair(0,N));
  while(!pq.empty())
    {
      int dist = pq.top().first;
      int now = pq.top().second;
      pq.pop();
      if(maps[now] < dist)
        continue;
      if(now>K)
      {
        int temp = 0;
        for(int i=now-1;i>=K;i--)
          {
            temp = now-i;
            if(maps[i] > (maps[now]+temp))
            {
              maps[i] = maps[now] + temp;
              pq.push(make_pair((maps[now]+temp),i));
            }
          }
        continue;
      }
      for(int i= 2*now;i<K+now && i<MAX;i*=2)
        {
          if(maps[i]>maps[now])
          {
          maps[i] = maps[now];
          pq.push(make_pair(maps[now],i));
          }
        }
        int temp =0;
      for(int i=now+1;i<K+1 && i<MAX;i++)
        {
          temp = (i-now)%now;
          if(maps[i] > (maps[now]+ temp))
          {
            maps[i] = maps[now]+ temp;
            pq.push(make_pair((maps[now]+temp),i));
            
          }
          
        }
    }
  return maps[K];
}
int main() {
  int N,K;
  cin>>N>>K;
  cout<<calc(N,K)<<endl;
}