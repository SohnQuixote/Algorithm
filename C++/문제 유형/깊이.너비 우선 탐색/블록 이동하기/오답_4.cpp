#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
const int MAX = 100;
bool visited[MAX][MAX][2];
int dx[4] = {-1,1,0,0}; //상하 좌우
int dy[4] = {0,0,-1,1};
int N;
const int INF = 987654321;
bool calc_range(int a,int R)
{
    if(a>=0 && a< R)
        return true;
    return false;
}
int solution(vector<vector<int>> board) {
    N = board[0].size();
    int answer = INF;
    queue<tuple<int,int,int,int>>q;// 기준좌표 상태 시간
    q.push(make_tuple(0,0,0,0)); // 0 -> 기준 좌표 y+1 1 -> 기준 좌표 x+1
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            for(int k=0;k<2;k++)
            {
                visited[i][j][k] = false;
            }
        }
    }
    visited[0][0][0] = true;
    //bool 배열 true인데 대체 왜가는건지 모르겠음
    while(!q.empty())
    {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int state = get<2>(q.front());
        int sec = get<3>(q.front());
        
        q.pop();
        int mov_x;
        int mov_y;
        switch(state)
        {
            case 0:
                //우측으로
                if((x==N-1) && (y+1 == N-1))
                {
                    answer = min(answer,sec);
                    continue;
                }
                for(int i=0;i<4;i++)
                {
                    mov_x = x+dx[i];
                    mov_y = y+dy[i];
                    if(calc_range(mov_x,N) && calc_range(mov_y,N) && calc_range(mov_y+1,N) && visited[mov_x][mov_y][state] == false)
                    {
                        visited[mov_x][mov_y][state] = true;
                        q.push(make_tuple(mov_x,mov_y,state,sec+1));   
                        
                    }
                }
                //회전
                //기준 좌표 기준 위로 회전 or 밑으로 회전
                if(x>=1) //위로 회전
                {
                    
                    if(board[x-1][y+1] != 1 && board[x-1][y] !=1)
                    {
                        if(visited[x-1][y][1] == false)
                        {
                            visited[x-1][y][1] = true;
                            q.push(make_tuple(x-1,y,1,sec+1)); //기준점
                        }
                        if(visited[x-1][y+1][1] == false)
                        {
                            visited[x-1][y+1][1] = true;
                            q.push(make_tuple(x-1,y+1,1,sec+1));
                        }
                    }
                    
                }
                if(x<=N-2) //밑으로 회전
                {
                    if(board[x+1][y] != 1 && board[x+1][y+1] != 1)
                    {
                        if(visited[x][y][1] == false)
                        {
                            visited[x][y][1] =true;
                            q.push(make_tuple(x,y,1,sec+1));
                        }
                        if(visited[x][y+1][1] == false)
                        {
                            visited[x][y+1][1] = true;
                            q.push(make_tuple(x,y+1,1,sec+1));
                        }
                        
                    }
                }
                break;
            case 1:
                //밑으로
                if((x+1 == N-1) && (y == N-1))
                {
                    answer = min(answer,sec);
                    continue;
                }
                for(int i=0;i<4;i++)
                {
                    mov_x = x+dx[i];
                    mov_y = y+dy[i];
                    if(calc_range(mov_x,N) && calc_range(mov_x+1,N) && calc_range(mov_y,N) && visited[mov_x][mov_y][state] == false)
                    {
                        visited[mov_x][mov_y][state] =true;
                        q.push(make_tuple(mov_x,mov_y,state,sec+1));   
                        
                    }
                }
                if(y>=1)
                {
                    if(board[x][y-1] != 1 && board[x+1][y-1] != 1 )
                    {
                        if(visited[x][y-1][0] == false)
                        {
                            visited[x][y-1][0] = true;
                            q.push(make_tuple(x,y-1,0,sec+1));
                        }
                        if(visited[x+1][y-1][0] == false)
                        {
                            visited[x+1][y-1][0] = true;
                            q.push(make_tuple(x+1,y-1,0,sec+1));
                        }
                        
                    }
                }
                if(y<=N-2)
                {
                    if(board[x][y+1] != 1 && board[x+1][y+1] != 1)
                    {
                        if(visited[x][y][0] == false)
                        {
                            visited[x][y][0] = true;
                            q.push(make_tuple(x,y,0,sec+1));
                        }
                        if(visited[x+1][y][0] == false)
                        {
                            visited[x+1][y][0] = true;
                            q.push(make_tuple(x+1,y,0,sec+1));
                        }
                        
                    }
                    
                    
                }
                break;
            default:
                break;
                
        }
        
        
        
    }
    return answer;
}
int main()
{
  vector<vector<int>> board = {{0,0,0,1,1},{0,0,0,1,0},{0,1,0,1,1},{1,1,0,0,1},{0,0,0,0}};
  cout<<solution(board)<<endl;
}