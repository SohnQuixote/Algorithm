#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> soldiers;
vector<int> dp;
//vector<pair<vector<int>,int>> rmved_s;
/*
  병사 배치하기  
  N명 병사 무작위 나열
  전투력 높은 병사 앞에오도록 내림차순 배치
  정렬이 아니라 특정 인원을 열외시켜서 내림차순으로
  전투력이 아니라 남아있는 병사의 수 최대로 하기위해 열외 병사수
  재귀호출로 해결
  열외된 병사인덱스 결과 저장 -> 재호출 -> 재사용
  다수가 열외되면?
  제거된 인덱스 결과 저장
  그냥 조건 만족안하는거 지우면 안되나?
  가장 긴 감소하는 부분 수열
  그냥 브루트 포스하면 무조건 시간초과뜸
  LIS 알고리즘 참고
  최장 감소 수열
*/
int calc(int N)
{
  for(int i=1;i<N;i++)
    {
      for(int j=0;j<i;j++)
        {
          if(soldiers[j]>soldiers[i])
          {
            dp[i] = max(dp[i], dp[j]+1);
          }
        }
    }
  
  return *max_element(dp.begin(),dp.end());
}
int main() {
  cin>>N;

  //0번 인덱스에 결과 저장 저장되있으면 그 결과 사용
  //soldiers.push_back(-1);
  for(int i=0;i<N;i++)
    {
      int temp;
      cin>>temp;
      soldiers.push_back(temp);
      dp.push_back(1);
    }
  cout<<soldiers.size()-calc(N)<<endl;
}