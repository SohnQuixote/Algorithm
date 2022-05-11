#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
/*
  국영수
  
*/
static bool CmpName(tuple<string,int,int,int> &v1 , tuple<string,int,int,int> &v2)
{
  //0 - 이름 1 - 국어 2 - 영어 3 -  수학
  if(get<1>(v1) > get<1>(v2))
  {
    return true;
  }
  else if(get<1>(v1) == get<1>(v2))
  {
    if(get<2>(v1) < get<2>(v2))
    {
      return true;
    }
    else if(get<2>(v1) == get<2>(v2))
    {
        if(get<3>(v1) > get<3>(v2))
        {
          return true;
        }
        else if(get<3>(v1) == get<3>(v2))
        {
          if(get<0>(v1) < get<0>(v2))
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
  vector<tuple<string,int,int,int>> scores;
  int N;
  cin>>N;
  string name;
  int korea,english,math;
  for(int i=0;i<N;i++)
    {
      cin>>name>>korea>>english>>math;
      scores.push_back(make_tuple(name,korea,english,math));
    }
  sort(scores.begin(),scores.end(), CmpName);
  for(int i=0;i<N;i++)
    {
      cout<<get<0>(scores[i])<<endl;
    }
}