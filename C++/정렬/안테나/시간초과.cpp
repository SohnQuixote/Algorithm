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
int calc_dist_anth(int idx,vector<int>houses)
{
  int result = 0;
  for(int i=0;i<houses.size();i++)
    {
      result += abs(idx- houses[i]);
    }
  return result;
}
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
  int idx;
  for(int i=0;i<N;i++)
    {
      int pre_result = result;
      result = min(result,calc_dist_anth(houses[i],houses));
      if(result != pre_result)
      {
         idx = houses[i]; 
      }
    }
    cout<<idx<<endl;
}