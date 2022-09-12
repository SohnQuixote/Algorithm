#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
/* 
  도로 네트워크
  N개 도시 N-1개 도로
  모든 도시쌍 경로
  총 K개 도시쌍
  두 도시 연결 경로 상 가장짧은 도로 긴 도로 길이
  유니온 파인드?
  우선순위 큐 
  최대 최소
  유니온 파인드는 전체 연결임 
  (최소 스패닝 트리)
  원하는 것은 해당 점간의 최소/최대 거리
  최소 -> 다익스트라
*/
struct low{

  int b;
  int c;
};
struct high{
  int b;
  int c;
};
bool operator<(low x, low y)
{
  if(x.c>y.c)
    return true;
  return false;
  
}
bool operator<(high x, high y)
{
  if(x.c<y.c)
    return true;
  return false;
}
priority_queue<low,vector<low>>low_q;
priority_queue<high,vector<high>>high_q;

vector<pair<int,int>>g[100001];
int parents[100001] = {0,};
int n;
int main() {
  cin>>n;
  //최소 다익스트라 최대 다익스트라
  //다익스트라 k번?
  //플로이드 워셜 하면 너무 큼
  //10만의 3승
  for(int i=0;i<n-1;i++)
    {
      int a,b,c;
      cin>>a>>b>>c;
      g[a].push_back({b,c});
      g[b].push_back({a,c});
      //그래프 정보
      
    }
 int k;
 cin>>k;
 for(int i=0;i<k;i++)
   {
      int start,loc;
     cin>>start>>loc;
     //우선순위 큐를 사용하기
    int low_visited[100001] = {0,};
     int low_dist[100001] = {0,};
     for(int idx=0;idx<n;idx++)
       low_dist[idx] = 987654321;
     low_dist[start] = 0;
     int high_visited[100001] = {0,};
     int high_dist[100001] = {0,};
     for(int idx=0;idx<n;idx++)
       high_dist[idx]= -1;
     high_dist[start] = 0;
     low_q.push({start,0});
     high_q.push({start,0});
     while(!low_q.empty())
       {
        low now = low_q.top();
         low_q.pop();
         if(low_visited[now.b])
            continue;
         low_visited[now.b] =1;
         for(int idx=0;idx<g[now.b].size();idx++)
           {
             int d,c;
             tie(d,c) = g[now.b][idx];
            if(low_dist[now.b] + c< low_dist[d])
            {
              low_dist[d] = low_dist[now.b]+c;
              low_q.push({d,low_dist[d]});
              
            }

             
           }

         
       }
        while(!high_q.empty())
       {
        high now = high_q.top();
         high_q.pop();
         if(high_visited[now.b])
            continue;
         high_visited[now.b] =1;
         for(int idx=0;idx<g[now.b].size();idx++)
           {
             int d,c;
             tie(d,c) = g[now.b][idx];
            if(high_dist[now.b] + c> high_dist[d])
            {
              high_dist[d] = high_dist[now.b]+c;
              high_q.push({d,high_dist[d]});
              
            }

             
           }

         
       }
     cout<<low_dist[loc]<<' '<<high_dist[loc]<<'\n';
   }
}