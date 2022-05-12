#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 100001;
vector<pair<int,int>> h;
//const int INF = 1987654321;
/*
  안테나
  정렬 + 조합 사용
  안테나 하나임 - brute force go
*/
bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first > b.first;
	}
}
long long calc_dist_anth(int idx,vector<pair<int,int>>houses,int h_size)
{
  long long result = 0;
  int start = houses[idx].second;
  //cout<<start<<endl;
  for(int i=0;i<h_size;i++)
    {
      result+=static_cast<long long>(abs(start -houses[i].second) * houses[i].first);
    }
  return result;
}
int main() {
  int N;
  cin>>N;
  long long result;
  int temp;
  //int lst_idx;
  vector<int> tmp_h(MAX);
  int h_size = 0;
  for(int i=0;i<MAX;i++)
    tmp_h[i] = 0;
  for(int i=0;i<N;i++)
    {
      cin>>temp;
      tmp_h[temp] +=1;
      result+= static_cast<long long>(temp);
      //idx -> 집 위치 값 -> 집 수
    }
    for(int i=0;i<MAX;i++)
      {
        if(tmp_h[i] != 0)
        {
          h.push_back(make_pair(tmp_h[i],i));
          h_size +=1;
        }
      }
  sort(h.begin(),h.end(),compare); //집의 수가 많은 것 부터
  //for(int i=0;i<h.size();i++)
    //cout<<h[i].first<<' '<<h[i].second<<endl;
  int good_h;
  for(int i=0;i<h_size;i++)
    {
      //cout<<result<<endl;
      long long pre_result = result;
      result = min(result,calc_dist_anth(i,h,h_size));
      if(pre_result != result)
      {
        good_h = h[i].second;
      }
    }
  cout<<good_h<<endl;
}