#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int INF = 987654321;


/*
  구슬 탈출 2
  직사각형 보드 빨간/파란 구슬 구멍을 통해 빼냄
보드 세로크기 N 가로크기 M
  빨간 구멍을 통해 빼냄
  파란 구멍에 들어가면 안됨  
  중력 -> 상하좌우 기울이기
최소 몇번 - 빨간
. -> 빈칸 -> 0
# -> 벽 -> -1
O -> 구멍 위치 -> 5
R -> 빨간 ->1
B -> 파란 ->2
10번이하 빨간 구슬 못빼내면 -1
무조건 완전탐색으로 해결 
상하좌우로 다 가봄 빨강 파랑 동시 이동
-1 만나면 멈추는 장소로
종료조건? -> 다시 들른곳 안들르기 - 이미 봐서 의미 없음
red가 들른 장소
blue가 들른 장소
모두 다 들러보고 최솟값 리턴
재귀로 구현 
같은 행이나 열에 존재할 경우 이동방향의 앞에있는 놈이 먼저 이동해야함 
*/


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
//하상 좌우
pair<int,int> goal;
vector<vector<int>> board(10,vector<int>(10,0));
vector<vector<bool>> red_visited(10,vector<bool>(10,false));
vector<vector<bool>> blue_visited(10,vector<bool>(10,false));
void print_board()
{
  cout<<endl<<endl;
  cout<<"printing marble board::  "<<endl;
  for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
        {
          int tmp = board[i][j];
          if(tmp == 0)
          {
            cout<<". ";
          }
          else if(tmp == -1)
          {
            cout<<"# ";
          }
          else if(tmp ==1)
          {
            cout<<"R ";
          }
          else if(tmp == 2)
          {
            cout<<"B ";
          }
          else if(tmp == 5)
          {
            cout<<"O "; 
          }
          
        }
      cout<<endl;

      
    }
  
}
pair<int,int> rolling_marble(pair<int,int> marble, int dir)
{
  //print_board();
  pair<int,int> result;
  int x=  marble.first;
  int y= marble.second;
  //골이면 해당 위치 -1이면 해당위치에서 이동방향으로 역으로 한번 이동
  while(true)
    {
      x+= dx[dir];
      y+= dy[dir];
      if(board[x][y] == -1 || board[x][y] == 1 || board[x][y] == 2)
      {
        return make_pair(x-dx[dir],y-dy[dir]);
        //장애물을 만나면 해당 방향 전방향으로 가야함
      }
      else if(x== goal.first && y == goal.second)
      {
        return make_pair(x,y);
      }
      
    }  
  return result;//여기까지 안와야함 
}
int calc(pair<int,int> red, pair<int,int> blue,int iter)
{
  int mini = INF;
  //빨강만 골에 있어야함
  int red_x = red.first;
  int red_y = red.second;
  int blue_x = blue.first;
  int blue_y = blue.second;
  //red_visited[red_x][red_y] = true;
  //blue_visited[blue_x][blue_y]  = true;
  vector<pair<int,int>> red_moving;
  vector<pair<int,int>> blue_moving;
  if(iter == 10)
    return mini;
  if(blue.first == goal.first && blue.second == goal.second)
  {
    return mini;
    //파랑 골 INF
    //빨강 파랑 골 INF
  }
  else if(red.first == goal.first && red.second == goal.second)
  {
    return iter;
  }
  //처음에 0 iter 10이상 return
  //갈 수 있는 방향 다 가보기 안 들른 장소
  //0 하 1 상 2 좌 3 우
  
  //너무 비효율적으로 짰음
  pair<int,int> red_mov;
  pair<int,int> blue_mov;
  cout<<"red::"<<red_x<<' '<<red_y<<endl;
  cout<<"blue::"<<blue_x<<' '<<blue_y<<endl;
  for(int i=0;i<4;i++)
    {
      if(red_x == blue_x) //같은 행에 존재
      {
        if(red_y<blue_y)
        {
          //빨강이 왼쪽
          if(i == 2) //좌
          {
            print_board();
            red_mov = rolling_marble(red,i);
            //이동해놓고 blue위치 반환
            //임시로 이동시켜야함 -이대로 가면 구슬증식
            //골이면 대체하면 안됨 
            if(red_mov.first == goal.first && red_mov.second == goal.second)
              board[red_mov.first][red_mov.second] = 5;
            else
              board[red_mov.first][red_mov.second] = 1;
            
            board[red.first][red.second] = 0;
            cout<<"direction"<<i<<endl;
            //print_board();
            blue_mov = rolling_marble(blue,i);
            print_board();
            if(red_mov.first == goal.first && red_mov.second == goal.second)
              board[red_mov.first][red_mov.second] = 5;
            else
              board[red_mov.first][red_mov.second] = 0;
            board[red.first][red.second] = 1;
            
          }
          if(i==3) //우
          {
            blue_mov = rolling_marble(blue,i);
            //이동해놓고 blue위치 반환
            
            if(blue_mov.first == goal.first && blue_mov.second == goal.second)
              board[blue_mov.first][blue_mov.second] = 5;
            else
              board[blue_mov.first][blue_mov.second] = 2;
            
            board[blue.first][blue.second] = 0;
            
            red_mov = rolling_marble(red,i);
            
            if(blue_mov.first == goal.first && blue_mov.second == goal.second)
              board[blue_mov.first][blue_mov.second] = 5;
            else
              board[blue_mov.first][blue_mov.second] = 0;
            
            board[blue.first][blue.second] = 2;
          }
          else //상하는 그냥 이동
          {
            
        red_mov = rolling_marble(red,i);
        blue_mov = rolling_marble(blue,i);
            
          }
        }
        else
        {
          //빨강이 오른쪽
          if(i == 3) //우
          {
            red_mov = rolling_marble(red,i);

            if(red_mov.first == goal.first && red_mov.second == goal.second)
              board[red_mov.first][red_mov.second] = 5;
            else
              board[red_mov.first][red_mov.second] = 1;
            board[red.first][red.second] = 0;
            cout<<i<<endl;            
            print_board();
            blue_mov = rolling_marble(blue,i);
            
            if(red_mov.first == goal.first && red_mov.second == goal.second)
              board[red_mov.first][red_mov.second] = 5;
            else
              board[red_mov.first][red_mov.second] = 0;
            board[red.first][red.second] = 1;





          }
          if(i==2) //좌
          {
            blue_mov = rolling_marble(blue,i);
            
            if(blue_mov.first == goal.first && blue_mov.second == goal.second)
              board[blue_mov.first][blue_mov.second] = 5;
            else
              board[blue_mov.first][blue_mov.second] = 2;
            //움직이지 않을 경우도 고려해서 0으로 바꿔야함
            board[blue.first][blue.second] = 0;
            cout<<i<<endl;
            print_board();
            red_mov = rolling_marble(red,i);
            
            if(blue_mov.first == goal.first && blue_mov.second == goal.second)
              board[blue_mov.first][blue_mov.second] = 5;
            else
              board[blue_mov.first][blue_mov.second] = 0;
            
            board[blue.first][blue.second] = 2;
          }
          else //상하는 그냥 이동
          {
            
        red_mov = rolling_marble(red,i);
        blue_mov = rolling_marble(blue,i);
            
          }      
        }
      }
      //행이 같음 좌 우 이동 할때 더 그방향에 있는놈 먼저 이동
      else if(red_y == blue_y)
      {
        if(red_x<blue_x) //빨강이 위
        {
          if(i == 1) //상
          {
            red_mov = rolling_marble(red,i);

            if(red_mov.first == goal.first && red_mov.second == goal.second)
              board[red_mov.first][red_mov.second] = 5;
            else
              board[red_mov.first][red_mov.second] = 1;
            board[red.first][red.second] = 0;
            
            blue_mov = rolling_marble(blue,i);
            
            if(red_mov.first == goal.first && red_mov.second == goal.second)
              board[red_mov.first][red_mov.second] = 5;
            else
              board[red_mov.first][red_mov.second] = 0;
            board[red.first][red.second] = 1;





          }
          if(i== 0 ) //하
          {
            blue_mov = rolling_marble(blue,i);
            
            if(blue_mov.first == goal.first && blue_mov.second == goal.second)
              board[blue_mov.first][blue_mov.second] = 5;
            else
              board[blue_mov.first][blue_mov.second] = 2;
            
            board[blue.first][blue.second] = 0;
            
            red_mov = rolling_marble(red,i);
            
            if(blue_mov.first == goal.first && blue_mov.second == goal.second)
              board[blue_mov.first][blue_mov.second] = 5;
            else
              board[blue_mov.first][blue_mov.second] = 0;
            
            board[blue.first][blue.second] = 2;
          }
          else //좌우는 그냥 이동
          {
            
        red_mov = rolling_marble(red,i);
        blue_mov = rolling_marble(blue,i);
            
          }        
        }
        else //빨강이 아래
        {
          if(i == 0) //하
          {
            red_mov = rolling_marble(red,i);

            if(red_mov.first == goal.first && red_mov.second == goal.second)
              board[red_mov.first][red_mov.second] = 5;
            else
              board[red_mov.first][red_mov.second] = 1;
            board[red.first][red.second] = 0;
            
            blue_mov = rolling_marble(blue,i);
            
            if(red_mov.first == goal.first && red_mov.second == goal.second)
              board[red_mov.first][red_mov.second] = 5;
            else
              board[red_mov.first][red_mov.second] = 0;
            board[red.first][red.second] = 1;





          }
          if(i== 1) //상
          {
            blue_mov = rolling_marble(blue,i);
            
            if(blue_mov.first == goal.first && blue_mov.second == goal.second)
              board[blue_mov.first][blue_mov.second] = 5;
            else
              board[blue_mov.first][blue_mov.second] = 2;
            
            board[blue.first][blue.second] = 0;
            
            red_mov = rolling_marble(red,i);
            
            if(blue_mov.first == goal.first && blue_mov.second == goal.second)
              board[blue_mov.first][blue_mov.second] = 5;
            else
              board[blue_mov.first][blue_mov.second] = 0;
            
            board[blue.first][blue.second] = 2;
          }
          else //좌우는 그냥 이동
          {
            
        red_mov = rolling_marble(red,i);
        blue_mov = rolling_marble(blue,i);
            
          }
      }
    }
      //열이 같음 상 하 이동 할때 더 그방향에 있는놈 먼저 이동 
      //가로 막고 있으면 못감
      else{
        //같은행 같은 축이 아님
        //두개 다 가봤을 경우 안가기
        red_mov = rolling_marble(red,i);
        blue_mov = rolling_marble(blue,i);
        
      }
    if(!((red_visited[red_mov.first][red_mov.second] == true)&&(blue_visited[blue_mov.first][blue_mov.second] == true)))
        {
          //두개 다 트루가 아닌 경우
          red_moving.push_back(red_mov);
          blue_moving.push_back(blue_mov);
        }
      
    }
  for(int i=0;i<red_moving.size();i++)
    {
      int red_mov_x = red_moving[i].first;
      int red_mov_y = red_moving[i].second;
      int blue_mov_x = blue_moving[i].first;
      int blue_mov_y = blue_moving[i].second;
      int orig_red= board[red_mov_x][red_mov_y];
      int orig_blue = board[blue_mov_x][blue_mov_y];

      
      cout<<"red_moving!!::"<<endl;
      cout<<"from..."<<red.first<<' '<<red.second<<endl;
      cout<<"to.."<<red_mov_x<<' '<<red_mov_y<<endl;

      cout<<endl<<"blue_moving!!::"<<endl;
      cout<<"from..."<<blue.first<<' '<<blue.second<<endl;
      cout<<"to.."<<blue_mov_x<<' '<<blue_mov_y<<endl;
      
      red_visited[red_mov_x][red_mov_y] = true;
      blue_visited[blue_mov_x][blue_mov_y] = true;
      
      board[red.first][red.second] = 0;
      if(!((red_mov_x == goal.first)&& (red_mov_y == goal.second)))
        board[red_mov_x][red_mov_y] = 1;
      board[blue.first][blue.second] = 0;
      if(!((blue_mov_x == goal.first)&& (blue_mov_y == goal.second)))
        board[blue_mov_x][blue_mov_y] = 2;
      mini = min(mini, calc(make_pair(red_mov_x,red_mov_y),make_pair(blue_mov_x,blue_mov_y),iter+1));
      red_visited[red_mov_x][red_mov_y] = false;
      blue_visited[blue_mov_x][blue_mov_y] = false;
      board[red.first][red.second] = 1;
      board[red_mov_x][red_mov_y] = orig_red;
      board[blue.first][blue.second] = 2;
      board[blue_mov_x][blue_mov_y] = orig_blue;
      
    }
  return mini;
}
int main() {
  int N,M;
  cin>>N>>M;
  pair<int,int> red;
  pair<int,int> blue;

  for(int r = 0;r<N;r++)
    {
      for(int c=0;c<M;c++)
        {
          char tmp;
          cin>>tmp;
          //cout<<tmp;
          if(tmp == '.')
          {
           board[r][c]= 0; 
          }
          else if(tmp == '#')
          {
            board[r][c] = -1;
          }
          else if(tmp == 'O')
          {
            board[r][c]= 5;
            goal.first = r;
            goal.second = c;
          }
          else if(tmp == 'R')
          {
            board[r][c]=1;    
            red.first = r;
            red.second = c;
            red_visited[r][c] = true;
          }
          else
          {
            board[r][c] = 2;
            blue.first = r;
            blue.second = c;
            blue_visited[r][c] = true;
          }
          
        }

      
    }
  //cout<<goal.first<<' '<<goal.second<<endl;
  /*for(int r=0;r<N;r++)
    {
      for(int c=0;c<M;c++)
        {
          cout<<board[r][c]<<' ';
        }
      cout<<endl;
    }*/
    int tmp = calc(red,blue,0);
  if(tmp == INF)
    cout<<-1<<endl;
  else
    cout<<tmp<<endl;
}