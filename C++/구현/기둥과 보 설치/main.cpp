#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
    기둥과 보 설치
    기둥과 보 길이 1인 선분
    벽면 구조물 자동 세우는 로봇
    벽면 n * n
    기둥 - 바닥위 보 끝부분 위 다른 기둥 위
    보 - 한쪽 끝부분 기둥 위 양쪽 끝부분 다른보와 연결
    너무 복잡하게 풀었음
*/
const int MAX = 101;
pair<int,int> maps[MAX][MAX];
//0,0 ~ 100,100 first 기둥 second 보
bool chk_cnd(int n)
{
    //바꿔도 되면 true 안되면 false
    bool result = true;
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(maps[i][j].first == 1)
            {
                if(j!=0)
                {
                    //기둥 바닥에 없음
                    if(maps[i][j].second == 0 && (i==0 || maps[i-1][j].second == 0)  && maps[i][j-1].first == 0)
                    {
                        //밑에 기둥 없고 보도 없음
                        result = false;
                        return result;
                    }
                }
                //기둥 쳌
            }
            if(maps[i][j].second == 1)
            {
                //보 쳌
                if(maps[i][j-1].first == 0 && maps[i+1][j-1].first ==0)
                {
                    //밑에 기둥 두개 없음
                    if((i==0 || maps[i-1][j].second == 0) || (i==n-1 || maps[i+1][j].second == 0))
                    {
                        result = false;
                        return false;
                    }
                }
            }
        }
    }
    return result;
}
bool cmp(vector<int>a , vector<int>b)
{
    if(a[0] == b[0])
    {
        if(a[1] == b[1])
        {
            return a[2] <b[2];
        }
        else
        {
            return a[1]<b[1];
        }
    }
    
    return a[0]<b[0];
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    //n 벽면의 크기
    //build_frame 기둥 보 설치 삭제 작업 조건 만족하지 않으면 무시됨
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            maps[i][j] = make_pair(0,0);
        }
    }
    int task_number = build_frame.size();
    vector<vector<int>> answer;
    //task_number pending 된 작업의 수
    //[x,y,a,b] -> x,y 설치/삭제 교차점 좌표 a- 0기둥 1보 b 0삭제 1설치
    //보는 무조건 교차점 기준 오른쪽 설치/삭제 기둥은 교차점 기준 무조건 위쪽 설치/삭제
    for(int i=0;i<task_number;i++)
    {
        int x,y,a,b;
        x = build_frame[i][0];
        y = build_frame[i][1];
        a = build_frame[i][2];
        b = build_frame[i][3];
        //maps first 기둥 second 보
        switch(b)
        {
            case 1:
              
            //설치
                switch(a)
                {
                    case 0:
                    //기둥 설
                    if(y ==0)
                    {
                        maps[x][y] = make_pair(1,0);
                         // x , y+1 까지 기둥
                    }
                    else if(maps[x][y-1].first == 1 || maps[x][y].second == 1 || (x>=1 && maps[x-1][y].second == 1 ) )
                    {
                        int bo = maps[x][y].second;
                        maps[x][y] = make_pair(1,bo);
                       //밑에가 기둥이나(x,y-1 ~ x,y) 보의 왼쪽 끝부분(x,y ~ x+1,y) 보의 오른쪽 끝부분(x-1,y ~ x,y)
                    }
                    //조건 만족 안하면 무시
                    break;
                    case 1:
                    //보 설
                    if(maps[x][y-1].first == 1 || maps[x+1][y-1].first == 1) //보는 무조건 오른쪽이니까 조건 벗어날 일 없음
                    {
                        //한쪽 끝부분 기둥위
                        //y범위 1~n x 범위 0, n-1
                        maps[x][y] = make_pair(maps[x][y].first ,1);
                    }
                    else if( x>=1 )
                    {
                        if(maps[x-1][y].second == 1 && maps[x+1][y].second == 1)
                        {
                            //양쪽 끝이 보로 연결
                            maps[x][y] = make_pair(maps[x][y].first,1);
                        }
                    }
                    break;
                    default:
                    
                    break;
                }
            //설치는 문제 없는 것으로 보임
            break;
            case 0:
            //삭제
                switch(a)
                {
                    
                    //안되는 조건 발견하면 false 하는 걸로 변경
                    //되는 조건으로 보면 너무 복잡
                    case 0:
                    //기둥 삭제
                        if(maps[x][y].first == 1)
                        {
                            maps[x][y] = make_pair(0,maps[x][y].second);
                            if(!chk_cnd(n))
                                maps[x][y] = make_pair(1,maps[x][y].second);
                            //위에 보 우측 꼭짓점 있는데 양옆에 보도 없고 지탱할 기둥도 없음
                        }
                    
                    break;
                    case 1:
                    //보 삭제
                        if(maps[x][y].second == 1)
                        {
                            maps[x][y] = make_pair(maps[x][y].first ,0);
                            if(!chk_cnd(n))
                                maps[x][y] = make_pair(maps[x][y].first ,1);
                            //위에 보 우측 꼭짓점 있는데 양옆에 보도 없고 지탱할 기둥도 없음
                        }
                    break;
                    default:
                    break;
                        
                }
                
            break;
                
            default:
            break;
                
                
                
                
        }
    }
    vector<int> temp(3);
    for(int i=0;i<n+1;i++)
    {
        
        for(int j = 0;j<n+1;j++)
        {
            if(maps[j][i].first == 1)
            {
                temp[0] = j;
                temp[1] = i;
                temp[2] = 0;
                answer.push_back(temp);
            }
            if(maps[j][i].second == 1)
            {
                temp[0] = j;
                temp[1] = i;
                temp[2] = 1;
                answer.push_back(temp);
            }
        }
    }
    sort(answer.begin(),answer.end(),cmp);
    return answer;
}
int main() {
  //std::cout << "Hello World!\n";
  //MAPS[0][0] = make_pair(1,2);
  int n=5;
  vector<vector<int>> build_frame = {{1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},{5,0,0,1},{5,1,0,1},{4,2,1,1,},{3,2,1,1}};
  solution(5,build_frame);
}