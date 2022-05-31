#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
/*
    블록 이동하기
    로봇 2*1
    처음 시작 지점 - (1,1) , (1,2)
    원하는 도착 지점 N*N
    빈 곳 - 0 블록 -1 로봇 2
    회전 걸리는 시간 1초
    이동 1초
    N,N 이동 필요 최소시간 return
*/
const int INF = 987654321;
int dx[4] = {-1,1,0,0}; //상하 좌우
int dy[4] = {0,0,-1,1};
int N;
int rot_two_dx_hor[2] = {1,-1}; 
int rot_two_dy_hor[2] = {-1,-1}; //밑 90도 위 90도
int rot_one_dx_hor[2] = {1,-1};
int rot_one_dy_hor[2] = {1,1}; // 밑 90도 위 90도 
//가로 회전
int rot_one_dx_ver[2] ={1,1};
int rot_one_dy_ver[2] = {-1,1}; //좌 90도 우 90도
int rot_two_dx_ver[2] = {-1,-1};
int rot_two_dy_ver[2] = {-1,1}; //좌 90 우 90
bool visited[101][101][101][101][2]; //세로로 들렀나 가로로 들렀나?
//수직 회전 180도회전 -> 이동하는게 나음
//가로로 있었을 때 회전 180도 회전하면 이동하는거랑 똑같음
//회전하는 좌표만 구하면 됨
//매번 로봇 이동한 지도 매개변수 처음에는 (1,1) , (1,2) 
//매개변수에 시간도 같이 return하는 값은 min한거
bool calc_range(int a,int R)
{
    if(a>=0 && a< R)
        return true;
    return false;
}
int mov_rob(vector<vector<int>> board)
{
    //재귀로 현재 가볼 수 있는데 다 가봄 - 좌표 전달
    //재귀가 필요한가? -> board때문에
    //재귀로 하면 queue가 필요한가?
    //board를 바꿀 필요가 있는가? - 없다
    //이미 가본 곳을 저장할 필요가 있는가? - 있다 -bool로 가본 좌표 + state
    //대각선도 존재하고 이상한데로 건너뜀 - 로봇 형태 유지가 안됨
    queue<tuple<int,int,int,int,int,int>> q;
    q.push(make_tuple(0,0,0,1,0,0)); //좌표 + 시간 + 상태
    int result = INF;
    //q.push(make_tuple(1,1,1,2,0,0));//시작 지점 + 걸린 시간 + 가로/세로
    while(!q.empty())
    {
        int x_one = get<0>(q.front());
        int y_one = get<1>(q.front());
        int x_two = get<2>(q.front());
        int y_two = get<3>(q.front());
        
        //언제나 one이 two보다 왼쪽/위
        int sec = get<4>(q.front());
        if((x_one == N-1 && y_one == N-1) || (x_two == N-1 && y_two == N-1))
        {
            result = min(result, sec);
        }
        int state = get<5>(q.front());
        visited[x_one][y_one][x_two][y_two][state] = true;
        q.pop();
        board[x_one][y_one] = 2;
        board[x_two][y_two] = 4;
        cout<<"start"<<sec<<endl<<endl;
        for(int i=0;i<N;i++)
          {
            for(int j=0;j<N;j++)
              {
                cout<<board[i][j]<<' ';
              }
            cout<<endl;
          }
        board[x_one][y_one] = 0;
        board[x_two][y_two] = 0;
        //좌표 계산 해놓고 조건 검사
        int mov_x_one;
        int mov_x_two;
        int mov_y_one;
        int mov_y_two;
        for(int i=0;i<4;i++)
        {
            //상하좌우 이동
            mov_x_one = x_one+dx[i];
            mov_y_one = y_one +dy[i];
            mov_y_two = y_two +dy[i];
            mov_x_two = x_two +dx[i];
            if(calc_range(mov_x_one,N) && calc_range(mov_y_one,N) && calc_range(mov_x_two,N) && calc_range(mov_y_two,N) && board[mov_x_one][mov_y_one] != 1 && board[mov_x_two][mov_y_two] != 1 && visited[mov_x_one][mov_y_one][mov_x_two][mov_y_two][state] == false)
            { //범위 안에 있고 가려는 곳에 장애물 없음 그리고 해당 상태로 가본적이 없음
                //visited[mov_x_one][mov_y_one][mov_x_two][mov_y_two][state] = true;
                q.push(make_tuple(mov_x_one,mov_y_one,mov_x_two,mov_y_two,sec+1,state));
            }
        }
        //회전
        
        if(state == 0) //가로에서 세로
        {
            //two 부분 회전
            for(int i=0;i<2;i++)
            {
            if (i == 0 )//밑 90도
            {
                mov_x_two = x_two +rot_two_dx_hor[i];
                mov_y_two = y_two +rot_two_dy_hor[i];
                mov_x_one = x_one;
                mov_y_one = y_one;
                if(calc_range(mov_x_one,N) && calc_range(mov_y_one,N) && calc_range(mov_x_two,N) && calc_range(mov_y_two,N) && board[mov_x_one][mov_y_one] != 1 && board[mov_x_two][mov_y_two] != 1 && visited[mov_x_one][mov_y_one][mov_x_two][mov_y_two][1] == false && board[x_two+1][y_two] != 1) //밑 회전 구간에 벽 존재 X
            {   q.push(make_tuple(mov_x_one,mov_y_one,mov_x_two,mov_y_two,sec+1,1));
            }
            }
            
            else//위 90도
            {
                mov_x_one = x_two+ rot_two_dx_hor[i];
                mov_y_one = y_two + rot_two_dy_hor[i];
                mov_x_two = x_one;
                mov_y_two = y_one;
                   if(calc_range(mov_x_one,N) && calc_range(mov_y_one,N) && calc_range(mov_x_two,N) && calc_range(mov_y_two,N) && board[mov_x_one][mov_y_one] != 1 && board[mov_x_two][mov_y_two] != 1 && visited[mov_x_one][mov_y_one][mov_x_two][mov_y_two][1] == false && board[x_two -1][y_two] !=1)
            {   q.push(make_tuple(mov_x_one,mov_y_one,mov_x_two,mov_y_two,sec+1,1));
            }
            }
             
            }
            
            //one 부분 회전
            for(int i=0;i<2;i++)
            {
                if(i==0) //밑 90도
                {
                    mov_x_one = x_two;
                    mov_y_one = y_two;
                    mov_x_two = x_one + rot_one_dx_hor[i];
                    mov_y_two = y_one +rot_one_dy_hor[i];
                if(calc_range(mov_x_one,N) && calc_range(mov_y_one,N) && calc_range(mov_x_two,N) && calc_range(mov_y_two,N) && board[mov_x_one][mov_y_one] != 1 && board[mov_x_two][mov_y_two] != 1 && visited[mov_x_one][mov_y_one][mov_x_two][mov_y_two][1] == false && board[x_one+1][y_one] !=1)
            {   q.push(make_tuple(mov_x_one,mov_y_one,mov_x_two,mov_y_two,sec+1,1));
            }
                }
                else //위 90도
                {
                    mov_x_two = x_two;
                    mov_y_two = y_two;
                    mov_x_one = x_one + rot_one_dx_hor[i];
                    mov_y_one = x_one +rot_one_dy_hor[i];
                    if(calc_range(mov_x_one,N) && calc_range(mov_y_one,N) && calc_range(mov_x_two,N) && calc_range(mov_y_two,N) && board[mov_x_one][mov_y_one] != 1 && board[mov_x_two][mov_y_two] != 1 && visited[mov_x_one][mov_y_one][mov_x_two][mov_y_two][1] == false && board[x_one-1][y_one] != 1)
            {   q.push(make_tuple(mov_x_one,mov_y_one,mov_x_two,mov_y_two,sec+1,1));
            }
                }
            }
        }
        else //세로에서 가로
        {
            for(int i=0;i<2;i++)
            {
                //one 부분
                if(i==0) //좌 90
                {
                    mov_x_one = x_one + rot_one_dx_ver[i];
                    mov_y_one = y_one + rot_one_dy_ver[i];
                    mov_x_two = x_two;
                    mov_y_two = y_two;
                       if(calc_range(mov_x_one,N) && calc_range(mov_y_one,N) && calc_range(mov_x_two,N) && calc_range(mov_y_two,N) && board[mov_x_one][mov_y_one] != 1 && board[mov_x_two][mov_y_two] != 1 && visited[mov_x_one][mov_y_one][mov_x_two][mov_y_two][0] == false && board[x_one][y_one-1] != 1)
            {   q.push(make_tuple(mov_x_one,mov_y_one,mov_x_two,mov_y_two,sec+1,0));
            }
                }                
                else //우 90
                {
                       if(calc_range(mov_x_one,N) && calc_range(mov_y_one,N) && calc_range(mov_x_two,N) && calc_range(mov_y_two,N) && board[mov_x_one][mov_y_one] != 1 && board[mov_x_two][mov_y_two] != 1 && visited[mov_x_one][mov_y_one][mov_x_two][mov_y_two][0] == false && board[x_one][y_one+1] != 1)
            {   q.push(make_tuple(mov_x_one,mov_y_one,mov_x_two,mov_y_two,sec+1,0));
            }
                    mov_x_one = x_two;
                    mov_y_one = y_two;
                    mov_x_two = x_one + rot_one_dx_ver[i];
                    mov_y_two = y_one + rot_one_dy_ver[i];
                }
             
                
            }
            for(int i=0;i<2;i++)
            {
                //two 부분
                if(i==0) //좌 90
                {
                    mov_x_two = x_one;
                    mov_y_two = y_one;
                    mov_x_one = x_two+rot_two_dx_ver[i];
                    mov_y_one = y_two + rot_two_dy_ver[i];
                    if(calc_range(mov_x_one,N) && calc_range(mov_y_one,N) && calc_range(mov_x_two,N) && calc_range(mov_y_two,N) && board[mov_x_one][mov_y_one] != 1 && board[mov_x_two][mov_y_two] != 1 && visited[mov_x_one][mov_y_one][mov_x_two][mov_y_two][0] == false && board[x_two][y_two-1] != 1)
            {   q.push(make_tuple(mov_x_one,mov_y_one,mov_x_two,mov_y_two,sec+1,0));
            }
                }
                else //우 90
                {
                    mov_x_one = x_one;
                    mov_y_one = y_one;
                    mov_x_two = x_two+rot_two_dx_ver[i];
                    mov_y_two = y_two+rot_two_dy_ver[i];
                    if(calc_range(mov_x_one,N) && calc_range(mov_y_one,N) && calc_range(mov_x_two,N) && calc_range(mov_y_two,N) && board[mov_x_one][mov_y_one] != 1 && board[mov_x_two][mov_y_two] != 1 && visited[mov_x_one][mov_y_one][mov_x_two][mov_y_two][0] == false && board[x_two][y_two+1] != 1)
            {   q.push(make_tuple(mov_x_one,mov_y_one,mov_x_two,mov_y_two,sec+1,0));
            }
                }
            
            }
        }
        }
  return result;
}
int solution(vector<vector<int>> board) {
    //board 1,1 ~ 100,100
    N = board[0].size();
    //board[1][1] = 2;
    //board[1][2] = 2;
    int answer = mov_rob(board);
    return answer;
}
int main()
{
  vector<vector<int>> board = {{0,0,0,1,1},{0,0,0,1,0},{0,1,0,1,1},{1,1,0,0,1},{0,0,0,0}};
  cout<<solution(board)<<endl;
}