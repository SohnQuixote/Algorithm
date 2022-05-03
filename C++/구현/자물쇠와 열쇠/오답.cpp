#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
#include <string>
#include <vector>

using namespace std;
/*
    자물쇠와 열쇠
    잠겨있는 자물쇠 N * N 정사각 격자 형태
    열쇠 M,M
    열쇠는 회전 이동 가능 벗어난 부분은 영향 X
    자물쇠 영역내 돌기 홈 부분 정확하게 일치
    열수 있으면 true 열 수 없으면 false
*/
vector<vector<int>> spinning(vector<vector<int>> k, int M)
{
    //회전할 열쇠 k, k의 크기 M
    vector<vector<int>> result;
    vector<int> temp;
    for(int i=0;i<M;i++)
    {
        temp.clear();
        for(int j=M-1;j>-1;j--)
        {
            temp.push_back(k[j][i]);
        }
        result.push_back(temp);
    }
    return result;
    //90도 회전 되는 것 확인
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    //lock의 빈부분 0을 key로 채워야함
    //key의 크기는 lock보다 작거나 같음
    //모두 다 시도해보는게 맞음
    bool answer = true;
    int N = lock[0].size();
    int M = key[0].size();
    const int unlocked_or_not = N*N; //풀리려면 모두다 1이어야 함
    int current_lock = 0;
    //vector<vector<int>> spinnned_key; // 90,180,270도 회전하고 가능한 경우의 수 전부 구함
    for(int i = 0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            current_lock += lock[i][j];
        }
    }
    if(current_lock == unlocked_or_not)
    {
        answer = true;
        return answer;
        //홈이 없으면 이미 열린거로 간주
    }
    answer = false;
    for(int i=0;i<4;i++)
    {
        key = spinning(key,M);
        //90도부터 회전시켜서 360도까지 확인
        //다 더해보고 unlocked_or_not이면 true return
        //더하는 방법 생각이 안남 더하고 %2를 해서 겹치면 0으로 처리
        //세로 가로 이동수 N+2M-2
        vector<vector<int>> play_ground; // 전체 key와 lock을 갖고 있는 변수
        vector<int> play_ground_row;
        for(int i=0;i<(N+2*M-2);i++)
        {
            play_ground_row.clear();
            for(int j =0;j<(N+2*M-2);j++)
            {
                play_ground_row.push_back(0);
            }
            play_ground.push_back(play_ground_row);
        }
        //0 으로 초기화 완료
        //중간 지점에 키 넣어야 함
        for(int i = M-1;i<M-1+N;i++)
        {
            for(int j = M-1;j<M-1+N;j++)
            {
                play_ground[i][j] = lock[i-(M-1)][j-(M-1)];
            }
            
        }
        //가운데 부분에 키 있는 play_ground 완성
        
        //벡터는 대입이 깊은 복사
        for(int i=0;i<N+M-1;i++)
        {
            for(int j=0;j<N+M-1;j++)
            {
                vector<vector<int>> unlocking_play_ground = play_ground;
                //시작점 0~ N+M-1
                for(int r = 0;r<M;r++)
                {
                    for(int w=0;w<M;w++)
                    {
                        unlocking_play_ground[i+r][i+w] =(unlocking_play_ground[i+r][i+w] + key[r][w]) %2;
                    }
                }
                current_lock = 0;
                //열렸는지 체크
        for(int i = M-1;i<M-1+N;i++)
        {
            for(int j = M-1;j<M-1+N;j++)
            {
                current_lock+= unlocking_play_ground[i][j];
            }
            
        }
                if(current_lock == unlocked_or_not)
                {
                    answer =true;
                    return answer;
                }
            }
        }
    }
    
    
    
    
    
    return answer;
}
int main() {
  //std::cout << "Hello World!\n";
  vector<vector<int>> test = {{0,0,0},{1,0,0},{0,1,1}};
  for(int i=0;i<test[0].size();i++)
    {
      for(int j=0;j<test[0].size();j++)
        {
          cout<<test[i][j]<<' ';
        }
      cout<<endl;
    }
  vector<vector<int>> spinned_test = spinning(test,3);
  for(int i=0;i<test[0].size();i++)
    {
      for(int j=0;j<test[0].size();j++)
        {
          cout<<spinned_test[i][j]<<' ';
        }
      cout<<endl;
    }
  //cout<<accumulate(test.begin(),test.end(),0)<<endl;
  //cout<<test<<endl;
}