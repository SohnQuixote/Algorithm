#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
/*
  스타트와 링크
  축구 모인 사람 짝수 N명
  스타트팀 링크팀 나누기
  스타트팀 링크팀 능력치 차이 최소
  브루트 -> 최대 20C10
  187456 -> 브루트 가능
*/
vector<vector<int>>members(20,vector<int>(20,0));
const int INF = 987654321;
int calc(vector<int> a, vector<int> b)
{
  int a_power = 0;
  int b_power = 0;
  int team_size = a.size();
  for(int i=0;i<team_size;i++)
    {
      for(int j=0;j<team_size;j++)
        {
          if(i!=j)
          {
            int a_mem_1 = a[i];
            int a_mem_2 = a[j];
            int b_mem_1 = b[i];
            int b_mem_2 = b[j];
            a_power += members[a_mem_1][a_mem_2];
            b_power += members[b_mem_1][b_mem_2];
            
          }

          
        }

      
    }
  return abs(a_power-b_power);
}
int main() {
  int N;
  int result = INF;
  cin>>N;
  vector<int> comb;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          cin>>members[i][j];
        }
      
    }
  for(int i=0;i<N;i++)
    comb.push_back(0);
  for(int i=0;i<N/2;i++)
    comb[i] = 1;
  sort(comb.begin(),comb.end());
  do{
    vector<int>a_team;
    vector<int>b_team;
    for(int i=0;i<comb.size();i++)
      {
        if(comb[i] == 0)
          a_team.push_back(i);
        else
          b_team.push_back(i);
        
      }
    
    result = min(result, calc(a_team,b_team));
  }while(next_permutation(comb.begin(),comb.end()));
  cout<<result<<endl;
}