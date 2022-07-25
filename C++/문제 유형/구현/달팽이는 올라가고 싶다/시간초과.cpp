#include <iostream>
using namespace std;
/*
  이진 탐색 아님
  BFS/DFS 아님
  구현/Brute Force?
  시간초과
*/

int calc(int A,int B,int V)
{
  if(V-A<=0)
    return 1;
  return 1+calc(A,B,V-(A-B));

  
}
int main() {
  int A,B,V;
  cin>>A>>B>>V;
  cout<<calc(A,B,V)<<endl;
}