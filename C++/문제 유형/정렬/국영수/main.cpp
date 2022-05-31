#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
/*
  국영수
  
*/
struct SCORES
{
  string name;
  int kor,eng,math;
};
static bool cmp(SCORES v1, SCORES v2)
{
  //0 - 이름 1 - 국어 2 - 영어 3 -  수학
  if(v1.kor > v2.kor)
  {
    return true;
  }
  else if(v1.kor == v2.kor)
  {
    if(v1.eng < v2.eng)
    {
      return true;
    }
    else if(v1.eng == v2.eng)
    {
        if(v1.math > v2.math)
        {
          return true;
        }
        else if(v1.math == v2.math)
        {
          if(v1.name < v2.name)
          {
            return true;
          }
          return false;
        }
        return false;
    }
    return false;
  }
  return false;
}
int main() {
  //std::cout << "Hello World!\n";
  int N;
  cin>>N;
  vector<SCORES> sco(N);
  for(int i=0;i<N;i++)
    {
      cin>>sco[i].name>>sco[i].kor>>sco[i].eng>>sco[i].math;
    }
  sort(sco.begin(),sco.end(), cmp);
  for(int i=0;i<N;i++)
    {
      cout<<sco[i].name<<endl;
    }
}