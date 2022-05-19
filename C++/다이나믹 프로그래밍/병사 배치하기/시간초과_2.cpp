#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> soldiers;
vector<pair<vector<int>,int>> rmved_s;
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
*/
bool inc_chk(vector<int> a, vector<int> b)
{
    int idx = 0;
  //int size = 0;
  if(a==b)
  {
    return true;
  }
else
{
        for(int j=0;j<b.size();j++)
          {
            if(idx < a.size() &&a[idx] == b[j])
            {
              idx++;
              //a,b 무조건 오름차순 인덱스
              //j다 볼때 idx가 a size면 포함되어있는거 
              //포함되어 있을 경우 굳이 볼필요 없음 -최적의 결과 존재 
            }
          }
  }
  if(idx == a.size())
    return true;
  return false;
}
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
  if(rmved_s.size() != 0)
  {
    for(int i=0;i<rmved_s.size();i++)
      {
        if(idxes.size() <= rmved_s[i].first.size())
        {
          if (inc_chk(idxes,rmved_s[i].first))
            return rmved_s[i].second;
          //return rmved_s[i].second;
        }
      //이미 해본 인덱스에 인덱스가 포함될경우 체크 안함
      }
  }
  if(idxes.size() == 0 )
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
    rmved_s.push_back(make_pair(idxes,result));
  }
  return result;
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
    }
  cout<<soldiers.size()-calc(soldiers)<<endl;
}