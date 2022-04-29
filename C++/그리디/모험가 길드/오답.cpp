#include <iostream>
#include <algorithm>
using namespace std;
/*
  모험가 길드
  모험가 N명
  공포도 주어짐
  공포도 X이면 반드시 X명 이상
  그룹수의 최댓값
  공포도 X+1인 애들은 공포도 X인 애들 X명에 낄수는 있으나 
  그룹수가 늘어나진 않음
*/
const int MAX = 100001;
int adventurers[MAX] = {0,};
int fears[MAX] = {0,};
int calc(int N){
  int result = 0;
  for(int i=0;i<N;i++)
    {
      fears[adventurers[i]] +=1;
    }
  //공포도 배열 1의 수는 결과의 최솟값
  for(int i=1;i< N+1;i++)
    {
      result += fears[i] /i;
    }
  return result;
}
int main() {
  int N;
  cin>>N;
  for(int i=0;i<N;i++)
    cin>>adventurers[i];
  //sort(adventurers , adventurers+N);
  cout<<calc(N)<<endl;
}