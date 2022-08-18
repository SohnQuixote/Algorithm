#include <iostream>
#include <vector>
using namespace std;
/*
  RGB 거리
  집 N개
*/
int n;
int arr[1000][3] = {0,};
int dp[1000][3] = {0,};


int main() {
  cin>>n;
  for(int i=0;i<n;i++)
    {
      cin>>arr[i][0]>>arr[i][1]>>arr[i][2];  
    }
    for(int i=0;i<3;i++)
      dp[0][i] = arr[0][i];

  for(int i=1;i<n;i++)
    {
      for(int j=0;j<3;j++)
        {
            if(j==0)
            {
              dp[i][j] = min(dp[i-1][1], dp[i-1][2]) + arr[i][j];
            }
            else if(j==1)
            {
              dp[i][j] = min(dp[i-1][0], dp[i-1][2]) + arr[i][j];
            }
            else
            {
              dp[i][j] = min(dp[i-1][1], dp[i-1][0]) + arr[i][j];
            }




          
        }



      
    }
    int min_val = 1987654321;
    for(int i=0;i<3;i++)
      {
        min_val = min(dp[n-1][i],min_val);
        
      }
    cout<<min_val<<'\n';
  
  
    
  
  
}