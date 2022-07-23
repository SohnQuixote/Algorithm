#include <iostream>
#include <vector>
using namespace std;
/*
  램프
  각 칸마다 -> 램프 직사각형 탁자
  스위치 K번 눌러서
켜져있는 행 최대
  세번 이상 -> 한번과 동일
  무조건 k번 눌러야함
  최대 1000번이라서 일단 구현해봄
*/
const int NINF = -987654321;
int result = NINF;
  int n,m;
void turn_off(vector<vector<int>>& ramp , int c)
{
  for(int i=0;i<n;i++)
    {
      ramp[i][c] = !ramp[i][c];
    }
  
}
int accum(vector<vector<int>> ramp)
{
  int result = 0;
  int cnt = 0;
  for(int i=0;i<n;i++)
    {
      cnt = 0;
      for(int j=0;j<m;j++)
        {
          cnt+= ramp[i][j];
        }
      if(cnt == m)
        result++;
    }
  return result;
}

void calc(vector<vector<int>> ramp, int k)
{
  vector<vector<int>> orig = ramp;
  if(k==0)
  {
    result = max(result , accum(ramp));
    return;
  }

  for(int j=0;j<m;j++)
    {
      ramp = orig;
      turn_off(ramp,j);
      calc(ramp,k-1);

      
    }

  
}
int main() {
    cin>>n>>m;
  vector<vector<int>> lamps(n,vector<int>(m,0));

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>lamps[i][j];
  // for(int i=0;i<n;i++)
  //   {
  //     for(int j=0;j<m;j++)
  //       cout<<lamps[i][j]<<" ";
  //     cout<<endl;
      
  //   }
  int num;
  cin>>num;
  // calc(lamps,num);
  cout<<result;
  
}