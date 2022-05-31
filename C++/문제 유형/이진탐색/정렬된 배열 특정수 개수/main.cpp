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
//정렬된 정보니까 입력 시점에서 계산 가능 -> O(1)
int main() {
  vector<int> numbers;
  cin>>N>>X;
  numbers.reserve(N);
  int start = -1;
  int end = 0;
  for(int i=0;i<N;i++)
    {
      int temp;
      cin>>temp;
      numbers[i] = temp;
      if(start == -1 && temp == X)
      {
        start = i; //시작 지점 -1이면 아예 안뜬거
        end = -1; //입력이 들어왔음
      }
      if(end == -1 && temp != X)
      {
        end = i;        
        //입력이 들어왔는데 원하는 입력이 아님 -> 여기까지가 범위
        //만약 끝까지면? N이 end임
      }
    }
  if(start == -1)
  {
    cout<<start<<endl;
  }
  else{
    if(end != -1)    
      cout<<(end-start)<<endl;
    else
      cout<<(N-start)<<endl;
  }
}