#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000001
pair<int,int> scores[MAX];
/*
  신입 사원
  문제가 이해가 안됨
  점수가 아니라 순위
  많은 문제를 접해서 문제를 빠르게 이해하는 것도 중요
*/
int main() {
  int T;
  cin>>T;
  vector<int> results;
  while(T--)
    {
      int N;
      cin>>N;
      for(int i=0;i<N;i++)
        {
        cin>>scores[i].first>>scores[i].second;
        }
      sort(scores,scores+N);
      int result = 1;
      int second_score = scores[0].second; 
      for(int i=1;i<N;i++)
        {
          if(scores[i].second< second_score)
          {
            result+=1;
            second_score = scores[i].second;            
          }
          
        }
      results.push_back(result);
    }
  for(int i=0;i<results.size();i++)
    {
      cout<<results[i]<<endl;
      
    }
}