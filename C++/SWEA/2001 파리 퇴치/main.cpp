#include <iostream>
#include <vector>
using namespace std;

/*
  파리 퇴치
  
*/

int calc(vector<vector<int>> a, int n,int m)
{
  int max_start = n-m;
  int result=-1;
  for(int r=0;r<=max_start;r++)
    {
      for(int c=0;c<=max_start;c++)
        {
          int tmp =0;
          for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
              tmp+=a[i+r][j+c];
          result = max(result,tmp);
          
        }
    }
  return result;
}
int main() {
  int T;
  cin>>T;
  vector<int> results;
  vector<vector<int>>grid(15,vector<int>(15,0));
  for(int i=0;i<T;i++)
    {
      int N,M;
      cin>>N>>M;
      for(int r=0;r<N;r++)
        for(int c=0;c<N;c++)
          cin>>grid[r][c];

    results.push_back(calc(grid,N,M));
      
    }
    for(int i=0;i<T;i++)
    {
      cout<<"#"<<i+1<<' '<<results[i]<<endl;
    }
}