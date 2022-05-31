#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int IMPOSSIBLE = 0;
/*
부품 찾기
정렬후 이진 탐색으로 찾은 다음 결과를
vector string container에 저장
값을 찾으면 인덱스가 아닌 값을 반환
*/
int calc(int *array,int start, int end, int target)
{
  if(start>end)
    return IMPOSSIBLE;
  int mid = static_cast<int>((start+end)/2);

  if(array[mid] == target)
    return target;
  else if(array[mid]>target)
    return calc(array,start,mid-1,target);
  else
    return calc(array, mid+1,end,target);
}
int main() {
  int N, M;
  vector<string> results;
  string yes = "yes";
  string no = "no";
  cin>>N;
  int *array = new int[N];
  for(int i=0;i<N;i++)
    {
      cin>>array[i];
    }
  cin>>M;
  int *customer = new int[M];
  for(int i=0;i<M;i++)
    {
      cin>>customer[i];
    }
  sort(array,array+N);
  for(int i=0;i<M;i++)
    {
      if(calc(array,0,N-1,customer[i]))
        results.push_back(yes);
      else
        results.push_back(no);
    }
  for(int i=0;i<M;i++)
    {  
      cout<<results[i]<<' ';
    }
  cout<<endl;
  delete [] customer;
  delete [] array;
}