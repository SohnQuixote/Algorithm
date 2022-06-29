#include <iostream>
#include <vector>
using namespace std;
/*
  컨베이어 벨트 로봇
  0~N-1 위
  N~2N-1 아래
  0번 올리는 위치
  N-1번 내리는 위치
  0번위치에 로봇 올림
  로봇 스스로 이동 가능
  로봇이 있는칸은 즉시 내구도 1감소

  로봇 옮기려 하는 단계 세부 스텝
  1. 벨트 회전
  2. 먼저 올라간 로봇 부터 한칸 이동할 수 있으면 이동 - 로봇 안겹치고 내구도 1이상
  3. 0 내구도 0아니면 로봇 올림
  4. 내구도 0인 칸 K개면 종료

  종료 되었을 때 단계
*/
int N,K;

int modular_add(int a)
{
  return (a+1) %(2*N);
}
void step_one(vector<pair<int,int>> &belt)
{
  vector<pair<int,int>> tmp = belt;
  for(int i=0;i<2*N;i++)
    {
      belt[modular_add(i)] = tmp[i];
    }
  return;
}
void down_robot(vector<pair<int,int>> &belt)
{
  if(belt[N-1].second == 1)
    belt[N-1].second =0;
  return;
}
int moving_belt(vector<pair<int,int>> belt)
{
  int steps = 0;
  int zeros = 0;
    do
    {
  //1
  //cout<<zeros<<endl;
  steps++;
  step_one(belt);
  down_robot(belt);
  //2
  for(int i=N-2;i>=0;i--)
    {
      if(belt[i].second == 1 && belt[i+1].second == 0 && belt[i+1].first >0)
      {
        belt[i].second = 0;
        belt[i+1].second =1;
        if( --belt[i+1].first== 0)
          zeros++;
      }
    }
    down_robot(belt);
    //3
    if(belt[0].first>0)
    {
      belt[0].second = 1;
      
      if(--belt[0].first == 0)
        zeros++;
      
    }

    //4
  }while(zeros<K);
  return steps;
  
}


int main() {
  cin>>N>>K;
  vector<pair<int,int>>belt(2*N,make_pair(0,0)); //first 내구도 second 로봇 여부 0 없음 1 있음
  for(int i=0;i<2*N;i++)
    {
      cin>>belt[i].first;
    }
  cout<<moving_belt(belt)<<endl;
}