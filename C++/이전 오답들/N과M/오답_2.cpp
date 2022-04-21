/*
  N과M
  1부터 N까지 중복없이 M개를 고른 수열
  문제 풀기전에 무슨 알고리즘을 써야하는지 정해놓고 풀기
*/
//DFS로 해결

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool visited[9];
void calc(int N,int M,int s)
{
  if(M==0)
    return;
  visited[s] = true;
  cout<<s<<" ";

  for(int i=1;i<N+1;i++)
    {
      if(!visited[i])
        calc(N,M-1,i);
    }
}
void clear()
{
  for(int i=0;i<9;i++)
    {
      visited[i] = false;
    }
}
int main() {
  int *array;  
  int N,M;
  cin>>N>>M;
  for(int i=1;i<N+1;i++)
    {
      calc(N,M,i);
      clear();
      cout<<endl;
    }
  }