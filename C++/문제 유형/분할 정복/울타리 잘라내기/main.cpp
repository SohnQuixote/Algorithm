#include <iostream>
#include <vector>
using namespace std;
/*
  울타리 잘라내기
  잘라 낼 수 있는 직사각형 최대크기
  N- 울타리 길이
  fences - 울타리 높이
  브루트 포스 -> 하나씩 자기보다 큰 펜스 만날때까지 폭을 더한뒤 넓이 계산 -> 최댓값 -> 데이터 클 경우 시간초과 가능
  
*/ 
int N;
const int NINF = -987654321;
vector<int> fences(20000,0);
//int result = -987654321; //매번 범위 * 높이 계산하여 최댓값
int max_rect(int start, int end)
{
  //판자 하나
  
  if(start>end) return NINF;
  else if(start == end ) return fences[start];
  //cout<<start<<' '<<end<<endl;
  int mid = (start+end)/2;
  //양 옆
  int result = max(max_rect(start,mid),max_rect(mid+1,end));
  //이진 탐색할때 mid-1로 탐색하면 무한 반복 일어남
  //두 부분 사각형
  int lo = mid;
  int hi = mid+1;
  int height = min(fences[lo],fences[hi]);
  result = max(result,height *2);
  while(start<lo || hi < end)
    {
      if(hi<end && (lo == start || fences[lo-1] < fences[hi+1]))
      {
        height = min(height,fences[hi+1]);
        hi+=1;
      }
      else
      {
        height = min(height,fences[lo-1]);
        lo-=1;
      }
      result =max(result,height * (hi-lo+1));
    }
  return result;
}
int main() {
  //int N;
  cin>>N;
  for(int i=0;i<N;i++)
    {
      cin>>fences[i];
    }
  //cout<<N-1<<endl;
  cout<<max_rect(0,N-1)<<endl;
}