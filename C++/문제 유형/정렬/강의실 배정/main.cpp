#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
/*
  S에서 시작 T에서 끝나는 N개 수업
  최소의 강의실을 사용
  Ti 이후 Sj면 강의실을 그대로 사용해도 가능
  끝나는 시간을 저장해놔야함
  우선순위 큐를 사용해야 함
  우선순위 큐 : 작은 값이 앞으로 오는 queue
*/
#define MAX 200001
pair<int,int> schedule[MAX];
priority_queue <int, vector<int> , greater<int>> pq;

int main() {
  int N;
  cin>>N;
  for (int i=0;i<N;i++)
    {
      cin>>schedule[i].first>>schedule[i].second;
    }
  sort(schedule,schedule+N);
  pq.push(schedule[0].second);
  for(int i=1;i<N;i++)
    {
      pq.push(schedule[i].second);
      if(pq.top()<= schedule[i].first)
      {
        pq.pop();
      }
    }
  cout<<pq.size()<<endl;
}