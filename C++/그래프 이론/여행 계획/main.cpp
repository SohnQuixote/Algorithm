#include <iostream>
#include <vector>
using namespace std;
/*
  여행 계획
  한울이 사는 나라 N개 여행지
  여행지 개수, 연결 정보
  여행 계획 가능한지 판별
  서로소 집합, 신장 트리, 크루스칼 알고리즘, 위상 정렬 알고리즘
  신장 트리?
  경로마다 최소 신장트리 생성? ex. 1->3 3->2각각 만약 생성 안됨-> 불가능 -> 끝까지 생성함 -> 가능 크루스칼 -> 간선 정렬 -> 간선이 같음
  서로소 집합 사용해서 해당 경로가 모두 같은 부모를 가지면 -> 가능
  가지지 않으면 -> 불가능 
*/
const int MAX = 501;
vector<vector<int>> trip(MAX, vector<int>(MAX, 0));
int parents[MAX] = {0,};
bool calc(vector<int> plan, int M)
{
  bool result = true;
  int start_p = parents[plan[0]];
  for(int i=1;i<M;i++)
    {
      if(start_p != parents[plan[i]])
      {
        //하나라도 다르면 못가는 것임
        return false;
      }

      
    }
  return result;
}
int find_p(int trip)
{
  if(parents[trip] != trip)
    parents[trip] = find_p(parents[trip]);
  return parents[trip];
  
}
void union_p(int trip_a,int trip_b)
{
  int parent_a = find_p(trip_a);
  int parent_b = find_p(trip_b);
  if(parent_a<parent_b)
    parents[trip_b] = parent_a;
  else
    parents[trip_a] = parent_b;  
}
int main() {
  int N,M;
  cin>>N>>M;
  vector<int> plan;
  for(int i=1;i<N+1;i++)
    {
      parents[i] = i;
      //처음에는 부모가 자기 자신임
    }
  for(int r= 1;r<N+1;r++)
    {
      for(int c=1;c<N+1;c++)
        {
          //1~N
          cin>>trip[r][c];
        }
    }
  //해당 경로를 보고 갈 수 있다 - 합쳐지지 않았다 -> 합침
  for(int r=1;r<N+1;r++)
    {
      for(int c = 1;c<N+1;c++)
        {
          if(trip[r][c])
          {
            //이어져 있음
            //집합이 안합쳐져있음
            if(parents[r] != parents[c])
            {
              union_p(r,c);
            }
            
          }

          
        }

      
    }
  for(int i=0;i<M;i++)
    {
      int temp;
      cin>>temp;
      plan.push_back(temp);
    }
  bool result = calc(plan,M);
  if(result)
  {
    cout<<"YES"<<endl;
  }
  else
  {
    cout<<"NO"<<endl;
  }
}