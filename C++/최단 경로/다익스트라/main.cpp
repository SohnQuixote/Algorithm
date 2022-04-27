#include <iostream>
#include <vector>
#include <queue>
/*
  최단 경로 알고리즘
*/
using namespace std;
//간단한 다익스트라 구현
//그래프 정보는 페어 벡터로 구현
const int MAX = 10000;
const int INF = 987654321;
vector<pair<int,int>> graph[MAX];
bool visited[MAX] = {};
int distances[MAX] = {0,};
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
//오름차순 정렬 하는 우선순위큐를 사용
int get_smallest_node_simple(int N)
{
  int min_value = INF;
  int index = 0;
  //매번 배열을 다 보고 최소의 거리를 가진 노드의 인덱스를 반환함
  for(int i=1;i<N+1;i++)
    {
      if(distances[i]<min_value && !visited[i])
      {
        min_value = distances[i];
        index = i;
      }
      
    }
  return index;
}
void simple_dijkstra(int start,int N,int M)
{
  distances[start] = 0;
  visited[start] = true;
  for(int i=0;i<graph[start].size();i++)
    {
      distances[graph[start][i].first] = graph[start][i].second;
    }
  for(int i=0;i<N-1;i++)
    {
      int now = get_smallest_node_simple(N);
      visited[now] = true;
    for(int j=0;j<graph[now].size();j++)
    {
      int cost = distances[now] + graph[now][j].second;
      if(cost<distances[graph[now][j].first])
        distances[graph[now][j].first] = cost;
    }
    }
}
void revised_dijkstra(int start,int N,int M)
{
  pq.push(make_pair(0,start));
  distances[start] = 0;
  while(!pq.empty())
    {
      pair<int,int> information;
      information = pq.top();
      pq.pop();
      int dist = information.first;
      int now = information.second;
      if(distances[now]<dist)
        continue;
      for(int i=0;i<graph[now].size();i++)
        {
          int cost = dist+graph[now][i].second;
          if(cost<distances[graph[now][i].first])
          {
            distances[graph[now][i].first] = cost;
            pq.push(make_pair(cost,graph[now][i].first));
          }
          
        }

      
    }

  
}
//개선된 다익스트라 구현

int main() {
  int N,M;
  //노드수 N 간선수 M
  cin>>N>>M;
    for(int i= 1;i<N+1;i++)
    {
      distances[i] = INF;
      //1부터 N까지의 거리 배열
    }
  for(int i=0;i<M;i++)
    {
      int a,b,c;
      cin>>a>>b>>c;
      graph[a].push_back(make_pair(b,c)); 
    }
  revised_dijkstra(1,N,M);
  for(int i=1;i<N+1;i++)
    cout<<distances[i]<<endl;
}