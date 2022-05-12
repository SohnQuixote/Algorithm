#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
/*
  국영수
  점수 1이상 100 이하 -> 계수 정렬 사용
*/
const int MAX = 101;
vector<int> korean_score[MAX]; //->스코어 + 인덱스 - 원소수 두개 - 겹치는 것 - 해당 인덱스 저장후 재 정렬 필요
vector<int> eng_score[MAX];
vector<int> math_score[MAX];
vector<tuple<string,int,int,int>> scores;
vector<string> result;//정렬된 원소 - 넣기
vector<int> calc_string(vector<int> idx)
{
  vector<int> result_idx;
  vector<pair<string,int>> tmp;
  for(int i=0;i<idx.size();i++)
    {
      tmp.push_back(make_pair(get<0>(scores[idx[i]]),idx[i]));
    }
  sort(tmp.begin(),tmp.end());
  for(int i=0;i<tmp.size();i++)
    {
      result_idx.push_back(tmp[i].second);
    }
  return result_idx;
}
vector<int> calc_math(vector<int> idx)
{
  vector<int> result_idx;
  vector<int> tmp_idx;
  for(int i=1;i<MAX;i++)
    {
      math_score[i].clear();
    }
  for(int i=0;i<idx.size();i++)
    {
      int math = get<3>(scores[idx[i]]);
      math_score[math].push_back(idx[i]);
    }
    for(int i=100;i>=1;i--)
      {
      if(math_score[i].size()==1)
      {
        result_idx.push_back(math_score[i][0]);
      }
      else if(math_score[i].size()>=2)
      {
        tmp_idx.clear();
        for(int j=0;j<math_score[i].size();j++)
            {
              tmp_idx.push_back(math_score[i][j]);
            }
          tmp_idx = calc_string(tmp_idx);
          for(int j=0;j<tmp_idx.size();j++)
            {
              result_idx.push_back(tmp_idx[j]);
            }
      }
        
      }
  return result_idx;
}
vector<int> calc_eng(vector<int> idx )
{
  vector<int> result_idx;
  vector<int> tmp_idx;
  for(int i=1;i<MAX;i++)
    {
      eng_score[i].clear();
    }
  for(int i=0;i<idx.size();i++)
    {
      int eng = get<2>(scores[idx[i]]);
      eng_score[eng].push_back(idx[i]);
    }
  for(int i=1;i<=100;i++)
    {
      if(eng_score[i].size()==1)
      {
        result_idx.push_back(eng_score[i][0]);
      }
      else if(eng_score[i].size()>=2)
      {
        tmp_idx.clear();
        for(int j=0;j<eng_score[i].size();j++)
            {
              tmp_idx.push_back(eng_score[i][j]);
            }
          tmp_idx = calc_math(tmp_idx);
          for(int j=0;j<tmp_idx.size();j++)
            {
              result_idx.push_back(tmp_idx[j]);
            }
      }
    }
  return result_idx;
}
void calc( int N)
{
  vector<int> tmp_idx;
  for(int i=0;i<N;i++)
    {
      int korean = get<1>(scores[i]);
      korean_score[korean].push_back(i);
    }
    for(int i=100;i>=1;i--)
      {
        if(korean_score[i].size() == 1)
        {
          result.push_back(get<0>(scores[korean_score[i][0]]));
        }
        else if(korean_score[i].size()>=2) //국어 겹침
        {
          tmp_idx.clear();
          for(int j=0;j<korean_score[i].size();j++)
            {
              tmp_idx.push_back(korean_score[i][j]);
            }
            tmp_idx = calc_eng(tmp_idx);
            for(int j=0;j<tmp_idx.size();j++)
            {
              result.push_back(get<0>(scores[tmp_idx[j]]));
            }
        }
      }
}
int main() {
  //std::cout << "Hello World!\n";
  int N;
  cin>>N;
  string name;
  int korea,english,math;
  for(int i=0;i<N;i++)
    {
      cin>>name>>korea>>english>>math;
      scores.push_back(make_tuple(name,korea,english,math));
    }
  //sort(scores.begin(),scores.end(), CmpName);
  calc(N);
  for(int i=0;i<N;i++)
    {
      cout<<result[i]<<endl;
      //cout<<get<0>(scores[i])<<endl;
    }
}