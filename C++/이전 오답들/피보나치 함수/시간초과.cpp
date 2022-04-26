#include <iostream>
#include <vector>
/*
  피보나치 함수
  
*/
using namespace std;
const int MAX = 41;
int numbers[MAX] = {0,};
int zeroone[2] = {0,};
int fibo(int n) {
  if(n == 1 || n==0)
  {
    
    zeroone[n]+=1;
    return n;
  }
  else
    return fibo(n-1) + fibo(n-2);
}
pair<int,int> calc(int N)
{
  for(int i=0;i<2;i++)
    {
      zeroone[i] = 0;
    }
  fibo(N);
  return make_pair(zeroone[0],zeroone[1]);
}

int main() {
  int T,N;
  cin>>T;
  vector<pair<int,int>> results;
  for(int i=0;i<T;i++)
    {
      cin>>N;
      results.push_back(calc(N));
    }
  for(int i =0;i<T;i++)
    {
      cout<<results[i].first<<' '<<results[i].second<<endl;
    }
}