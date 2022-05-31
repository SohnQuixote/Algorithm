#include <iostream>
using namespace std;
const int IMPOSSIBLE  = 9876543;

//재귀 구현
int bin_search(int *array, int start, int end,int target)
{
  if(start>end)
  {
    return IMPOSSIBLE;
  }
  int mid = (int)((start+end)/2);  
  if(target == array[mid])
    return mid;
  else if(target< array[mid])
    return bin_search(array,start,mid-1,target);
  else 
    return bin_search(array,mid+1,end,target);
  
}
//반복 구현
int bin_search_iter(int *array,int start, int end, int target)
{
  while(start<=end)
    {
      int mid = (int)((start+end)/2);
      if(target == array[mid])
        return mid;
      else if(target<array[mid])
        end = mid-1;
      else
        start = mid+1;
    }
    return IMPOSSIBLE;

  
}
int main() {
  
}