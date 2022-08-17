#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
long long n, m;
int main() {
  long long result;
  long long s,l;
  cin>>n;
  vector<long long>arr(n,0);
  for(long long i=0;i<n;i++)
    cin>>arr[i];
  long long left= 0;
  long long right = n-1;
  long long sum = 2123456789;
  sort(arr.begin(),arr.end());
  while(left< right)
    {
      long long tmp_sum = arr[left] +arr[right];
      if(abs(tmp_sum)<sum)
      {
        sum = abs(tmp_sum);

        s = arr[left];
        l = arr[right];

      }
      
      if(tmp_sum<0)
        left++;
      if(tmp_sum>0)
        right--;
      else if(tmp_sum == 0)
        break;

      
    }
    cout<<s<<' '<<l<<endl;
  


  
}