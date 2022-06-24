#include <iostream>
#include <vector>
using namespace std;
/*
  주사위 윷놀이
  시작칸 말 4개 존재
  주사위 10개 얻을 수 있는 점수 최댓값
  게임판 표현 가능한 좋은 자료구조?
  일단 전체 탐색은 dfs 사용
*/
const int NEGINF = -987654321;
vector<int> board(51,0);
int answer = NEGINF;
//해당 보드 번호
vector<bool> chk(51,false);
int dice[10] = {0,};
int horse_loc[4] = {0,};
//해당 보드에 말이 존재하는 지 여부
int move_idx(int start, int dist)
{
  int result = 0;
  //시작 인덱스, 이동하는 칸의 수
  if(dist ==0)
  {
    if(start>35)
      start = 35;//도착지
    return start;
  }
  if(start == 5)
  {
    return move_idx(21,dist-1);
  }
  else if(start == 10)
  {
    return move_idx(24,dist-1);
  }
  else if(start == 15)
  {
    return move_idx(26,dist-1);
  }
  else if(start == 20)
  {
    return(move_idx(35,0));
  }
  else if(start == 23|| start == 25|| start == 28)
  {
    return move_idx(30,dist-1);
  }
  else if(start == 32)
  {
    return move_idx(20,dist-1);
  }
  else if(start >= 30&& start <= 31)
  {
    return move_idx(start +1, dist -1); 
  }
  else if(start>=21 && start<=22)
  {
    return move_idx(start+1 , dist-1);
  }
  else if(start == 24)
  {
    return move_idx(start+1,dist-1);
  }
  else if (start>=26 && start<=27)
  {
    return move_idx(start+1,dist-1);
  }
  else if(start +dist >20)
  {
    return move_idx(35,0);
  }
  else
    return(move_idx(start+dist,0));
  return result;
}
void init_board()
{
  for(int i=1;i<=20;i++)
    {
      board[i] = 2*i;
    }
    board[21] = 13;
    board[22] = 16;
    board[23] = 19;
    //10 루트
    board[24] = 22;
    board[25] = 24;
    //20 루트
    board[26] = 28;
    board[27] = 27;
    board[28] = 26;
    //30 루트
    board[30] = 25;
    board[31] = 30;
    board[32] = 35;
    //공통 루트
    board[35] = 0;
    //도착지
  
}
void dfs(int cnt, int sum)
{
  //4개니까 구현상 이유로 중복해서 다 가보는식으로 구현
  if(cnt == 10)
  {
    answer = max(answer,sum);
    return;
  }
  for(int i=0;i<4;i++)
    {
      int cur_loc = horse_loc[i];
      if(cur_loc != 35)
      {
        int mov_loc = move_idx(cur_loc,dice[cnt]);
        if(chk[mov_loc] == false||mov_loc == 35)
        {
          chk[mov_loc] = true;
          chk[cur_loc] = false;
          horse_loc[i] = mov_loc;
          dfs(cnt+1,sum+board[mov_loc]);
          horse_loc[i] = cur_loc;
          chk[mov_loc] = false;
          chk[cur_loc] = true;
        }
        
      }
    }
}
void input()
{
  for(int i=0;i<10;i++)
    cin>>dice[i];
}
void test_print()
{
  int i,j;
  cin>>i>>j;
          cout<<"moving from::"<<board[i]<<endl;
          cout<<"moving steps::"<<j<<endl;
          cout<<"final dest::"<<board[move_idx(i,j)]<<endl;
          cout<<endl;

          
}
int main() {
  init_board();
  input();
  dfs(0,0);
  //while(1)
    //test_print();
  cout<<answer<<endl;
}