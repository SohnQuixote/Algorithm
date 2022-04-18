/*
설탕배달 
상근이는 요즘 설탕공장에서 설탕을 배달하고 있다. 상근이는 지금 사탕가게에 설탕을 정확하게 N킬로그램을 배달해야 한다. 설탕공장에서 만드는 설탕은 봉지에 담겨져 있다. 봉지는 3킬로그램 봉지와 5킬로그램 봉지가 있다.

상근이는 귀찮기 때문에, 최대한 적은 봉지를 들고 가려고 한다. 예를 들어, 18킬로그램 설탕을 배달해야 할 때, 3킬로그램 봉지 6개를 가져가도 되지만, 5킬로그램 3개와 3킬로그램 1개를 배달하면, 더 적은 개수의 봉지를 배달할 수 있다.

상근이가 설탕을 정확하게 N킬로그램 배달해야 할 때, 봉지 몇 개를 가져가면 되는지 그 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (3 ≤ N ≤ 5000)

출력
상근이가 배달하는 봉지의 최소 개수를 출력한다. 만약, 정확하게 N킬로그램을 만들 수 없다면 -1을 출력한다.

무게는 무조건 5a+3b 아니면 -1

*/

#include <iostream>
int calc(int N){
  int orig_N = N;
  int fin_result =  9876543;
  int result = 0;
  int target;
  target = (int)(N/5) * 5;

  if(orig_N%3 == 0)
  {
    result = (int)(orig_N/3);
    if(fin_result>result)
    {
      fin_result = result;
    }
  }
  for(int i = (target/5);i>0;i--)
    {
      result = 0;
      N = orig_N;
      N -= i*5;
      result += i;
      if(N == 0)
        {
          if(fin_result>result)
          {
            fin_result = result;
          }
        }
        else if(N!=0 && N%3 ==0)
        {
          result += (int)(N/3);
          if(fin_result>result)
          {
            fin_result = result;
          }
        }

      }
  if(fin_result == 9876543)
  {
    return -1;
  }
  return fin_result;
}
int main() {
  int N;
  std::cin>>N;
  std::cout<<calc(N)<<std::endl;
  
}