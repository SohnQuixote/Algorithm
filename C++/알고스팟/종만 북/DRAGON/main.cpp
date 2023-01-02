#include <iostream>
using namespace std;
/*
  DRAGON
  0세대 FX
  X => X+YF
  Y => FX-Y
  1세대 FX+YF
  2세대 FX+YF + FX-YF
  문자열중 p번째 글자부터 l글자만을 계산
  할 때 전부다 해야하는것인가?
  너무 길긴함
  어쨌든 다봐야 되긴 함
  규칙 자체는 간단
  함수 인자로 p와 l을 넘겨야함

  n세대 p번째 글자를 찾는것
  이런 유형의 문제의 경우 skip을 제대로 하는 것이 중요함
  어렵구만
  탑다운 보텀업 방식 채택
  좀 고민 더했으면 풀이가 나왔을 것

*/
const int MAX = 1000000051;
int length[51];//해당 gen의 길이
void length_calc()
{
   length[0] = 1;
  //length[0]은 어차피 쓸일이 없음
  
  for(int i=1;i<=50;i++)
    length[i] = min(MAX, 2*length[i-1] +2);
  //0번째 세대는 좀 이상하지만
  //1번째부터는 맞음
  
}
// 드래곤 커브 문자열을 생성하는 재귀호출 알고리즘
//skip번째 글자를 반환함
char curve(const string& seed,int gen,int skip)
{
  if(!gen)
  {
    return seed[skip];
  }
  for(int i=0;i<seed.size();i++)
    {
      if(seed[i] == 'X' || seed[i] == 'Y')
      {
        if(skip>=length[gen])
          skip -= length[gen]; //해당 세대를 보지 않고 그냥 건너 뛰어버림
          //그러면 그냥 다음문자가 나오게됨
          //이해 완료
        else if(seed[i] == 'X')
          return curve("X+YF",gen-1,skip);
        else if(seed[i] =='Y')
          return curve("FX-Y",gen-1,skip);
      }
      else if(skip>0)
      {
        --skip;
      }
      else
        return seed[i];

      
    }
  
}
int main() {
  int C;
  int N,P,L;
  cin>>C;
  length_calc();
  for(int i=0;i<C;i++)
    {
      cin>>N>>P>>L;
      P--;
      for(int idx = P;idx<P+L;idx++)
        cout<<curve("FX" , N,idx);
      cout<<"\n";

      
    }
}