#include <iostream>
#include <vector>
using namespace std;
/*
  램프
  각 칸마다 -> 램프 직사각형 탁자
  스위치 K번 눌러서
켜져있는 행 최대
  세번 이상 -> 한번과 동일
*/
int main() {
  int n,m;
  vector<vector<int>> lamps(n,vector<int>(m,0));
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      cin>>lamps[i][j];
  int num;
  cin>>num;
  
}