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
int arr[9] = {0,}
bool visited[9] = {0,};
void calc(int N,int M,int s)
{
  if(s == M)
  {
    for(int i=0;i<M;i++)
      cout<<arr[i]<<' ';
    cout<<endl;
    return;
  }

  for(int i=1;i<=N;i++)
    {
      if(!visited[i])
      {
        visited[i] = true;
        arr[s] = i;
        calc(N,M,s+1);
        visited[i] = false;
        
      }
      
    }
}
int main() {
  int *array;  
  int N,M;
  cin>>N>>M;
  calc(N,M,0);
  }