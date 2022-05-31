#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
  일곱난쟁이
  아홉난쟁이 주어짐
  일곱난쟁이 키의 합은 100
  정렬후 DFS 사용?
*/
int smalls[9] = {0,};
bool visited[9];
vector<int> real;
bool flag = false;
void find_small(int height)
{
  if(flag)
    return;
  if(height == 0 && real.size() == 7)
  {
    flag = true;
    for(int i=0;i<7;i++)
      cout<<real[i]<<endl;
    return;
  }
  for(int i=0;i<9;i++)
    {
      if(!visited[i])
      {
        visited[i] = true;
        real.push_back(smalls[i]);
        find_small(height-smalls[i]);
        real.pop_back();
        visited[i]  =false;
        if(flag)
          return;
      }
      
    }

  
}
int main() {
  for(int i=0;i<9;i++)
    {
      cin>>smalls[i];
    }
  sort(smalls,smalls+9);
  find_small(100);
  
}