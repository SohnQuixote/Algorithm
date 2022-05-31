#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
  포도주 시식
  다양한 포도주 1렬
  규칙
  1. 선택하면 다 마심
  2. 연속 3잔 불가능
  많은 양의 포도주 맛보려함
  
*/
const int  MAX = 10001;
int wines[MAX] = {0,};
int drink[MAX] = {0,};
int calc(int N)
{
  drink[0] = 0;
  drink[1] = wines[1];
  drink[2] = wines[1]+wines[2];
  for(int i=3;i<=N;i++)
    {
      drink[i] = max({(drink[i-3]+wines[i-1]+wines[i]), (drink[i-2] +wines[i]),drink[i-1]});
    }
  return drink[N];
}
int main() {
  ios_base :: sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);
  int N;
  cin>>N;
  for(int i=1;i<=N;i++)
    cin>>wines[i];
  cout<<calc(N)<<'\n';
}