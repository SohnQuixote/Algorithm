#include <iostream>
#include<vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 8;
vector <vector<int>> lab(8,vector <int>(8,0));
/*
  연구소
  0 빈곳
  1 벽
  벽 3개
  안전영역 최댓 값
  벽 3개 조합 구하기 - 브루트 포스 모든 조합 다 해봄 
  바이러스 펼쳐지는거 만들기 - DFS/ BFS?
  BFS queue 사용해서 가능한 좌표로 펼쳐나가기 시도
*/
//대각선 안감
int dx[4] = {-1,0,1,0}; // 세로축
int dy[4] = {0,1,0,-1}; //가로축
//가볼 수 있는 좌표 queue에 넣기
queue<pair<int,int>> plague_start;
vector<pair<int,int>> possible_wall;
vector<vector<int>> infection(vector<vector<int>> t_lab,int N,int M, queue<pair<int,int>>plague)
{
  while(!plague.empty())
    {
      //시작 위치
      int x = plague.front().first;
      int y = plague.front().second;
      plague.pop();
      for(int i=0;i<4;i++)
        {
          int mov_x = x+dx[i];
          int mov_y = y+dy[i];
         if(mov_x>=0 && mov_x < N && mov_y>=0 && mov_y<M)
         { //랩 안에 들어가 있으며 비어 있는 공간이면 전염병 
            if(t_lab[mov_x][mov_y] == 0)
            {
              t_lab[mov_x][mov_y] =2;
              plague.push(make_pair(mov_x,mov_y));
            }
         }
        }
      
    }
  return t_lab; //전염병 다 퍼짐
}
int calc_safe(vector<vector<int>> lab,int N,int M)
{
  int result = 0;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        {
          if(lab[i][j] == 0)
            result+=1;
        }
    }
  return result;
}
int main() {
  //std::cout << "Hello World!\n";
  int N,M;
  cin>>N>>M;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        {
          int temp;
          cin>>temp;
          if(temp == 0)
            possible_wall.push_back(make_pair(i,j)); // 가능한 벽 위치
          else if(temp == 2)
            plague_start.push(make_pair(i,j)); // 있는 전염병 위치
          lab[i][j] = temp;
        }
    }
    vector<vector<int>> test_labs = lab;
    queue<pair<int,int>> plague = plague_start;
    int result = -987654321;
    vector<int> comb;
    for(int i=0;i<possible_wall.size();i++)
      comb.push_back(0);
    for(int i=0;i<3;i++)
      comb[i] = 1;
    sort(comb.begin(),comb.end());
    do{
        test_labs = lab;
        plague = plague_start;
        for(int i=0;i<comb.size();i++)
          {
            if(comb[i] == 1)
            {
              int x = possible_wall[i].first;
              int y = possible_wall[i].second;
              test_labs[x][y] = 1;
              //가능한 벽의 위치 모두 조합으로 시험
            }
          }
        test_labs = infection(test_labs,N,M,plague);
        /*cout<<"벽 건설"<<endl<<endl;
        for(int i=0;i<N;i++)
          {
            for(int j = 0;j<M;j++)
              {
                cout<<test_labs[i][j]<<' ';
              }
            cout <<endl<<endl;
          }
        test_labs = infection(test_labs,N,M,plague);
        cout<<"전염병 후"<<endl<<endl;
        for(int i=0;i<N;i++)
          {
            for(int j = 0;j<M;j++)
              {
                cout<<test_labs[i][j]<<' ';
              }
            cout <<endl<<endl;
          }*/
        result = max(result,calc_safe(test_labs,N,M));
      }while(next_permutation(comb.begin(),comb.end()));
    //벽을 3개 세워보고 인자 전달 -> 전염병 퍼뜨림 -> 0인 공간 계산(8*8)
  cout<<result<<endl;
  //입력 완료
}