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
vector<bool> visited;
//재귀로 해야됨
int calc_bi(int start, int end, int mini)
{
  //이진으로 가장 범위 큰거(그리디) 고르고 visited true 바꿈 -> 이진 탐색
  //처음 1~N-1
  int mid = static_cast<int>((start+end)/2);
  int tmp_mini = mini;
  //int mini = 987654321;
  for(int i=0;i<results.size();i++)
    {
      mini = min(mini,abs(results[i] - houses[mid]));
    }
  mini = calc_bi(start,mid-1,mini);
  mini = calc_bi(start,)
  //최소 길이 가장 커야함
  if(tmp_mini!= mini)
  {
    return mid;
  }
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
      visited.push_back(false);
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
    for(int i=1;i<=C-2;i++)
      {
        
      }
    
  }
  //조합? 200,000 C 200,000 -> 시간초과 뜰거 같음 -> brute force
}