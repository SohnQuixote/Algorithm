#include <iostream>
#include <cstring>
using namespace std;
/*
  QUANTIZE
  넓은 범위를 갖는 값들을 작은 범위를 갖는 값들로 근사해 표현
  자료를 손실 압축
  최대 S종류 값 양자화 숫자 원래 수열에 없는 숫자 가능
  각 숫자별 오차제곱의 합을 최소화 양자화
  제한시간
  0초
  완전탐색 시간터질거 같음
  풀이의 과정

  반복되는 부분문제
  조건
  1. 양자화 시켜야 될 수의 범위 1000?
  2. 
*/
int C;
int N;
int S;
int used[1001]
int perm[100];
int main() {
  cin>>C;
  for(int tc=0;tc<C;tc++)
    {
      memset(used,0,sizeof(used));
      cin>>N>>S;
      for(int i=0;i<N;i++)
        {
          cin>>perm[i];
          if(!used[perm[i]])
            used[perm[i]]++;
        }

      
    }
}