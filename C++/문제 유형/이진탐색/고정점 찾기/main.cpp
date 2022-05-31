#include <iostream>
#include <vector>
using namespace std;
/*
  고정점 찾기
  수열 원소 중 그값 인덱스 동일 원소
  고정점 최대 1개
  고정점 없으면 -1
  이진 탐색 시도
  O(N)은 안됨 -가장 간단
  target?
  이것도 입력때 체크하면 될 수 있긴 함 - 이진탐색으로 시도
  그냥 반환하는 조건만 변경  
  이진 완전 탐색
*/
int N;
const int IMPOSSIBLE = -1;
int bin_search(vector<int> array, int start, int end)
{
  int first,second;
  if(start>end)
  {
    return IMPOSSIBLE;
  }
  int mid = static_cast<int>((start+end)/2);
  if(array[mid] == mid)
    return mid;
  else
  {
    first = bin_search(array,start,mid-1);
    second = bin_search(array,mid+1,end);
  }
  if(first != -1)
    return first;
  else if(second != -1)
    return second;
  else
    return IMPOSSIBLE;
}
int main() 
{
  vector<int> numbers;
  cin>>N;
  //numbers.reserve(N);
  for(int i=0;i<N;i++)
    {
      int temp;
      cin>>temp;
      numbers.push_back(temp);
    }
  cout<<bin_search(numbers,0,N-1)<<endl;
}