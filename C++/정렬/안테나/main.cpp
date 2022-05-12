#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int INF = 987654321;
/*
  안테나
  정렬 + 조합 사용
  안테나 하나임 - brute force go
*/
int main() {
  int N;
  cin>>N;
  vector<int> houses;
  int result = INF;
  int temp;
  for(int i=0;i<N;i++)
    {
      cin>>temp;
      houses.push_back(temp);
    }
  sort(houses.begin(),houses.end());
  cout<<houses[(N-1)/2]<<endl;
}