#include <iostream>
#include <vector>
using namespace std;
/*
  2048(easy)
  같은 값 두 블록 충돌 -> 하나로 합쳐짐
  한번 합쳐지고 계속 합쳐지진 않음
  블록마다 합쳐짐 flag?
  같은 수 3개 이동하려고 하는쪽이 합쳐짐
  최대 5번 이동해서 만들 수 있는 큰 블록 값 구하기
  보드 크기 N *N 
  일단 끝까지 이동 -> 합쳐져 있거나 같은 숫자 아닐 경우 이동 방향 역으로 한칸(이동 될때까지 반복) -> 모든 칸에 적용
0은 빈칸
*/
const int NINF = -987654321;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
//하 상 우 좌
//이동할때 모든 보드 전체 이동
//반복해서 0이 아닌칸 전체 이동
//simulation 문제 -> 시간 괜찮나?
//이동하고 상태 안변하면 바꿀필요 없긴 함 
bool calc_range(int a, int N)
{
  if(a>=0 && a<N)
    return true;
  return false;
}
vector<vector<int>> moving_board(vector<vector<int>> board, int dir, int N)
{
  vector<vector<bool>> possible(N,vector<bool>(N,true));
  //이동 방향에 따라 가장 끝쪽에 있는건 안움직임
  
      //2이상인것만 이동
      //이동방향 끝까지 갔다가 하나씩 왔던 방향으로 가면서 가능한지 체크
      //case 0: //하
    if(dir == 0)
    {
        for(int r = N-2;r>=0;r--)
          {
            for(int c = 0; c<N;c++)
              {
                if(board[r][c]>=2)
                {
                  //N-1 , c 와 체크 해야함
                  //cout<<r<<' '<<c<<endl;
                  int final_row;
                  for(int k = N-1;k>=r;k--)
                    {
                      final_row = k;
                      //같고 이동 가능이며 이동 했음
                      if(k!= r && board[k][c] == board[r][c] && possible[k][c] )
                      {
                        possible[k][c] = false;
                        //final_row = k;
                        break;
                      }
                      else if(board[k][c] == 0)
                      {
                        break;
                      }
                      //안 같음
                      
                    }
                    //한칸이라도 이동
                    //cout<<final_row<<' '<<c<<' '<<r<<endl;
                  
                    if(final_row != r)
                    {
                      board[final_row][c] += board[r][c];
                      board[r][c] = 0;
                    }
                    //이동 안하면 그냥 놔둠 

                  
                }
                
              }

            
          }
    }
      //case 1: //상
    else if(dir == 1)
    {
    for(int r = 1;r<= N-1;r++)
          {
            for(int c = 0; c<N;c++)
              {
                if(board[r][c]>=2)
                {
                  //N-1 , c 와 체크 해야함
                  //cout<<r<<' '<<c<<endl;
                  int final_row;
                  for(int k = 0;k<=r;k++)
                    {
                      final_row = k;
                      //같고 이동 가능이며 이동 했음
                      if(k!= r && board[k][c] == board[r][c] && possible[k][c] )
                      {
                        possible[k][c] = false;
                        //final_row = k;
                        break;
                      }
                      else if(board[k][c] == 0)
                      {
                        break;
                      }
                      //안 같음
                      
                    }
                    //한칸이라도 이동
                    //cout<<final_row<<' '<<c<<' '<<r<<endl;
                  
                    if(final_row != r)
                    {
                      board[final_row][c] += board[r][c];
                      board[r][c] = 0;
                    }
                    //이동 안하면 그냥 놔둠 

                  
                }
                
              }

            
          }
      
    }
      //case 2: //우
    else if(dir ==2 )
    {
        for(int c = N-2;c>=0;c--)
          {
            for(int r = 0; r<N;r++)
              {
                if(board[r][c]>=2)
                {
                  //N-1 , c 와 체크 해야함
                  //cout<<r<<' '<<c<<endl;
                  int final_col;
                  for(int k = N-1;k>=c;k--)
                    {
                      final_col = k;
                      //같고 이동 가능이며 이동 했음
                      if(k!= c && board[r][k] == board[r][c] && possible[r][k] )
                      {
                        possible[r][k] = false;
                        //final_row = k;
                        break;
                      }
                      else if(board[r][k] == 0)
                      {
                        break;
                      }
                      //안 같음
                      
                    }
                    //한칸이라도 이동
                    //cout<<final_row<<' '<<c<<' '<<r<<endl;
                  
                    if(final_col != c)
                    {
                      board[r][final_col] += board[r][c];
                      board[r][c] = 0;
                    }
                    //이동 안하면 그냥 놔둠 

                  
                }
                
              }

            
          }

      
    }
    else if(dir == 3)
    {
          for(int c = 1;c<= N-1;c++)
          {
            for(int r = 0; r<N;r++)
              {
                if(board[r][c]>=2)
                {
                  //N-1 , c 와 체크 해야함
                  //cout<<r<<' '<<c<<endl;
                  int final_col;
                  for(int k = 0;k<=c;k++)
                    {
                      final_col = k;
                      //같고 이동 가능이며 이동 했음
                      if(k!= c && board[r][k] == board[r][c] && possible[r][k] )
                      {
                        possible[r][k] = false;
                        //final_row = k;
                        break;
                      }
                      else if(board[r][k] == 0)
                      {
                        break;
                      }
                      //안 같음
                      
                    }
                    //한칸이라도 이동
                    //cout<<final_row<<' '<<c<<' '<<r<<endl;
                  
                    if(final_col != c)
                    {
                      board[r][final_col] += board[r][c];
                      board[r][c] = 0;
                    }
                    //이동 안하면 그냥 놔둠 

                  
                }
                
              }

            
          }

      
    }
      //case 3: //좌
      //이동 잘되는 것으로 보임
    return board;
}
bool diff_board(vector<vector<int>> a, vector<vector<int>> b, int N)
{
  bool result = false;
  for(int r = 0;r<N;r++)
    {
      for(int c=0;c<N;c++)
        {
          if(a[r][c] != b[r][c])
          {
            result = true;
            break;
            
          }
          
        }
      
    }

  return result;
}
int max_value_board(vector<vector<int>> board, int N)
{
  int result = NINF;

  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {  
          result = max(result,board[i][j]);
          
        }
      
    }
  return result;
}

int calc_max(vector<vector<int>> board, int N, int S)
{
  int result = max_value_board(board,N);
  if(S==0)
  {
    return result;
  //횟수를 다 했기에 최댓값 반환
  }
  //매번 매개변수 새로운 공간 할당됨

  //최대 N번 이동해서 얻을 수 있는 최댓값 반환
  vector<vector<int>> orig_board = board;
  
  for(int dir = 0;dir<4;dir++)
    {
      //상하좌우 전체 이동
      board = moving_board(board,dir,N);
      //가본 이력이 있으면 가볼 필요 없음 -> 경우의수가 너무 많나? 20 * 20 
      //5번이니 같지 않을 때만 이동하는걸로 구현
      if(diff_board(board,orig_board,N))
      {
        result = max(result, calc_max(board,N, S-1));
      }
      board = orig_board;//이동 전으로 해야함
    }
  
  

  return result;
}
void print_board(vector<vector<int>> board, int N)
{
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          cout<<board[i][j]<<' ';
          
        }
        cout<<endl;
      
    }
  
}
int main() {
  int N;
  cin>>N;
  
vector<vector<int>> board(20,vector<int>(20,0)); //숫자 담고 있음
//vector<vector<bool>>board_possible(20,vector<bool>(20,false)); //이동 했을 때 갈 수 있는지?
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          cin>>board[i][j];
        }
    }
    cout<<calc_max(board,N,5)<<endl;
    //board = moving_board(board,0,N);
    //print_board(board,N);
}