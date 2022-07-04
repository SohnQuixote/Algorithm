#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
  상어 초등학교
  교실 N*N 격자
  배치 조건
  1. 좋아하는 학생 인접한 칸에 가장 많은 칸
  2. 여러개일 경우 인접한 칸 중 비어있는 칸 가장 많은 칸
  3. 여러 개일경우 행 작은칸
    열 작은 칸
  학생 순서대로 배치
*/
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int N;
vector<vector<int>>room(20,vector<int>(20,0));
void print_room()
{
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          cout<<room[i][j]<<' ';
        }
        cout <<endl;
      
    }
}
bool calc_range(int a, int b)
{
  if(a>=0 && a<N && b>=0 && b<N)
    return true;
  return false;
}
int accum_like(int x, int y,vector<bool> prf)
{
  int result = 0;
  for(int d=0;d<4;d++)
    {
      int mov_x = x+dx[d];
      int mov_y = y+dy[d];
      if(calc_range(mov_x,mov_y))
      {
        if(room[mov_x][mov_y]>0 && prf[room[mov_x][mov_y]])
        {
          result++;
        }

        
      }
    }
  return result;
}
int find_like(vector<bool>prf,vector<vector<bool>> &cand)
{
  //찾은 수 반환
  int result = 0;
  int max_sat = 0;
  vector<vector<int>> tmp(N,vector<int>(N,-1));//인접한 좋아하는 학생 수 저장 배열
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          if(room[i][j] ==0)
          {
            tmp[i][j] = accum_like(i,j,prf);
            max_sat = max(max_sat,tmp[i][j]);
          }
        }
    }
    for(int i=0;i<N;i++)
      {
        for(int j=0;j<N;j++)
          {
            if(tmp[i][j] == max_sat && room[i][j] == 0) //무조건 비어있어야함
            {
              cand[i][j] = true;
              result++;
            }
            
          }
        
      }
  return result;
}
int accum_empty(int x,int y)
{
  int result = 0;
  for(int d= 0;d<4;d++)
    {
      int mov_x = x+dx[d];
      int mov_y = y+dy[d];
      if(calc_range(mov_x,mov_y))
      {
        if(room[mov_x][mov_y] == 0)
          result++;
        
      } 
    }
  return result;
}
vector<vector<bool>> find_empty(vector<vector<bool>> cand)
{
  //복수개여도 그냥 반복문 돌려서 위에 있는거 찾으면 됨
  vector<vector<bool>> result(N,vector<bool>(N,false));
  vector<vector<int>> tmp(N,vector<int>(N,-1));
  int max_empty = 0;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          if(cand[i][j])
          {
            tmp[i][j] = accum_empty(i,j);
            max_empty = max(max_empty,tmp[i][j]);
          }
        }
    }
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          if(tmp[i][j] == max_empty)
            result[i][j] = true;
          
        }
    }

  
  return result;
}
void put_stud(int s,vector<bool>prf)
{
  //1단계 좋아하는 학생 가장 많은 칸
  vector<vector<bool>>cand(N,vector<bool>(N,false));
  int like_stud = find_like(prf,cand);
  if(like_stud == 1)
  {
    //후보 한개
    for(int i=0;i<N;i++)
      {
        for(int j=0;j<N;j++)
          {
            if(cand[i][j] == true)
            {
              //cout<<i<<' '<<j<<' '<<s<<endl;
              room[i][j]  = s;
              return;
            }
          }
      }
  }
  else
  {
    //후보 한개 이상
    //2단계 
    cand = find_empty(cand);
    for(int i =0;i<N;i++)
      {
        for(int j=0;j<N;j++)
          {
            if(cand[i][j])
            {
              //cout<<i<<' '<<j<<' '<<s<<endl;
              room[i][j] = s;
              return; 
            }
          }
        
      }
  }
  //print_room();
}
int accum_sat(int x, int y,vector<bool>prf)
{
  int result =0;
  for(int d=0;d<4;d++)
    {
      int mov_x = x+dx[d];
      int mov_y = y+dy[d];
      if(calc_range(mov_x,mov_y))
      {
        if(prf[room[mov_x][mov_y]])
          result++;
        
      }
    }
  if(result == 0)
    return 0;
  else if(result ==1)
    return 1;
  else if(result == 2)
    return 10;
  else if(result == 3)
    return 100;
  else
    return 1000;
}
int calc_sat(vector<vector<bool>>prf)
{
  int result =0;
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<N;j++)
        {
          result+=accum_sat(i,j,prf[room[i][j]]);
        }
      
    }
  return result;
}
int main() {
  cin>>N;
  int pref_size = (N*N)+1;
  vector<vector<bool>>pref(pref_size,vector<bool>(pref_size,false));
  queue<int>seq;
  for(int i=0;i<N*N;i++)
    {
      int a,b,c,d,e;
      cin>>a>>b>>c>>d>>e;
      seq.push(a);
      pref[a][b] = true;
      pref[a][c] = true;
      pref[a][d] = true;
      pref[a][e] = true;
    }
  while(!seq.empty())
    {
      int student = seq.front();
      //cout<<student<<endl;
      
      put_stud(student,pref[student]);
      //print_room();
      seq.pop();
    }
    cout<<calc_sat(pref)<<endl;
  
}