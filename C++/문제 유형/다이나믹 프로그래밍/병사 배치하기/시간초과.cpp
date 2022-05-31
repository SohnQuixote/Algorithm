#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> soldiers;
/*
  병사 배치하기  
  N명 병사 무작위 나열
  전투력 높은 병사 앞에오도록 내림차순 배치
  정렬이 아니라 특정 인원을 열외시켜서 내림차순으로
  전투력이 아니라 남아있는 병사의 수 최대로 하기위해 열외 병사수
  재귀호출로 해결 
*/
vector<int> chk(vector<int> t)
{
  vector<int> result;
  //bool result = true;
  for(int i=0;i<t.size()-1;i++)
    {
      if(t[i]<= t[i+1])
        result.push_back(i);
    }
  return result;
}
int calc(vector<int> sol)
{
  //vector<int> tmp_sol = sol;
  vector<int> idxes;
  int result =0;
  //내림 차순 쳌
  //최대크기를 받아서 원래 크기에서 빼기
  idxes = chk(sol);
  if(idxes.size() == 0)
  {
    return sol.size();
  }
  else{
    for(int i=0;i<idxes.size();i++)
      {
        //cout<<idxes[i]<<endl;
        vector<int> tmp_sol = sol;
        tmp_sol.erase(tmp_sol.begin()+idxes[i]);
        result = max(result,calc(tmp_sol));
      }
    
  }
  return result;
}
int main() {
  cin>>N;
  for(int i=0;i<N;i++)
    {
      int temp;
      cin>>temp;
      soldiers.push_back(temp);
    }
  cout<<soldiers.size()-calc(soldiers)<<endl;
}