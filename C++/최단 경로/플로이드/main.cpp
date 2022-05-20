#include <iostream>
#include <vector>
using namespace std;
const int INF = 987654321;
/*
  플로이드
  n개 도시 한도시 다른 도시 m개 버스
*/
int main() {
  int n,m;
  cin>>n;
  vector<vector<int>> houses = vector<vector<int>>(n,(vector<int>(n,INF)));
  for(int i=0;i<n;i++)
    houses[i][i] = 0;
  cin>>m;
  for(int i=0;i<m;i++)
    {
      int a,b,t;
      cin>>a>>b>>t;
      houses[a-1][b-1] = min(houses[a-1][b-1],t);  
    }
  //cout<<"till"<<endl;
  for(int k = 0;k<n;k++)
    {
      for(int r = 0;r<n;r++)
        {
          for(int c =0;c<n;c++)
            {
              houses[r][c] = min(houses[r][c] , houses[r][k]+houses[k][c]);
              
            }
          
        }
      
    }
    for(int r = 0;r<n;r++)
        {
          for(int c =0;c<n;c++)
            {
              if(houses[r][c] == INF)
                houses[r][c] = 0;
              cout<<houses[r][c]<<' ';
            }  
          cout<<endl;
        }
}