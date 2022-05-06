#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
  특정 거리의 도시 찾기
  1~N 도시
  M개 도로 거리 1
  X로 출발해서 도달 모든 도시 거리 K 번호 출력
  BFS를 사용해서 depth에 맞게 탐색해서 해당 depth에 모든 원소 출력
*/
const int MAX = 300001;
bool visited[MAX];
vector<int> cities[MAX];
queue<pair<int,int>> result_q;
vector<pair<int,int>> results;
void bfs(int X,int K){
  result_q.push(make_pair(0,X));
  results.push_back(make_pair(0,X));
  visited[X] = true;
  //int count =0;
  while(!result_q.empty())
    {
      int dist = result_q.front().first;
      int temp = result_q.front().second;
      if(dist>K)
        return;
      result_q.pop();
      for(int i=0;i<cities[temp].size();i++)
        {
          int y = cities[temp][i];
          if(!visited[y])
          {
            result_q.push(make_pair(dist+1,y));
            results.push_back(make_pair(dist+1,y));
            visited[y] = true;
          }
        }
    }
}
int main() {
  vector<int>result;
  int N,M,K,X;
  cin>>N>>M>>K>>X;
  for(int i=0;i<M;i++)
    {
      int A,B;
      cin>>A>>B;
      cities[A].push_back(B);
    }
  bfs(X,K);
  for(int i=0;i<results.size();i++)
    {
      if(results[i].first == K)
      {
        result.push_back(results[i].second);
      }
    }
  if(result.size() == 0){
    cout<<-1<<endl;
    return 0 ;
  }
  sort(result.begin(),result.end());
  for(int i=0;i<result.size();i++)
    cout<<result[i]<<endl;
}