#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
/*
  공유기 설치
  도현이 집 N개 수직선- 집좌표 x1~xN
  공유기 C개 설치
  한 집에는 공유기 하나
  가장 인접한 공유기 사이 거리 크게 하여 설치
  C개 공유기 N개 집 설치 -> 거리 최대
  C가 2면 그냥 앞뒤에 배치하면 됨
  C가 3이상 -> start mid end?
  start, end 추가하고 2개
  3개부터 mid 추가 ->탐색 mid와 비교해서 범위 큰쪽
  3개 -> 1개 깊이
  4개 -> 2개 깊이
  visited 배열이 필요한가?  
*/
int N,C;
vector<int>results;

vector<int>houses;
//vector<bool> visited;
const int INF = 987654321;
//재귀로 해야됨
pair<int,int> chose(pair<int,int> lef , pair<int,int> orig,pair<int,int>rig)
{
  if(lef.second != INF &&lef.second >orig.second && lef.second > rig.second)
  {
    return lef;
  }
  else if (rig.second != INF && rig.second>lef.second && rig.second > orig.second)
  {
    return rig;
  }
  return orig;
}
pair<int,int> calc_bi(int start, int end)
{
  //cout<<start<<' '<<end<<endl;
  int mid = static_cast<int>((start+end)/2);
  int range = INF;
  pair<int,int> lef_range; //return 한것중 가장 큰거로 인덱스
  pair<int,int> rig_range;
  if(start>end)
  {
    return make_pair(-1,INF); //해당 인덱스 + 거리
  }
  for(int i=0;i<results.size();i++)
    {
      range = min(range,abs(houses[mid]-results[i]));
    }
  //현재
  lef_range = calc_bi(start , mid-1);
  //왼쪽
  rig_range = calc_bi(mid+1,end); 
  //우측
  pair<int,int> result = chose(lef_range, make_pair(mid,range),rig_range);
  //INF아니며 가장 큰거
  return result;
  //lef , rig range 중에서 가장 크며 INF아닌거 선택
}
int main() 
{
  //vector<int> houses;
  cin>>N>>C;
  for(int i=0;i<N;i++)
    {
      int temp;
      cin>>temp;
      houses.push_back(temp);
      //visited.push_back(false);
    }
  sort(houses.begin(),houses.end());
  if(C==2)
  {
    cout<<(houses[N-1] - houses[0])<<endl;
    return 0;
  }
  else
  {
    results.push_back(houses[0]);
    results.push_back(houses[N-1]); //일단 무조건 최대 범위
    houses.erase(houses.begin() + N-1);
    houses.erase(houses.begin());
    //삭제 뒤 나머지 범위에서 범위 최댓값 찾음
    for(int i=1;i<=C-2;i++)
      {
        //cout<<"till good";
        pair<int,int> result = calc_bi(0,houses.size()-1); //가장 범위 큰거 구하고 houses 지우기
        //cout<<result.first<<' '<<result.second<<endl;
        results.push_back(houses[result.first]);
        houses.erase(houses.begin()+result.first);
        //results.push_back(result.second);
      }
    sort(results.begin(),results.end());
    int mini = INF;
    for(int i=0;i<results.size()-1;i++)
      {
        //cout<<results[i+1]<<' '<<results[i]<<endl;
        mini  = min(mini, results[i+1]-results[i]);
      }
    cout<<mini<<endl;
  }
  //조합? 200,000 C 200,000 -> 시간초과 뜰거 같음 -> brute force
}