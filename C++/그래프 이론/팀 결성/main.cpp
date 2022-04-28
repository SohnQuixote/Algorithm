#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
  팀 결성
  학생 0번부터 N번까지 번호 부여 
  처음에는 서로 다른 팀 N+1개 팀
  팀 합치기/ 같은 팀
  서로소 집합 실제 사용
*/
const int MAX = 100001;
int teams[MAX] ={0,};
int find_team(int child);

void union_teams(int child_a,int child_b)
{
  int team_a = find_team(child_a);
  int team_b = find_team(child_b);
  if(team_a<team_b)
    teams[team_b] = team_a;
  else
    teams[team_a] = team_b;
}
int find_team(int child)
{
  if(teams[child] != child)
    teams[child] = find_team(teams[child]);
  return teams[child];
}
int main() {
  int N,M;
  vector<string> find_results;
  cin>>N>>M;
  for(int i=0;i<N+1;i++)
    teams[i] = i;
  for(int i=0;i<M;i++)
    {
      int c,a,b;
      cin>>c>>a>>b;
      switch(c)
        {
          case 0:
          union_teams(a,b);
          break;
          case 1:
          if(find_team(a) == find_team(b))
            find_results.push_back("YES");
          else
            find_results.push_back("NO");
          break;
          default:
          break;
        }
    }
  for(int i=0;i<find_results.size();i++)
    cout<<find_results[i]<<endl;
}