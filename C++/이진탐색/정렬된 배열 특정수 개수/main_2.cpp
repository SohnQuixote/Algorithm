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
  입력은 너무 쉬우니 이진으로 시도
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
  if((mid == 0 || target >array[mid-1])&& array[mid] == target)//특정 숫자를 찾는게 아니라 바로 작은 수의 위치
    //맨 앞이거나 앞 원소가 작음
    return mid;
  else if(target<= array[mid])
    //아닐경우는 mid-1부터 다시 탐색
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
  if((mid == N-1 || target <array[mid+1])&& array[mid] == target) //특정 숫자를 찾는게 아니라 바로 작은 수의 위치
    //끝 부분이거나 뒤에 원소가 큼
    return mid;
  else if(target>= array[mid])
    return bin_search_big(array,mid+1,end,target);
  else
    return bin_search_big(array,start,mid-1,target);
  
}
int calc(vector<int> numbers,int target)
{
  int start,end;
  start = bin_search_small(numbers,0,N-1,X);
  if(start == IMPOSSIBLE) //아예 못찾은거
    return IMPOSSIBLE;
  else{
    end = bin_search_big(numbers,0,N-1,X);
  }
  return end-start+1;
} 
int main() {
  vector<int> numbers;
  cin>>N>>X;
  //reserve해서 할 경우 잘 안됨 
  for(int i=0;i<N;i++)
    {
      int temp;
      cin>>temp;
      numbers.push_back(temp);
    }
  cout<<calc(numbers,X)<<endl;
}