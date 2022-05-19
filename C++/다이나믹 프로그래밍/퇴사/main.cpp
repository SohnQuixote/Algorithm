#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
  다이나믹 - 저장하고 사용 - 중복 계산하지 않기 위해
  퇴사
  N+1일 퇴사
  N일 동안 많은 상담    
  schedules first -> 걸리는 일자 second -> 얻을 수 있는 이익
  결과 - 최대 이익
  91%오답
*/
vector<pair<int,int>> schedules;
vector<int> max_bene;
int calc(vector<pair<int,int>> sche , int N)
{
  //최대 이득은 -1로 채워져서 초기화됐음
  int max_value = -1;
  for(int i=1;i<N+1;i++) // 1부터 N까지
    {
     if(sche[i].first + i <= N+1)
     {
        max_bene[i] = max(max_bene[i],sche[i].second);
       //이날 업무 수행가능
       //cout<<"init:: "<<i<<' '<<max_bene[i]<<endl<<endl;
       for(int k= sche[i].first+i;k<N+1;k++)
         {
           //cout<<i<<':'<<k<<' '<<max_bene[k]<<endl;
          if(sche[k].first+k <= N+1)
          {
            max_bene[k] = max(max_bene[k],sche[k].second+max_bene[i]);
            //이날 업무하고 나머지도 수행
          }
           
         }
     }
    }
  //for(int i=0;i<max_bene.size();i++)
    //cout<<max_bene[i]<<endl;
  max_value = *max_element(max_bene.begin(),max_bene.end());
  if(max_value == -1)
  {
    return 0;
    //이것때문에 틀렸음
    //아예 벌지 못하는 테스트 케이스를 생각 못함
  }
  return max_value;
}
int main() {
  int N;
  cin>>N;
  schedules.push_back(make_pair(1,1));
  max_bene.push_back(-1);
  for(int i=0;i<N;i++)
    {
      int l_tmp,r_tmp;
      cin>>l_tmp>>r_tmp;
      schedules.push_back(make_pair(l_tmp,r_tmp));
      max_bene.push_back(-1);
    }
  cout<<calc(schedules,N)<<endl;
}