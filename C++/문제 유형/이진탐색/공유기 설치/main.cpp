#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,C;
vector<int> houses;
/*
  공유기 설치
  집 N개 수직선 위
  공유기 C개 설치
  인접한 공유기 사이 최대거리
  어떻게 이진탐색 적용?
  감도 안잡혀서 해답 참고 - 파라메트릭 서치 문제
*/
int calc_bi()
{
  //0~N-1 정렬된 데이터
  int result = 0;
  int max_gap = houses[N-1] - houses[0];
  int min_gap = 1;
  //거리를 조정해서 이진 탐색
  //최소거리 1 최소거리 8
  //두개는 무조건 맨앞 맨뒤
  //그러나 3개 이상 -> 가장 큰 거리 골라야함 ->완전 탐색->시간초과
  //최대 길이
  //원하는 결과 가장 인접한 두 공유기 사이의 최대거리
  //거리를 이진탐색하여 최적의 거리 알아냄
  while(min_gap<= max_gap)
    {
      int gap = static_cast<int>((max_gap+min_gap)/2);
      //gap -> 가장 인접한 공유기 최대거리5
      int value = houses[0];
      int count =1; //첫번째것은 설치하고 봄
      for(int i=1;i<N;i++)
        {
          if(houses[i] >= value+gap)
          {
            value = houses[i];
            //원하는 최소 gap 만족
            count++;
            //count가 C보다 작으면 최소 gap을 줄여야함
          }
        }
      if(count>=C)
      {
        //C개 이상 설치 가능
        min_gap = gap+1;
        result = gap;
      }
      else
      {
        max_gap = gap-1;
        //갭을 줄이기
      }
      
    }

  
  return result;
}
int main() {
  cin>>N>>C;
  for(int i=0;i<N;i++)
    {
      int temp;
      cin>>temp;
      houses.push_back(temp);
    }
  sort(houses.begin(),houses.end());
  cout<<calc_bi()<<endl;  
  
}