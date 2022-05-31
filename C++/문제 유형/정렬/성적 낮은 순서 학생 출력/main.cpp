#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*
  N명의 학생정보 
  입력 - 학생의 이름 성적
  학생 이름 성적 낮은 순서대로 출력
  vector <pair>로 해결
  계수 정렬을 사용
*/
vector<string> possible_score[101];
void calc(vector<pair<string,int>>score, int N)
{
  for(int i=0;i<N;i++)
    {
      possible_score[score[i].second].push_back(score[i].first);
    }
  for(int i=0;i<=100;i++)
    {
      for(int j=0;j<possible_score[i].size();j++)
        {
          cout<<possible_score[i][j]<<' ';
        }
      
    }
  
}
int main() {
  int N;
  vector<pair<string,int>>score;
  string temp_1;
  int temp_2;
  cin>>N;
  for(int i=0;i<N;i++)
    {
      cin>>temp_1>>temp_2;
      score.push_back(make_pair(temp_1,temp_2));
    }
  calc(score,N);
}