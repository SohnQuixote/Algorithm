#include <iostream>
#include <vector>
using namespace std;
/*
  모노미노도미노 2
  사용블록 1*1 , 1*2, 2*1
  빨간색 보드에 위치 선택
  -> 초록색,파란색 블록 이동함
  타일로 꽉차면 타일 모두 사라짐
  점수 - 사라진 행 또는 열의 수
  얻은 점수 -> 초록색 파란색 보드 타일 있는 칸 개수
  블록 종류 상관없이 한칸씩 내려감
*/
const int MAX = 11;
int result = 0;
void gravity(vector<vector<int>> &board)
{
  //스코어 한 후 연한 곳에 있는 수만큼 블록 중력으로 내리기
  int el_x= 0;
  int el_y = 0;
  for(int i=0;i<4;i++)
    {
      if(board[4][i] != 0)
      {
        el_x = 2;
      }
      if(board[i][4] != 0)
      {
        el_y = 2;
      }
    }
  if(el_x == 0)
  {
    for(int i=0;i<4;i++)
      if(board[5][i] != 0)
        el_x = 1;
  }
  if(el_y == 0)
    for(int i=0;i<4;i++)
      if(board[i][5] != 0)
        el_y = 1;

  if(el_x != 0)
  {
    for(int i=9-el_x;i>=4;i--)
      {
        for(int j=0;j<4;j++)
          {
              
            board[i+el_x][j] = board[i][j];
            board[i][j] = 0;
          }

        
      }

    
  }
  if(el_y !=0)
  {
    
    for(int i=9-el_y;i>=4;i--)
      {
        for(int j=0;j<4;j++)
          {
              
            board[j][i+el_y] = board[j][i];
            board[j][i] = 0;
          }

        
      }
    
  }
  
}
int score(vector<vector<int>> &board)
{
  int score= 0;
  //한행 된거 삭제 및 연한 곳에 있으면 움직이기
  int sc_x = MAX;
  int sc_y = MAX;
  int del_x= 0;
  int del_y= 0;
  for(int i=6;i<10;i++)
    {
      int tmp = 0;
      int tmp_two = 0;
      for(int j=0;j<4;j++)
        {
          tmp+= board[i][j];
          tmp_two += board[j][i];
        }
      if(tmp>=4)
      {
        score++;
        sc_x = min(sc_x,i);
        for(int k=0;k<4;k++)
          {
            board[i][k] = 0;
            
          }
        del_x++;
      }
      if(tmp_two>=4)
      {
        score++;
        sc_y = min(sc_y,i);
        for(int k=0;k<4;k++)
          {
            board[k][i] = 0;
            
          }
        del_y++;
      }
    }
  if(sc_x != MAX)
  {
    for(int i=sc_x-1;i>=4;i--)
      {
        for(int j=0;j<4;j++)
          {
            if(board[i][j] != 0)
            {
              int tmp = board[i][j];
              board[i][j] = 0;
              board[i+del_x][j] = tmp;
            }
            
          }
        
      }
    
  }
  if(sc_y != MAX)
  {
    for(int j=sc_y-1;j>=4;j--)
      {
        for(int i=0;i<4;i++)
          {
            if(board[i][j] != 0)
            {
              int tmp = board[i][j];
              board[i][j] = 0;
              board[i][j+del_y] = tmp;
              
            }

            
          }
        
      }
    
  }
  return score;
}
void print(vector<vector<int>> board, int N)
{
  cout<<endl;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          cout<<board[i][j]<<' ';
          
        }
      cout<<endl;
      
    }
  
}
void put(vector<vector<int>> &board, int p, int x, int y)
{
  //빨간색에 놓으면 이동] 중력 처리 위해서 피스 구분 해야함
  //중구난방으로 떨어지면 안됨
  int mov_x, mov_y;
  if(p == 1)
  {
    // .
    for(int i=0;i<MAX;i++)
      {
        if(board[i][y] != 0)
        {
          mov_x = i-1;
          break;
        }
        
      }
    for(int i=0;i<MAX;i++)
      {
        if(board[x][i] != 0)
        {
          mov_y = i-1;
          break;
        }
        
      }
    board[mov_x][y] = 1;
    board[x][mov_y] = 1;
  }
  else if(p == 2)
  {
    // ..
    for(int i=0;i<MAX;i++)
      {
        if(board[x][i] != 0)
        {
          mov_y = i-1;
          break;
        }
        
      }
    for(int i=0;i<MAX;i++)
      {
        if(!(board[i][y] == 0 && board[i][y+1] == 0))
        {
          mov_x = i-1;
          break;
        }
        
      }    
    board[x][mov_y] = 1;
    board[x][mov_y-1] = 1;

    board[mov_x][y] = 1;
    board[mov_x][y+1] = 1; 
  }
  else if(p==3)
  {
    //.
    //.
    
    for(int i=0;i<MAX;i++)
      {
        if(board[i][y] != 0)
        {
          mov_x = i-1;
          break;
        }
      }
    for(int i=0;i<MAX;i++)
      {
        if(!(board[x][i]== 0 && board[x+1][i] ==0))
        {
          mov_y = i-1;
          break;
        }
        
      }
    board[mov_x][y] =1;
    board[mov_x-1][y] = 1;
    board[x][mov_y] = 1;
    board[x+1][mov_y] = 1;
  }
  result+=score(board);
  gravity(board);
}
void print_result(vector<vector<int>> board)
{
  int g_b = 0;
  for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
        {
          g_b+=board[i][j];
        }
    }
  cout<<result<<endl;
  cout<<g_b<<endl;
}
int main() {
  int N;
  cin>>N;
  vector<vector<int>> board(MAX,vector<int>(MAX,0));
  for(int i=0;i<MAX;i++)
    {
      board[10][i] = -1;
      board[i][10] = -1;
      
    }
  for(int i=0;i<N;i++)
    {
      int a,b,c;
      cin>>a>>b>>c;
      put(board,a,b,c);
      //print(board,10);
    }
  print_result(board);
}