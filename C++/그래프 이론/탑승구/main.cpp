#include <iostream>
#include <vector>
using namespace std;
/*
  탑승구
  공항 G개 탑승구
  P개 비행기 차례대로 도착
  1부터 비행기 입력받은 값 탑승구까지 영구적으로 도킹
  최대한 많은 비행기 도킹하려함
  최대 몇대 출력
  서로소 집합?
  그냥 배열두고 그리디하게 해결 불가능? -> 가능해 보임
  그리디 한번 구현
  왼쪽에 있는 것과 부모 합치면 서로소 집합으로도 해결가능
  
*/
const int MAX = 100001;
int parents[MAX] = {0,};
int find_p(int a)
{
  if(parents[a] != a)
    parents[a] = find_p(parents[a]);
  return parents[a];
}
void union_p(int c_a,int c_b)
{
  int p_a = find_p(c_a);
  int p_b = find_p(c_b);
  if(p_a<p_b)
    parents[p_b] = p_a;
  else
    parents[p_a] = p_b;
  //find하면서 패런트 동일되기에 맨 위에있는 패런트만 변경해도 충분
}
int main() {
  int G,P; 
  cin>>G>>P;
  vector<int> plane;
  for(int i=0;i<G+1;i++)
    {
      parents[i] = i;
    }
  for(int i=0;i<P;i++)
    {
      int temp;
      cin>>temp;
      plane.push_back(temp);
    }
  int result = 0;
  for(int i=0;i<P ;i++)
    {
      int data = parents[plane[i]];
      if(data != 0)
      {
        result++;
        union_p(data,data-1);
      }
      else{
        break;
      }
      } 
  cout<<result<<endl;
}