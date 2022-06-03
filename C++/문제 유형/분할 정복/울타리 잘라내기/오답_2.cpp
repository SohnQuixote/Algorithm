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
vector<int> fences(20000,0);
const int NINF = -987654321;
//int result = -987654321; //매번 범위 * 높이 계산하여 최댓값
int max_rect(int start, int end)
//start와 end 사이의 울타리 크기중 모두가 만족하는 최솟값 * end- start + 1
{
  cout<<start<<' '<<end<<endl;
  int answer = -987654321;
  //가운데 값 -1 , 가운데 값 +1 , 걸쳐있을 경우?
  
  int mid  = (start +end)/2;
  //분할 정복 종료조건
  if(end<start)
    return NINF;
  if(start == end)
  {
    return fences[start];
  }
  answer = max(answer, (mid-start+1) *max_rect(start,mid-1));
  //걸쳐 있을 경우?????
  int deg = 0;
  deg++;
  while(mid - deg >= 0 || mid+deg <= N-1)
    {
      if((mid+deg) <= N-1)
        answer = max(answer,(deg+1) *         max_rect(mid,mid+deg));
    if((mid-deg) >=0)
      answer = max(answer,(deg+1) * max_rect(mid-deg,mid));
      deg++;
    }
  //중간값에서 하나씩?
  answer = max(answer, (end-mid) * max_rect(mid+1 ,end));
  int mini = 987654321;
  for(int i= start; i<=end;i++)
    {
      mini = min(mini,fences[i]);
    }
    answer = mini;
  return answer;
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