#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
  숨바꼭질
  1 ~ N 헛간 중 하나 숨기
  술래 무조건 1번 헛간
  M개 양방향 통로 존재
  가장 먼거리 최단 경로 헛간 숨기
  다익스트라 사용 
*/
priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
const int MAX = 20001;
const int INF = 987654321;
vector<pair<int,int>> barns[MAX];
//int dists[MAX] = {0,};
vector<int> dists(MAX,INF);
//int min = INF;
int calc_d(int start, int N)
{
  pq.push(make_pair(0,start));
  //vector<int> dists(INF, N);
  int minimi = 0;
  dists[start] = 0;
  for(int i=start+1;i<N;i++)
    {
      dists[i] = INF;
    }
  while(!pq.empty())
    {
      int dist = pq.top().first;
      int now = pq.top().second;
      pq.pop();
      if(dists[now] < dist)
        continue;
      for(int i=0;i<barns[now].size();i++)
        {
          int cost = dist+barns[now][i].second;
          int going = barns[now][i].first;
          //cout<<cost<<' '<<going<<endl;
          if(dists[going] > cost)
          {
            dists[going] = cost;
            pq.push(make_pair(cost,going));
            minimi = max(minimi,cost);
          }

          
        }
      
    }
  return minimi;
  //return dists;
}
int main() {
  int N,M;
  cin>>N>>M;
  //vector<int> dists(INF,N+1);
  for(int i=0;i<M;i++)
    {
      int a,b;
      cin>>a>>b;
      barns[a].push_back(make_pair(b,1));
      barns[b].push_back(make_pair(a,1));
      //양방향 통로
    }
  int mini= calc_d(1,N+1);
  //vector<int> dists = calc_d(1,N+1);
  //int mini = *max_element(dists.begin() +1 , dists.begin() + N+1);
  int first;
  int number = 0;
  bool flag = false;
  for(int i=2;i<N+1;i++)
    {
      if(dists[i] ==mini)
      {
      if(!flag)
      {
        first = i;
        flag = true;
        number++;
      }
      else
      {
        number++;
      }
      }
    }
  cout<<first<<' '<<mini<<' '<<number<<endl;
}