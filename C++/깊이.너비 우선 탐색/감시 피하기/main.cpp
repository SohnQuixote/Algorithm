#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;
/*
  감시망 피하기
  N*N 크기 복도
  선생 상하좌우 감시 거리 상관없이 다봄
  선생 T 학생 S 장애물 O
  빈칸 중 장애물 3개 설치
  -조합? 장애물 설치할 좌표
  -선생 감시망 - queue로 이동 S만나면 바로 false
*/
const int MAX = 7;
//int map[MAX][MAX] = {0,}; //비어있는 곳 0 학생 1 선생 2 벽 3
vector < vector <int> > map(MAX,vector <int>(MAX,0));
//vector < vector <int> > tmp_map(MAX,vector <int>(MAX,0));
vector<pair<int,int>> walls; //가능한 벽들 좌표 - 벽을 찍고 맵으로 계산
vector<pair<int,int>> students; // 학생들 좌표 - 사용 안할 거 같음
vector<pair<int,int>> teachers; //선생들 좌표 - BFS주체
int dx[4] = {-1,0,1,0}; //한번 가기 시작하면 해당 방향으로 쭉 이동 벽 만나면 멈춤 학생 만나면 아예 새로 시작
int dy[4] = {0,1,0,-1};
int N;
bool calc(vector<vector<int>>tmp_map)
{
  queue<tuple<int,int,int>> q; //좌표 + 방향
  bool result = true;
      for(int j = 0;j<teachers.size();j++)
        {
          int x = teachers[j].first;
          int y = teachers[j].second;
          for(int i=0;i<4;i++)
            {
              q.push(make_tuple(x,y,i));
            }
          
        }
  //큐 안에 이동 방향과 선생 정보 모두 존재
  while(!q.empty())
    {
      int x = get<0>(q.front());
      int y = get<1>(q.front());
      int dir = get<2>(q.front());
      q.pop();
      int mov_x = x+dx[dir];
      int mov_y = y+dy[dir];
      if(mov_x>=0 && mov_x < N && mov_y >=0 && mov_y < N)
      {
        if(tmp_map[mov_x][mov_y] == 0)
        {
          //비어 있음
         q.push(make_tuple(mov_x,mov_y,dir)); 
        }
        else if(tmp_map[mov_x][mov_y] == 1)
        {
          result = false;
          break;
        }
        //선생이나 벽은 아예 큐에 안넣음 --선생이 진행방향에 있으면 그선생도 어차피 그쪽으로 봄
      }
    }
  return result;
  }
int main() {
  cin>>N;
  vector<int> comb;
  bool answer = false;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          char temp;
          cin>>temp;
          if(temp == 'X')
          {//비어있는 곳
            map[i][j] = 0;
            walls.push_back(make_pair(i,j));
          }
          else if(temp == 'S')
          {
             map[i][j] = 1;
            students.push_back(make_pair(i,j));
          }
          else{
            map[i][j] = 2;
            teachers.push_back(make_pair(i,j));
          }
        }
    }
  //for(int i=0;i<teachers.size();i++)
    //cout<<' '<<teachers[i].first <<' '<<teachers[i].second<<' '<<endl;
  /*for(int i=0;i<N;i++)
    {
    for(int j=0;j<N;j++)
      cout<<map[i][j]<<' ';
    cout<<endl;
    }*/
  //cout<<walls.size();
  for(int i=0;i<walls.size();i++)
    comb.push_back(0);
  for(int i=0;i<3;i++)
    comb[i] = 1;
    /*vector<vector<int>>tmp_map = map;
    for(int i=0;i<N;i++)
    {
    for(int j=0;j<N;j++)
      cout<<tmp_map[i][j]<<' ';
    cout<<endl;
    }*/
  //for(int i=0;i<comb.size();i++)
    //cout<<comb[i]<<endl;
  sort(comb.begin(),comb.end());
  do{
      vector<vector<int>>tmp_map = map;
    /*for(int i=0;i<N;i++)
    {
    for(int j=0;j<N;j++)
      cout<<tmp_map[i][j]<<' ';
    cout<<endl;
    }*/
      for(int i=0;i<comb.size();i++)
        {
          if(comb[i] == 1)
          {
            int x = walls[i].first;
            int y = walls[i].second;
            tmp_map[x][y] = 3;//벽
          }
        }
      if(calc(tmp_map))
      {
        cout<<"YES"<<endl;
        return 0;
      }
    }while(next_permutation(comb.begin(),comb.end()));
  if(!answer)
  {
    cout<<"NO"<<endl;
    return 0;
  }
}