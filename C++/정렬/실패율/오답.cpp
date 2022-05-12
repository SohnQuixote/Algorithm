#include <iostream>


#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
    실패율
    도달 클리어 못한 플레이어 수 / 도달 플레이어 수
    스테이지 개수 N
    플레이어 스테이지 번호 stages
    실패율 높은 스테이지 내림 차순 배열 return 
*/
static bool comp(pair<double,int> a , pair<double,int> b)
{
    if(a.first>b.first)
    {
        return false;
    }
    return a.second<b.second;
}
vector<int> solution(int N, vector<int> stages) {
    vector<pair<double,int>> fail_rate; //비교 함수로 정렬
    vector<int> answer;
    sort(stages.begin(),stages.end()); // 낮은 수부터 나오게 됨
    int tmp_size = stages.size();
    int first_stage = stages[0];
    for(int i=1;i<first_stage;i++) //모두가 클리어한 스테이지
    {
        fail_rate.push_back(make_pair(0,i));
    }
    int reduced_people = 0;
    for(int i=1;i<stages.size() + 1;i++)
    {
        if(i == stages.size() && stages[i-1] != N+1)
        {
            first_stage = stages[i-1];
            fail_rate.push_back(make_pair(1,first_stage));
            while(first_stage<N+1)
            {
                fail_rate.push_back(make_pair(0,++first_stage));
            }
        }
        while(stages[i] != first_stage && i !=stages.size())
        {
            first_stage++;
            double temp = static_cast<double>(i-reduced_people)/static_cast<double>(tmp_size - reduced_people);
            reduced_people = i;
            fail_rate.push_back(make_pair(temp,first_stage-1));
        }
    }
    sort(fail_rate.begin(),fail_rate.end(),comp);
    for(int i=0;i<fail_rate.size();i++)
    {
        answer.push_back(fail_rate[i].second);
    }
    return answer;
}
int main() {
  int N = 5;
  vector<int> stages = {2,1,2,6,2,4,3,3};
  vector<int> result = solution(N,stages);
}