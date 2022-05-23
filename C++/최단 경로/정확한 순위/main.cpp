#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
  정확한 순위
  N개 성적 분실후 성적 비교 결과 일부
  성적 순위 알수 있는 학생 수
  플로이드 워셜 사용하여 자신을 제외한 모든 학생 으로부터 갈 수 있으면 순위를 알 수 있는 학생
  학생 수 n 비교 수 m
  무방향 그래프로 한뒤 다익스트라 시도
  다익스트라를 하여 높은 사람 낮은 사람 수의 합이 n-1일 경우 순위 알 수 있는 것
*/
const int MAX = 501;
const int INF = 987654321;
vector<pair<int,int>> graph[MAX];
priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
vector<pair<int,int>> ranks;
vector<vector<int>> total_dist;
int n,m;
//학생마다 높고 낮은것 판별 -> first 높은 사람 수 second 낮은 사람 수
//높은 것은 단방향으로 할 경우 판별 가능 낮은 것은 판별해 다른 점에서 판별해 줘야함(안겹치게 가능?)
void r_d(int start)
{
  //모든 학생 시작점
  //가는 것은 first에 ++
  //오는 것은 다른 학생이 해당 second에 누적해서 ++
vector<int> distances(MAX,INF);
  pq.push(make_pair(0,start));
distances[start] = 0;
//거리가 의미가 있나?
  //최단경로를 해서 중복 없앰?
while(!pq.empty())
  {
    pair<int,int> information;
    information = pq.top();
    pq.pop();
    int now = information.second;
    int dist = information.first;
    if(distances[now]<dist)
      continue;
    //ranks[now].first = graph[now].size();//바로 갈 수 있는 선
    //거쳐서 갈 수 있는 선도 넣어야함(백트래킹?)
    for(int i=0;i<graph[now].size();i++)
      {
        int cost = dist+graph[now][i].second;
        
        //cout<<"시작 과 끝"<<now+1<<' '<<graph[now][i].first+1<<' '<<cost<<endl;
        if(cost<distances[graph[now][i].first])
        {
            distances[graph[now][i].first] = cost;
            pq.push(make_pair(cost,graph[now][i].first));
            //ranks[now].first++; //가는 거니까 높음
          //자신보다 낮은 것 + 자신
          //중복해서 연산함
          //낮은 것만 저장
          //높은것은 자신의 size임
          //ranks[start].first +=1;
          //해당 학생보다 높은 학생 총 수
        }
          
      }
  }
  
  for(int i=0;i<n;i++)
      {
        //높은 학생 해결
        //갈수 있는 경로 점의 수 저장
        //cout<<start+1<<' '<<i+1<<' '<<distances[i]<<endl;
        if(distances[i]<INF && i != start)
        {
          ranks[start].first++;
        }
      }
  total_dist.push_back(distances);
  //행을 보고 높은 사람
  //해당 열을 보고 낮은 사람
}
int main() {
  cin>>n>>m;
  int result = 0;
  for(int i=0;i<n;i++)
    {
      ranks.push_back(make_pair(0,0));
    }
  for(int i=0;i<m;i++)
    {
      int a,b;
      cin>>a>>b;
      graph[a-1].push_back(make_pair(b-1,1));
      //graph[b].push_back(make_pair(a,1));
      //양방향 그래프
    }
  for(int i=0;i<n;i++)
    {
      r_d(i);
      //모든 시작지마다 최단 경로로 탐색
      //갈때는 높다
      //가는 학생은 자신보다 낮은 사람 + 자신 
    }
  for(int c=0;c<n;c++)
    {
      for(int r=0;r<n;r++)
        {
          //열을 보고 올 수 있다는 것은 해당 학생보다 낮다는 뜻
          if(total_dist[r][c] <INF && c!=r)
          {
            ranks[c].second++;
          }
        }
    }
  for(int i=0;i<n;i++)
    {
      //cout<<i+1<<' '<<ranks[i].first<<' '<<ranks[i].second<<endl;
      if((ranks[i].first + ranks[i].second) == n-1)
      {
        result++;
      }
    }
    cout<<result<<endl;
}