#include <iostream>
#include <vector>

using namespace std;
/*
  다이나믹 - 저장하고 사용 - 중복 계산하지 않기 위해
  퇴사
  N+1일 퇴사
  N일 동안 많은 상담    
  schedules first -> 걸리는 일자 second -> 얻을 수 있는 이익
  결과 - 최대 이익
*/
int calc(vector<pair<int,int>>sche ,int N)
{
  int result = -1;
  //매번 max 갱신할 때 result에 저장
  vector<pair<int,int>>mov_sche = sche;
  for(int i=1;i<=N;i++)
    {
      int possible_day = i+ sche[i].first;
      int accu_pay = mov_sche[i].second;
      for(int k = possible_day;k<=N;k++)
        {
          if((sche[k].first+k) <=N+1)
          {
            mov_sche[k].second = max(mov_sche[k].second , accu_pay+ sche[k].second);
            result = max(result,mov_sche[k].second);
            //수행 가능한 스케줄일 경우
          }
          
          
        }
    }
  return result;
  
}
int main() {
  int N;
  cin>>N;
  vector<pair<int,int>> schedules;
  schedules.push_back(make_pair(1,1));
  for(int i=0;i<N;i++)
    {
      int l_tmp,r_tmp;
      cin>>l_tmp>>r_tmp;
      schedules.push_back(make_pair(l_tmp,r_tmp));
    }
  cout<<calc(schedules,N)<<endl;
}