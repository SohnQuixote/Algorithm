#include <iostream>
#include <vector>
using namespace std;
/*
  지민이 전체페이지 N
  각 숫자 페이지 번호 몇번
  1~9 - 1부터 9
  10-19 - 0부터 9 + 1
  21-29 - 1부터 9 + 2
  하나하나 다 계산할 필요가 있나?
  너무 복잡해서 브루트 포스 시도
*/
const int MAX = 10;
int nums[MAX] = {0,};
vector<int> calc_jarisoo(int N , vector<int> jarisoo)
{
  while(N)
    {
      jarisoo.push_back(N % 10);
      N/=10;
    }
  return jarisoo;
}
void brute_jarisoo(int N)
{
  while(N)
    {
      nums[N % 10]+=1;
      //cout<<N%10<<endl;
      N/=10;
    }
}
void brute_calc(int N)
{
  while(N )
    {
      brute_jarisoo(N);
      N--;
    }
}
void calc(int N , vector<int>jarisoo)
{
  if(N<10)
  {
    for(int i=1;i<=N;i++)
      {
        nums[i]+= 1;
      }
    return;  
  }
  else
  {
    int t = 1;
    while(!N)
      {
        for(int j =0;j <= N/10 - 1;j++)
          {
        for(int i=0;i<MAX;i++)
          {
            nums[i]+=t;
          }
          }
          for(int j=0;j<=N%8;j++)
            {
              nums[j] += t;
            }
      }
  }
}
int main() {
  vector<int> jarisoo;
  int N;
  cin>>N;
  //jarisoo = calc_jarisoo(N,jarisoo);
  //calc(N,jarisoo);
  brute_calc(N);
  for(int i=0;i<MAX;i++)
    {
      cout<<nums[i]<<' ';
    }
  cout<<endl;
}