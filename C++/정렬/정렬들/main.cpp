#include <iostream>
using namespace std;
/*
  유의- 그냥 new int는 동적 배열이 0으로 초기화 안됨
*/
//Selection Sort
void s_sort(int *array, int length)
{
  for(int i=0;i<length;i++)
    {
      int min_index = i;
      for(int j=i+1;j<length;j++)
        {
          if(array[min_index]>array[j])
            min_index = j;
        }
      int temp = array[min_index];
      array[min_index] = array[i];
      array[i] = temp;
    }
}
void i_sort(int *array, int length)
{
  for(int i=1;i<length;i++)
    {
      for(int j=i;j>0;j--)
        {
          if(array[j]<array[j-1])
          {
            int temp = array[j];

            array[j] =array[j-1];
            array[j-1] = temp;
          }
          else{
            break;
          }
        }

      
    }
}
void q_sort(int *array, int start, int end)
{
  if(start>=end)
    return;
  int pivot = start;
  int left = start+1;
  int right = end;
  while(left<=right)
    {
      while(left<=end && array[left] <= array[pivot])
        left++;
      while(right> start && array[right] >= array[pivot])
        right--;
      if(left> right)
      {
        int temp = array[pivot];
        array[pivot] = array[right];
        array[right] = temp;        
      }
      else{
        int temp = array[left];
        array[left] = array[right];
        array[right] = temp;  
      }       
    }
  q_sort(array,start,right-1);
  q_sort(array,right+1,end);
}
void c_sort(int * array, int max, int length)
{
  int *count = new int[max+1]();
  for(int i=0;i<length;i++)
    count[array[i]]++;

  for(int i=0;i<max+1;i++)
    {
      for(int j=0;j<count[i];j++)
        cout<<i<<' ';
      
    }

  delete [] count;
}
int main() {
  int array[5] = {3,4,2,1,5};
  //s_sort(array,5);
  //i_sort(array,5);
  //q_sort(array,0,4);
  //c_sort(array,5,5);
  cout<<endl;
}