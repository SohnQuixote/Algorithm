#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
/*
  카드 정렬하기
  정렬된 두 묶음 숫자카드 각 묶음 카드 수 A,B -> 합치려면 A+B 비교 필요
  조합 사용? or 정렬해서 작은것 부터 합치면 효율적? - 맞음
  최소 비교 범위 - int 내에 존재 - 21억
  우선순위 큐 사용?
*/
int main() {
  int N;
  cin>>N;
  //vector<int> cont;
  priority_queue<int, vector<int> ,greater<int>> q;
  for (int i=0;i<N;i++)
    {
      int temp;
      cin>>temp;
      q.push(temp);
    }
  if(q.size()== 1)
  {
    cout<<0<<endl;
    return 0;
  }
  int result = 0;
  while(q.size()!=1)
    {
      int a = q.top();
      q.pop();
      int b = q.top();
      q.pop();
      q.push(a+b);
      result += a+b;
    }
  cout<<result<<endl;
}