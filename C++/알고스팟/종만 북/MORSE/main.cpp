#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
/*
  MORSE
  n개의 장점 m개의 단점
  - ascii  code 45
  o ascii code 111
  장점 n, 단점 m, k 번째 신호 
  1. 고려사항 dp를 어디에?
  선택지는 두개
  근데 -를먼저해야됨
  그리고 몇번째지?
  사실 부분문제임

  cache를 어디다가???
  n과 m에 따라서 다른 값이 나오는 것이 문제임
  모든 신호를 사전 순서대로 만드는 완전 탐색 알고리즘
  모든 신호를 출력하는 대신에 k번째 신호만 출력
  이항계수?
  n+m 에서 n개를 뽑는 경우의수 뽑음 안뽑음 N+M-1 N-1 N+M-1 N
*/
const int M = 1000000000 + 500;
int bino[201][201]; //n= 100 m=100
int skip;
void init_bino()
{
  for(int i=0;i<=200;i++)
    {
      bino[i][0] = 1;
      bino[i][i] = 1;
      for(int j=1;j< i;j++)
        {
          bino[i][j] = min(M , bino[i-1][j-1] + bino[i-1][j]);
        }


      
    }



  
}
void print_k(int n,int m,string s)
{
  if(skip<0) return;
  if(n==0 &&m==0)
  {
    if(skip == 0) cout<<s<<'\n';
    --skip;
    return;
    
    
  }
  if(bino[n+m][n] <= skip)
  {
    skip -= bino[n+m][n];
    return;
  }
  if(n>0) print_k(n-1,m,s+"-");
  if(m>0) print_k(n,m-1 , s+"o");

  
}




int main() {
  int C;
  cin>>C;
  init_bino();
  for(int i=0;i<C;i++)
    {
      int n,m,k;
      cin>>n>>m>>k;
      skip = k-1;
      print_k(n,m,"");

      
    }
}