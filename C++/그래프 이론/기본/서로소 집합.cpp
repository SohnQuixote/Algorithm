#include <iostream>
using namespace std;
//서로소 집합 구현
const int MAX = 101;
int parents[MAX]= {0,};
int find_parent(int child)
{
  if(parents[child] != child)
    return find_parent(parents[child]);
  return child;
}
//경로 압축 기억
int r_find_parent(int child)
{
  if(parents[child] != child)
    parents[child] =  find_parent(parents[child]);
  return parents[child];
  
}
void union_parent(int child_a,int child_b)
{
  int parent_a = find_parent(child_a);
  int parent_b = find_parent(child_b);
  if(parent_a<parent_b)
    parents[child_b] = parent_a;
  else
    parents[child_a] = parent_b;
}
int main() {
  int v,e;
  cin>>v>>e;
  bool cycle = false;
  for(int i=1;i<v+1;i++)
    parents[i] = i;
  for(int i=0;i<e;i++)
    {
      int a,b;
      cin>>a>>b;
      //사이클 판별
      if(r_find_parent(a) == r_find_parent(b))
      {
        cycle = true;
        break;
      }
      else{
        union_parent(a,b);
      }
      //union_parent(a,b);
    }
  if(cycle)
    cout<<"사이클 발생"<<endl;
  else
    cout<<"사이클 발생 안함"<<endl;
  for(int i=1;i<v+1;i++)
    {
      cout<<parents[i]<<' ';
    }
  cout <<endl;
  for(int i=1;i<v+1;i++)
    {
      cout<<find_parent(parents[i])<<' ';
    }
  cout<<endl;
}