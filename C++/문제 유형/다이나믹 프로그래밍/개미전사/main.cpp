#include <iostream>
using namespace std;
/*
  개미전사
  인접한 식량 창고 공격받으면 알아챔
  최소 한칸 떨어진 창고 약탈
  ex. 1 3 1 5 -> 3 5 약탈 최댓값 8
*/
const int MAX = 100;
int foods[MAX] = {0};
int visited[MAX] = {0};
int calc(int N,int index)
{
  int result;
  if(visited[index])
    return visited[index];
  if(index>N)
    return 0;
  
  result = max(foods[index]+calc(N,index+2),calc(N,index+1));
  visited[index] = result;
  return result;
}
int main() {
  int N;
  cin>>N;
  for(int i=0;i<N;i++)
    {
       cin>>foods[i]; 
    }
  cout<<calc(N,0)<<endl;
}