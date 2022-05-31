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
//priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
queue<pair<int,int>> pq;
//vector<pair<int,int>> graphs[MAX];
int calc(int N,int K)
{
  
  for(int i=0;i<MAX;i++)
    {
      maps[i] = INF;
    }
  maps[N] = 0;
  pq.push(make_pair(0,N));
  while(!pq.empty())
    {
      int dist = pq.front().first;
      int now = pq.front().second;
      pq.pop();
      if(now == K)
        break;
      int prev,teleport,forward;
      prev = now-1;
      teleport = now*2;
      forward = now+1;
      if(teleport<MAX && maps[teleport]>(maps[now]))
      {
        maps[teleport] = maps[now];
        pq.push(make_pair(maps[now] , teleport));
      }
      if(prev>=0 && maps[prev] >(maps[now]+1))
      {
        maps[prev] = maps[now]+1;
        pq.push(make_pair(maps[now]+1,prev));
      }
      if(forward< MAX && maps[forward]>(maps[now]+1))
      {
        maps[forward] = maps[now]+1;
        pq.push(make_pair(maps[now]+1, forward));
      }

    }
  return maps[K];
}
int main() {
  int N,K;
  cin>>N>>K;
  cout<<calc(N,K)<<endl;
}