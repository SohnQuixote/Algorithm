#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int N;
  cin>>N;
  int temp = 0;
  vector<int>array;
  for(int i=0;i<N;i++)
    {
      cin>>temp;
      array.push_back(temp);
    }
  sort(array.begin(),array.end(),greater<int>());
  for(int i=0;i<N;i++)
    {
      cout<<array[i]<<' ';
      
    }
}