#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
  S에서 시작 T에서 끝나는 N개 수업
  최소의 강의실을 사용
  Ti 이후 Sj면 강의실을 그대로 사용해도 가능
  끝나는 시간을 저장해놔야함
  S,T 범위 10^9이라서 벡터로 가능한 룸 다 하는건 불가능
*/
#define MAX 200001
pair<int,int> schedule[MAX];
vector<int> rooms;
int main() {
  int N;
  cin>>N;
  for (int i=0;i<N;i++)
    {
      cin>>schedule[i].first>>schedule[i].second;
    }
  sort(schedule,schedule+N);
  rooms.push_back(schedule[0].second);
  for(int i=1;i<N;i++)
    {
      for(int j=0;j<rooms.size();j++)
        {
          if(rooms[j]<=schedule[i].first)
          {
            rooms[j] = schedule[i].second;
            break;
          }
          else if(rooms[j]>schedule[i].first)
          {
            rooms.push_back(schedule[i].second);
            break;
          }
        }
    }
  cout<<rooms.size()<<endl;
}