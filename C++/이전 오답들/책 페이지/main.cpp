#include <iostream>
using namespace std;
/*
  지민이 전체페이지 N
  각 숫자 페이지 번호 몇번
  1~9 - 1부터 9
  10-19 - 0부터 9 + 1
  21-29 - 1부터 9 + 2
  하나하나 다 계산할 필요가 있나?
*/
const int MAX = 10;
int nums[MAX] = {0,};
void calc(int N)
{
  if(N<10)
  {
    for(int i=1;i<=N;i++)
      {
        nums[i]+= 1;
      }
    return;  
  }
  for(int i=0;i<MAX;i++)
    {
      nums[i]+= N/10;
    }
  for(int i=0;i<=(N%10);i++)
    {
      nums[i] += 1;
    }
  calc(N/10);
}
int main() {
  int N;
  cin>>N;
  calc(N);
  if(N>=10)
    nums[0]--;
  for(int i=0;i<MAX;i++)
    {
      cout<<nums[i]<<' ';
    }
  cout<<endl;
}