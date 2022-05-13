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
    COMP함수 작성할 때 WEAK ORDERING 하지 않기 -> SEG fault 발생
*/
static bool comp(pair<double,int>& a, pair<double, int>& b){
    if(a.first > b.first) 
        return true;
    else if(a.first == b.first)
    {
        return a.second <= b.second;
    } 
    else
    {
        return false;
    }
}
/*static bool comp(pair<double,int> &a , pair<double,int> &b)
{
    if(a.first>b.first)
    {
        return true; //확률
    }
    return a.second<b.second;//인덱스
}*/
vector<int> solution(int N, vector<int> stages) {
    vector<pair<double,int>> fail_rate; //비교 함수로 정렬
    vector<int> answer;
    sort(stages.begin(),stages.end()); // 낮은 수부터 나오게 됨
    //1부터 스테이지 N+1까지 존재 가능
    int first_stage = stages[0]; //
    //1부터 모두가 클리어한 스테이지는 실패율 0으로 해도 됨
    for(int i=1;i<first_stage;i++)
    {
        //처음 스테이지 1이면 그냥 스킵
        //2이면 모두가 1은 깬거임 -> 실패율 0
        fail_rate.push_back(make_pair(0,i));
    }
    int player_num = stages.size();
    int index = 0;
    for(int i=first_stage;i< N+1;i++)
    {
        //처음 스테이지부터 검사
        int stage_player =0;
        for(int j=index;j<stages.size()&&stages[j] == i ;j++)
        {
            stage_player++;
        }
        //stage_player+=1;
        index+=stage_player;
      double rate = 0;
      if(player_num != 0)
      {
       rate = static_cast<double>(stage_player) / static_cast<double>(player_num);
      }
        //cout<<"현재 스테이지: "<<i<<' '<<stage_player<<' '<<player_num<<' '<<rate<<endl;
        player_num -= stage_player;
        fail_rate.push_back(make_pair(rate,i));
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
  vector<int> stages = {4};
  //vector<int>stages = {4,4,4,4};
  vector<int> result = solution(N,stages);
  for(int i=0;i<result.size();i++)
    cout<<result[i]<<endl;
}