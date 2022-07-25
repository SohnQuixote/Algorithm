#include <iostream>
#include <algorithm>
/*
  1로 만들기
  정수 X 연산 4가지
  1. 5로 나누어 떨어지면 5로 나누기
  2. 3로 나누어 떨어지면 3로 나누기
  3. 2로 나누어 떨어지면 2로 나누기
  4. 1빼기
  적절히 사용해서 1만들기 연산 사용횟수 최솟값
*/

using namespace std;
const int MAX = 1000001;
int dp_table[MAX] = {0,};
int calc(int X)
{
  for(int i=1;i<=X;i++)
    {
      dp_table[i] = 1000001;
    }
  dp_table[1] = 0;
  //처음에는 0임
  
  for(int i=1;i<=X;i++)
    {
        int temp = dp_table[i]+1;
        if((2*i) < MAX && dp_table[2*i] > temp ) 
          dp_table[2*i] = temp;
        if((3*i) < MAX &&dp_table[3*i] > temp )
          dp_table[3*i] = temp;
        if((i+1) < MAX &&dp_table[(i+1)] > temp)
          dp_table[(i+1)] = temp;
      
    }
  return dp_table[X];
}
int main() {
  int X;
  cin>>X;
  cout<<calc(X)<<endl;
}