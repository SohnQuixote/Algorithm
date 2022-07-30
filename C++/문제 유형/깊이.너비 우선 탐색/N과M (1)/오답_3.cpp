#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
  n과 m
*/
int numbers[8] = {1,2,3,4,5,6,7,8};
int main() {
  int n,m;
  cin>>n>>m;
  vector<int> comb;
  for(int i=0;i<n;i++)
    {
      comb.push_back(0);
    }
  for(int i=0;i<m;i++)
    {
      comb[i] = 1;
    }
  sort(comb.begin(),comb.end());
  vector<vector<int>> results;
  do
    {
      vector<int> tmp;
      tmp.clear();
      for(int i=0;i<n;i++)
        {
          
          if(comb[i] == 1)
          {
            tmp.push_back(numbers[i]);
          }
        }
      results.push_back(tmp);
      //cout<<endl;
      
    }while(next_permutation(comb.begin(),comb.end()));
  sort(results.begin(),results.end());
  for(int i=0;i<results.size();i++)
    {
      for(int j=0;j<m;j++)
        {
          cout<<results[i][j]<<' ';
        }
      cout<<endl;
    }
}