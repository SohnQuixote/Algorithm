#include <iostream>
#include <vector>
using namespace std;
int m,n;
bool arr[1000000] = {0,};
vector<int> result;
void calc()
{
  for(int i=m;i<=n;i++)
    {
      if(i %2 == 0 && i!=2)
        arr[i] = 1;
      if(i %3 == 0 && i!=3)
        arr[i] = 1;
      if(i %5 == 0 && i!=5)
        arr[i] = 1;
      if(i %7 == 0 && i!=7)
        arr[i] = 1;
      if(i %11 == 0 && i!=11)
        arr[i] = 1;
      if(i %13 == 0 && i!=13)
        arr[i] = 1;
      if(i %17 == 0 && i!=17)
        arr[i] = 1;
      if(i %19 == 0 && i!=19)
        arr[i] = 1;
      if(i %23 == 0 && i!=23)
        arr[i] = 1;
            if(i %29 == 0 && i!=29)
        arr[i] = 1;
            if(i %31 == 0 && i!=31)
        arr[i] = 1;
            if(i %37 == 0 && i!=37)
        arr[i] = 1;
            if(i %41 == 0 && i!=41)
        arr[i] = 1;
            if(i %43 == 0 && i!=43)
        arr[i] = 1;
            if(i %47 == 0 && i!=47)
        arr[i] = 1;
            if(i %53 == 0 && i!=53)
        arr[i] = 1;
            if(i %59 == 0 && i!=59)
        arr[i] = 1;
                  if(i %59 == 0 && i!=59)
        arr[i] = 1;
                  if(i %59 == 0 && i!=59)
        arr[i] = 1;
    }
  for(int i=m;i<=n;i++)
    {
      if(arr[i] == 0)
      {
        bool flag= true;
        for(int c = 2;c<i-1;c++)
          {
            if(i%c == 0)
            {
              flag = false;
            }
            
          }
        if(flag)
          result.push_back(i);
        
      }
      
    }
  
}



int main() {
  cin>>m>>n;
  //에라토스테네스의 체
  calc();
  for(int i=0;i<result.size();i++)
    cout<<result[i]<<'\n';
  

  
}