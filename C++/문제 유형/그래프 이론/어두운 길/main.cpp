#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
/*
  어두운 길
  한 마을 N개 집 M개 도로
  각 집 0~N-1
  일부 가로등 비활성화 
  최소 비용 신장트리 사용
  무방향 그래프 -> tuple 사용
*/
const int MAX = 200001;
int parents[MAX] = {0,};
vector<tuple<int,int,int>> houses;
int find_p(int a)
{
  if(parents[a] != a)
  {
    parents[a] = find_p(parents[a]);
  }
  return parents[a];
}
void union_p(int a,int b)
{
  a = find_p(a);
  b = find_p(b);
  //낮은 것을 부모로 삼음 
  if(b>a)
    parents[b] = a;
  else
    parents[a] = b;
}
int main() {
  int N,M;
  cin>>N>>M;
  for(int i=0;i<N;i++)
    {
      parents[i] = i;
    }
  for(int i=0;i<M;i++)
    {
      int a,b,c;
      cin>>a>>b>>c;
      houses.push_back(make_tuple(c,a,b));
      
    }
    //정렬후 최소 비용 신장트리 구축
    sort(houses.begin(),houses.end());
  int result = 0;
  for(int i=0;i<M;i++)
    {
            
      
      int c = get<0>(houses[i]);
      int a = get<1>(houses[i]);
      int b = get<2>(houses[i]);
      result+=c;
      //cout<<c<<' '<<a<<' '<<b<<endl;
    }
  
  //해당 금액이 아닌 절약할 최대거리
  
  for(int i=0;i<M;i++)
    {
      int c = get<0>(houses[i]);
      int a = get<1>(houses[i]);
      int b = get<2>(houses[i]);
      if(find_p(a) != find_p(b))
      {
        union_p(a,b);
        result-=c;
        //부모가 같으면 루프 발생
        //적은 코스트부터 보기 때문에 최소 비용으로 트리 생성됨 
      }
      
    }
    cout<<result<<endl;
}