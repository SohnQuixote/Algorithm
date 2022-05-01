#include <iostream>
#include <algorithm>
using namespace std;
/*
  만들 수 없는 금액
  동빈이 N개 동전
  N개 동전 이용하여 만들 수 없는 금액 최솟값
  배열이 너무 커지면 링크 오류가 발생함 (염두)
  동전들을 정렬한 뒤 1원부터 만들 수 있는지 확인  
*/
const int MAX = 1001;
int coins[MAX] = {0};
int calc(int N)
{
  int result = 0;
  int price = 1;
  int tmp_price = price;
  while(!result){
    for(int i=0;i<N;i++)
      {
        if(price == coins[i])
        {
          tmp_price = 0;
          break;
        }
        if(tmp_price>=coins[i])
        {
          tmp_price -= coins[i];
        }
        
      }
    if(tmp_price == 0)
        {
          tmp_price = ++price;
          continue;
        }
    else
    {
      result = price;  
    }
  }
  return result;
}
int main() {
  int N;
  cin>>N;
  for(int i=0;i<N;i++)
    {
      cin>>coins[i];
    }
  sort(coins,coins+N); //오름차순 정렬
  cout<<calc(N)<<endl;
}