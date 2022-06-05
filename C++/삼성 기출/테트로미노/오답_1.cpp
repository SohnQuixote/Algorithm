#include <iostream>
#include <vector>
using namespace std;

/*
  테트로미노
  보드 N*M 주어짐
  해당 보드 공간에서 합 최대로 하는 테트로미노 놓아서 합을 최대
  완전으로 하면 너무 피스가 많음 -> 대칭 까지 고려해야함
  19개 피스 매번 다 해보고 범위 안에 있는 값 조정?
  다른 효율적인 방법이 생각 안남 -> 일단 구현
  dfs? 가본곳 더 안가기- 
  다이나믹 프로그래밍? 
*/ 
vector<vector<int>>board(500, vector<int>(500,0));
int pieces[19][4][2] = {
{{0,0}, {0,1},{0,2},{0,3} }, //1
{{0,0},{1,0},{2,0},{3,0}}, //2
{{0,0}, {0,1},{1,0},{1,1} }, //3
{{0,0}, {1,0},{2,0},{2,1} }, //4
{{0,0}, {1,0},{0,1},{0,2} }, //5
{{0,0}, {0,1},{1,1},{2,1} }, //6
{{0,0}, {0,1},{0,2},{-1,2} }, //7
{{0,0}, {0,1},{-1,1},{-2,1} }, //8
{{0,0}, {1,0},{1,1},{1,2} }, //9
{{0,0}, {1,0},{2,0},{0,1} }, //10
{{0,0}, {0,1},{0,2},{1,2} }, //11
{{0,0}, {1,0},{1,1},{2,1} }, //12
{{0,0}, {0,1},{-1,1},{-1,2} }, //13
{{0,0}, {1,0},{1,-1},{2,-1} }, //14
{{0,0}, {0,1},{1,1},{2,1} }, //15
{{0,0}, {0,1},{1,1},{0,2} }, //16
{{0,0}, {0,1},{-1,1},{1,1} }, //17
{{0,0}, {0,1},{-1,1},{0,2} }, //18
{{0,0}, {1,0},{2,0},{1,1} } // 19
};
/*
int piece_1[4][2] = {{0,0}, {0,1},{0,2},{0,3} };
int piece_2[4][2] = {{0,0},{1,0},{2,0},{3,0}};
int piece_3[4][2] = {{0,0}, {0,1},{1,0},{1,1} };
int piece_4[4][2] = {{0,0}, {1,0},{2,0},{2,1} };
int piece_5[4][2] = {{0,0}, {1,0},{0,1},{0,2} };
int piece_6[4][2] = {{0,0}, {0,1},{1,1},{2,1} };
int piece_7[4][2] = {{0,0}, {0,1},{0,2},{-1,2} };
int piece_8[4][2] = {{0,0}, {0,1},{-1,1},{-2,1} };
int piece_9[4][2] = {{0,0}, {1,0},{1,1},{1,2} };
int piece_10[4][2] = {{0,0}, {1,0},{2,0},{0,1} };
int piece_11[4][2] = {{0,0}, {0,1},{0,2},{1,2} };
int piece_12[4][2] = {{0,0}, {0,1},{1,1},{2,1} };
int piece_13[4][2] = {{0,0}, {0,1},{-1,1},{-1,2} };
int piece_14[4][2] = {{0,0}, {1,0},{1,-1},{2,-1} };
int piece_15[4][2] = {{0,0}, {0,1},{1,1},{2,1} };
int piece_16[4][2] = {{0,0}, {0,1},{1,1},{0,2} };
int piece_17[4][2] = {{0,0}, {0,1},{-1,1},{1,1} };
int piece_18[4][2] = {{0,0}, {0,1},{-1,1},{0,2} };
int piece_19[4][2] = {{0,0}, {1,0},{2,0},{1,1} };
*/
bool calc_range(pair<int,int> a, int b, int c)
{
  if((a.first>=0 && a.first<b) && (a.second>=0 && a.second<c))
    return true;
  return false;
}
int calc(int N, int M)
{
  int result = -987654321;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        {
          for(int p = 0;p<19;p++)
            {
              int tmp = board[i][j];
              bool ok_flag = true;
          
              for(int u=1;u<4;u++)
                {
                  int moving_i = i+pieces[p][u][0];
                  int moving_j = j+pieces[p][u][1];
                  if(calc_range(make_pair(moving_i,moving_j),N,M))
                  {
                    tmp+= board[moving_i][moving_j];
                  }
                  else{
                    ok_flag = false;
                    break;
                  }
                }

              if(ok_flag)
                result = max(result, tmp);
            }
        
          
        }

      
    }
  return result;
  
}
int main() {
  int N,M;
  cin>>N>>M;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        {
          cin>>board[i][j];
        }
      
    }
  cout<<calc(N,M)<<endl;
}