#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
  램프
  각 칸마다 -> 램프 직사각형 탁자
  스위치 K번 눌러서
켜져있는 행 최대
  세번 이상 -> 한번과 동일
  무조건 k번 눌러야함
  최대 1000번이라서 일단 구현해봄
  모든 경우의 수 2^50
  모르겠어서 참고
  재귀나 다이나믹도 무조건 안됨
  수학적으로 접근 -꺼져있는 각 행의 전구의 수 -홀 -> k의 수도 홀 && 
  k가 꺼져있는 전구의 수보다 커야됨
*/
const int NINF = -987654321;
int result = NINF;
int n, m;
void print_ramp(vector<vector<int>> r , int k)
{
  cout<<k<<"th Switching Remained::"<<endl;
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
        {
          cout<<r[i][j]<<' ';
        }
      cout<<endl;
      
    }
  cout<<endl;
}
void turn_off(vector<vector<int>> &ramp, int c) {
  for (int i = 0; i < n; i++) {
    ramp[i][c] = !ramp[i][c];
  }
}
int accum(vector<vector<int>> ramp) {
  int a_result = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt = 0;
    for (int j = 0; j < m; j++) {
      cnt += ramp[i][j];
    }
    if (cnt == m)
      a_result++;
  }
  return a_result;
}

// void calc(vector<vector<int>> ramp, int k) {
//   vector<vector<int>> orig = ramp;
//   // print_ramp(ramp,k);
//   if (k == 0) {
//     result = max(result, accum(ramp));
//     return;
//   }

//   for (int j = 0; j < m; j++) {
//     ramp = orig;
//     turn_off(ramp, j);
//     calc(ramp, k - 1);
//   }
// }
bool same(vector<int> a, vector<int> b,int l)
{
  for(int i=0;i<l;i++)
    {
      if(a[i]!= b[i])
        return false;
    }
  return true;
}
int calc(vector<vector<int>> ramp , int k)
{
  int result =0;
  vector<int>zeros(n,0);
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
        if(ramp[i][j] == 0)
          zeros[i]++;
    }
  for(int i=0;i<n;i++)
    {
      if(zeros[i] <= k && zeros[i] %2 == k%2)
      {
        int cnt = 0;
        for(int j=0;j<n;j++)
          {
            if(same(ramp[i],ramp[j],m)){
              cnt++;
            }
            
          }
        result = max(result,cnt);
      }
      
    }

  
  return result;
}

int main() {
  cin >> n >> m;
  vector<vector<int>> lamps(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++)
    {
      string tmp;
      cin>>tmp;
    for (int j = 0; j < m; j++)
      lamps[i][j] = static_cast<int>(tmp[j] -'0');
    }
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++)
  //     cout << lamps[i][j] << " ";
  //   cout << endl;
  // }
  int num;
  cin >> num;
  cout<<calc(lamps,num)<<'\n';
}