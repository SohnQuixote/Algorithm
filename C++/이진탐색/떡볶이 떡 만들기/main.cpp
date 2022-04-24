#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
/*
  떡볶이 떡만들기
  떡의 개수 N 떡의 길이 M
  절단기 설정 높이 최댓값
  손님은 빼고 남은 값만 갖고 감
  떡 크기 배열에서 절단기 크기보다 큰 크기를 가진 인덱스를 반환해야함
  정확한 값을 못찾아도 값보다 크거나 같으면 반환
  이진 탐색 변환
*/
int array_sum(int *array, int start, int end, int i)
{
  int result = 0;
  for(int j= start;j<end;j++)
    result += (array[j] - i);
  return result;  
}
int calc(int *array, int start, int end,int target)
{
 if(start>end)
 {
    if(start == -1)
      return 0;
    return start;
 }
  int mid = static_cast<int>((start+end)/2);
  if(array[mid] == target)
    return mid;
  else if (array[mid] >target)
    return calc(array,start,mid-1,target);
  else
    return calc(array,mid+1,end,target);
}
int main() {
  int N,M;
  cin>>N>>M;
  int fin_result;
  int *array = new int[N];
  for(int i=0;i<N;i++)
    {
      cin>>array[i];
    }
  sort(array,array+N);
  for(int i=0;i<array[N-1];i++)
    {
      int index = calc(array,0,N-1,i);
      int result = array_sum(array,index,N,i);
      //cout<<i<<' '<<index<<endl;
      //cout<<i <<' '<<result<<endl;
      if(result < M)
      {
        fin_result = i-1;
        break;
      }
    }
  cout<<fin_result<<endl;
  delete [] array;
}