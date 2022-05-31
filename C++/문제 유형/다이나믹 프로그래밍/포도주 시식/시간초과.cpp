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
int calc(int N,int index)
{
  if(drink[index])
    return drink[index];
  if(index>=N)
    return 0;
  int result = 0;
  result = max({(wines[index] + calc(N,index+2)) , (wines[index] + wines[index+1] + calc(N,index+3) ) , (calc(N,index+1))});
  drink[index] = result;
  return result;
}
int main() {
  int N;
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>wines[i];
  cout<<calc(N,0)<<endl;
}