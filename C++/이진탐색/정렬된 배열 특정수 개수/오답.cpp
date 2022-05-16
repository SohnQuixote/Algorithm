#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = -1;
/*
  정렬된 배열에서 특정 수의 개수 구하기
  N개 수열 오름차순 정렬 -> x가 등장하는 횟수
  11222 -> 2 ->3번
  이진 탐색 사용 -> X가 우측에 있는 시작점, X가 좌측에 있는 끝점 - 수 계산
  이진 탐색 -> 시작점,끝점,중간점을 이용하여 특정 원소 찾기
  특정 원소보다 작은 숫자/큰 숫자의 수 계산?
  or 특정원소 찾고 지우기
*/
//재귀 구현된 이진 탐색 함수
int N,X;
int bin_search_small(vector<int> array, int start, int end,int target)
{
  if(start>end)
  {
    return IMPOSSIBLE;
  }
  int mid = (int)((start+end)/2);  
  if(target == array[mid] && target> array[mid-1]) //특정 숫자를 찾는게 아니라 바로 작은 수의 위치
    return mid - 1;
  else if(target< array[mid])
    return bin_search_small(array,start,mid-1,target);
  else 
    return bin_search_small(array,mid+1,end,target);
  
}
int bin_search_big(vector<int> array, int start, int end,int target)
{
  if(start>end)
  {
    return IMPOSSIBLE;
  }
  int mid = (int)((start+end)/2);  
  if(target == array[mid] && target < array[mid+1]) //특정 숫자를 찾는게 아니라 바로 작은 수의 위치
    return mid + 1;
  else if(target< array[mid])
    return bin_search_big(array,start,mid-1,target);
  else 
    return bin_search_big(array,mid+1,end,target);
  
}
int calc(vector<int> numbers,int start,int mid,int target)
{
  
} 
int main() {
  vector<int> numbers;
  cin>>N>>X;
  numbers.reserve(N);
  for(int i=0;i<N;i++)
    cin>>numbers[i];
  
}