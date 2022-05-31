#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
  전보
  N개 도시 존재
  최대한 많은 도시로 메시지를 보냄  
  그냥 다익스트라로 해결 가능
*/
const int MAX_CITY = 30001;
const int INF = 987654321;
vector<pair<int,int>>cities[MAX_CITY];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int distances[MAX_CITY] = {0,};
pair<int,int> calc(int N,int C)
{
  pq.push(make_pair(0,C));
  distances[C] = 0;
  while(!pq.empty())
    {
      int dist = pq.top().first;
      int now = pq.top().second;
      pq.pop();
      if(distances[now] < dist)
        continue;
      for(int i=0;i<cities[now].size();i++)
        {
          int conn_dist = cities[now][i].first;
          int conn_now = cities[now][i].second;
          if(distances[conn_now]> dist+conn_dist)
          {
            distances[conn_now] = dist+ conn_dist;
            pq.push(make_pair(dist+conn_dist,conn_now));
          }
        }    
    }
  int result_1,result_2;
  result_1 = N;
  result_2 = 0;
  for(int i=1;i<N+1;i++)
    {
     if(distances[i] == INF || i ==C)
       result_1--;
      if(distances[i] != INF && distances[i] > result_2)
        result_2 = distances[i];
    }
  return make_pair(result_1,result_2);
}
int main() {
  int N,M,C;
  cin>>N>>M>>C;
  for(int i=1;i<N+1;i++)
    distances[i] = INF;
  for(int i=0;i<M;i++)
    {
      int d,e,f;
      cin>>d>>e>>f;
      cities[d].push_back(make_pair(f,e));
      //d와 e가 f의 가중치로 연결
    }
  pair<int,int> result =calc(N,C);
  cout<<result.first<<' '<<result.second<<endl;
}