#include <iostream>
#include <vector>
using namespace std;
/*
  효율적인 화폐 구성
  N개줄 화폐가치
  M원
  최소 화폐 개수
*/
const int MAX = 10001;
int price[MAX] = {0,};
int calc(vector<int> coins,int M, int N)
{
  for(int i=1;i<M+1;i++)
    {
      price[i] = 10001;
    }
  //price[0] = 0;
  for(int i=0;i<M+1;i++)
    {
       for(int j =0;j<N;j++)
         {
          if((i+coins[j])<M+1 && price[i+coins[j]] > (price[i]+1))
          {
           price[i+coins[j]] = price[i]+1;
          }

           
         }
    }
  if(price[M] != 10001)
    return price[M];
  else
    return -1;
}
int main() {
  int N,M;
  cin>>N>>M;
  vector<int> coins;
  for(int i=0;i<N;i++)
    {
      int temp;
      cin>>temp;
      coins.push_back(temp);
    }
  
  cout<<calc(coins,M,N)<<endl;
}