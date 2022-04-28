#include <iostream>
#include <queue>
#include <vector>

using namespace std;
/*
  커리큘럼
  N개 강의 (1번부터 N번) 
  1번부터 N번강의까지 수강하는데 걸리는 최소시간 각각 출력
  위상 정렬
  1번부터 N번까지 모두 저장해야함
  모든 선수 과목이 다 명시되어있는 경우도 있고 안되있는 경우도 있음
*/
const int MAX = 501;
int prevs[MAX] = {0,};
//int results[MAX] = {0,};
int lecture_time[MAX] = {0,};
vector<pair<int,int>>lectures[MAX];
void calc(int N)
{
  queue<int>q;
  for(int i=1;i<N+1;i++)
    {
      if(prevs[i] == 0)
        q.push(i);
    }
  while(!q.empty())
    {
      int now = q.front();
      q.pop();
      
      for(int i=0;i<lectures[now].size();i++)
        {
          int aft,time;
          time = lectures[now][i].first;
          aft = lectures[now][i].second;
          prevs[aft]-=1;
          lecture_time[aft] += time;
          if(prevs[aft] == 0)
            q.push(aft);
          
        }
      
    }
  for(int i=1;i<N+1;i++)
    cout<<lecture_time[i]<<endl;
  
}
int main() {
  int N;
  cin>>N;
  for(int i=1;i<N+1;i++)
    {
      int time;
      cin>>time;
      lecture_time[i] = time;
      int temp;
      do{
        cin>>temp;
        if(temp == -1)
          break;
        lectures[temp].push_back(make_pair(lecture_time[temp],i));
        prevs[i]+=1;
      }while(temp!=-1);
    }
  calc(N);
}