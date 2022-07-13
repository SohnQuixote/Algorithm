#include <iostream>
#include <vector>
using namespace std;

/*
  N*N 단어 퍼즐
  특정 길이 K 단어 자리수 출력
  그냥 세면 됨
*/
int calc(vector<vector<int>> a,int n, int k)
{
  //연속적인 1의수
  int result =0;
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
        {
          int tmp = 0;
          while(a[i][j] == 1 && j<n)
          {
            tmp+=1;
            j+=1;
          }
          if(tmp == k)
            result+=1;
          
        }
      
    }
    for(int j=0;j<n;j++)
    {
      for(int i=0;i<n;i++)
        {
          int tmp = 0;
          while(a[i][j] == 1 && i <n)
          {
            tmp+=1;
            i+=1;
          }
          if(tmp == k)
            result+=1;
          
        }
      
    }

  
  return result;
}
int main() {
  int T;
  cin>>T;
  vector<int> results;
  vector<vector<int>> Arr(15,vector<int>(15,0));
  for(int i=0;i<T;i++)
    {
      int N,K;
      cin>>N>>K;
      
    for(int r=0;r<N;r++)
      {
      for(int c=0;c<N;c++)
        {
          cin>>Arr[r][c];
        }
      }
      
    results.push_back(calc(Arr,N,K));      

      
    }
  for(int i=0;i<T;i++)
    {
      cout<<"#"<<i+1<<' '<<results[i]<<endl;
    }
}