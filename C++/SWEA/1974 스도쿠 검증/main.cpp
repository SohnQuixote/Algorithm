#include <iostream>
#include <vector>
using namespace std;
/*
  스도쿠 검증

*/

int calc(vector<vector<int>> sudo)
{
  int result = 1;
  for(int r=0;r<9;r+=3)
    {
    for(int c=0;c<9;c+=3)
      {
        vector<int>visited(10,0);
        for(int i=0;i<3;i++)
          {
            for(int j=0;j<3;j++)
              {
                visited[sudo[i+r][j+c]]++;
                if(visited[sudo[i+r][j+c]] >1)
                  return 0;
                
              }
            
          }
        
      }
    }
  for(int r=0;r<9;r++)
    {
      vector<int> row_visited(10,0);
      vector<int> col_visited(10,0);
      for(int c=0;c<9;c++)
        {

          row_visited[sudo[r][c]]++;
          col_visited[sudo[c][r]]++;
          if(row_visited[sudo[r][c]]>1)
            return 0;
          if(col_visited[sudo[c][r]] > 1)
            return 0;

          
        }

      
    }
  return result;
}
int main() {
  vector<int> results;
  int T;
  cin>>T;
  vector<vector<int>> grid(9,vector<int>(9,0));
  for(int i=0;i<T;i++)
    {
      for(int r=0;r<9;r++)
        for(int c=0;c<9;c++)
          cin>>grid[r][c];
      results.push_back(calc(grid));
    }
    for(int i=0;i<T;i++)
    {
      cout<<"#"<<i+1<<' '<<results[i]<<endl;
    }
  
}