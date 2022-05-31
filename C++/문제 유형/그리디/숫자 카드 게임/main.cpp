#include <iostream>
/*
숫자카드게임
N * M 
행을 고르는데 가장 작은 숫자 카드
가장 큰 숫자 뽑을 수 있는 행 고르기
  */
int card_calc(int **array, int N,int M)
{
  //int result = 0;
  int max,tmp_max;
  max = 0;
  for(int i=0;i<N;i++)
    {
      tmp_max = 10001;
      for(int j=0;j<M;j++)
        {
          if(tmp_max>array[i][j])
          {
            tmp_max = array[i][j];
          }
          
        }
        if(tmp_max>max)
        {
          max = tmp_max;
        }
    }

  return max;
}
int main() {
  int N,M;
  int ** array;
  std::cin>> N >>M;
  array = new int*[N]; 
  for(int i = 0; i < N; i++) 
    array[i] = new int[M];

  for (int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        std::cin>>array[i][j];
      
    }
  std::cout<<card_calc(array,N,M)<<std::endl;
}