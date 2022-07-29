#include <iostream>
#include <vector>
using namespace std;
int m,n;
bool arr[1000000] = {0,};

vector<int> result;
void calc()
{
  for(int i=2;i<=n;i++)
    {
      for(int j=2;i*j<=n;j++)
        arr[i*j] = 1;
      
    }
  for(int i=m;i<=n;i++)
    {
      if(arr[i] == 0)
      {
          result.push_back(i);       
      }
      
    }
  
}



int main() {
  cin>>m>>n;
  //에라토스테네스의 체
  arr[1] = true;
  calc();
  for(int i=0;i<result.size();i++)
    cout<<result[i]<<'\n';
  

  
}