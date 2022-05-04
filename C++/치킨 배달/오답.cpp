#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> //abs
using namespace std;
/*
  치킨 배달
  크기 N*N
  도시 r,c - > [r][c]
  치킨 거리 - 집과 가장 가까운 치킨 거리
  도시 치킨 거리 - 모든 치킨 거리 합
  0 - 빈칸
  1 - 집
  2 - 치킨집 
  치킨집중 M개 골라서 최소 치킨 거리를 구하기
*/
vector<pair<int,int>> houses;
vector<pair<int,int>> chickens;
//집 치킨집 좌표 저장
int calc_min_dist(vector<int> comb,vector<pair<int,int>>houses)
{
  int dist = 0;
  //집기준으로 정해야함
  for(int i=0;i<houses.size();i++)
    {
      int temp = 987654;
      for(int j=0;j<comb.size();j++)
        {
          if(comb[j] == 1)
          {
            int chi_dist = abs(houses[i].first - chickens[j].first) + abs(houses[i].second - chickens[i].second);
            if(temp>chi_dist)
              temp = chi_dist;
            //해당 집의 치킨거리 구했음
          }
        }
      dist+= temp;
    }
  return dist;

  //치킨거리 최솟값 반환
}
const int MAX = 51;
//int maps[MAX][MAX] = {0,};
int main() {
  int N,M;
  cin>>N>>M;
  for(int i=1;i<N+1;i++)
    {
      for(int j=1;j<N+1;j++)
        {
          int temp;
          cin>>temp;
          if(temp == 1)
          {
            houses.push_back(make_pair(i,j));
          }
          else if(temp ==2)
          {
             chickens.push_back(make_pair(i,j)); 
          }
          //좌표 저장
          //maps[i][j] = temp;
        }
    }
  int num_house = houses.size();
  int num_chickens = chickens.size();
  vector<int>comb;
  for(int i=0;i<num_chickens;i++)
    {
      comb.push_back(0);
    }
  for(int i=0;i<M;i++)
    {
      comb[i] = 1;
    }
  sort(comb.begin(),comb.end());
  int result = 987654;
  do{
  //조합 사용
    int temp = 0;
    temp = calc_min_dist(comb,houses);
   if(temp<result)
   {
     result = temp;
   }
  }while(next_permutation(comb.begin(),comb.end()));
  cout<<result<<endl;
}