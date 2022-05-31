#include <iostream>
/*
  시각
  정수 N입력되면 0시00분부터 N시 59 분 59초까지 3이 포함되는 경우의 수
*/
int calc(int N)
{
  int result = 0;
  for(int i=0;i<N+1;i++)
    {
      if(i==3 || i==13 || i==23)
      {
        result+= (60*60);
      }
      else{
      result += (15*105);
        }
    }
  
  return result;
}
int main() {
  int N;
  std::cin>>N;
  std::cout<<calc(N)<<std::endl;
}