#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
  팬미팅
  M명 팬들 맨 오른쪽 멤버에서 한명씩 왼쪽 이동하며 포옹
  모든 팬 동시에 한명
  남성 멤버 -> 악수
  모든 멤버 동시 포옹 몇번
  브루트 포스 -> 직접 포옹 시뮬레이션 -> 비효율
  배열간 곰셈으로 구현
  팬수 20만
  최대 연산 횟수 20만
  여자 0
  남자 1
  
  허그 경우의 수 멤버 여자 (남자, 여자)/ 멤버 남자 (여자)
  and연산 0일 경우 안음    
*/
vector<int> members_vec;
vector<int> fans_vec;
bool all_hug(vector<int> tmp_members,int start,int members_num)
{  
  int hug = 0;
  for(int i=start;i<start+members_num;i++)
    {
      if((tmp_members[i] && fans_vec[i]) == 0)
      {
        hug+=1;
      }
    }
  if(hug == members_num)
    return true;
  else
    return false;
}
int calc()
{
  int result =0;
  int members_num = members_vec.size();
  int fans_num = fans_vec.size();
  
    for(int i=0;i<=fans_num - members_num;i++)
    {
      vector<int> tmp_members(fans_vec.size(),0);
      for(int j=0;j<members_num;j++)
        {
          tmp_members[i+j] = members_vec[j];
        }
      if(all_hug(tmp_members,i,members_num))
        result++;
    }
  return result;
}
int main() {
  string members;
  string fans;
  getline(cin,members);
  getline(cin,fans);
  for(int i=0;i<members.size();i++)
    {
      if(members[i] == 'F')
        members_vec.push_back(0);
      else
        members_vec.push_back(1);
    }
  for(int i=0;i<fans.size();i++)
    {
      if(fans[i] == 'F')
        fans_vec.push_back(0);
      else
        fans_vec.push_back(1);
    }
  cout<<calc()<<endl;
}