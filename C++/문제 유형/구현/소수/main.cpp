#include <iostream>
using namespace std;
int m,n;
int arr[10001] = {0,};

void calc()
{
  for(int i=2;i<=n;i++)
    {
    for(int j=2;i*j<=n;j++)
      {
        arr[i*j] = 1;
      }
      
    }
  
}
int main() {
  cin>>m>>n;
  int min_val = 0;
  int summ = 0;
  arr[1] = 1;
  calc();  
  for(int i=m;i<=n;i++)
    {
      if(!arr[i])
      {
        min_val = i;
        break;
      }
    }
    for(int i=m;i<=n;i++)
    {
      if(!arr[i])
      {
        summ+=i;
      }
    }
    if(min_val == 0)
    {
      cout<<-1;
    }
    else{
      cout<<summ<<'\n'<<min_val;
    }
}