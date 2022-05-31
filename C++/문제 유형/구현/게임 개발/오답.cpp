#include <iostream>
using namespace std;
/*
  게임개발
  N*M맵 생성 - 2차원 배열
  1. 현재 바라보고 있는 방향에서 반시계 90도 갈 수 있나?
  2. 갈수 있으면 고 계속 왼쪽 탐사 왼쪽 없으면 1단계
  3. 다 가보거나 바다 - 한칸 뒤(한칸 뒤 바다일 경우 끝)
  육지 0 바다 1
*/
int calc(int **map,int N,int M,int A,int B,int cd)
{
  int result = 0;
  int moving_dx[4] = {0,1,0,-1};
  int moving_dy[4] = {-1,0,1,0};
  //0 북 1 동 2 남 3 서
  //int chk_alldir = 0;
  //방향 체크할 때마다 1증가 4면 모든 방향 체크
  map[A][B] += 2;
  //2는 가봤다는 뜻 - 갈 수는 있는데 가본곳
  int goback_flag;
  int iter = 0;
  //모두 가본칸이거나 바다
  while(1)
    {
      //1단계 방향 결정
      //iter++;
      for(int i = 3;i>=0;i--)
        {
          cd = ((cd+i)%4);
          //cout<<cd<<endl;
          //2단계 이동
          goback_flag =1;
          if(map[(A+moving_dx[cd])][(B+moving_dy[cd])] == 0)
          {
            A+= moving_dx[cd];
            B+= moving_dy[cd];
            map[A][B]+=2;
            result+=1;
            goback_flag = 0;
          }
        }
      if(goback_flag)
      {
        int tmp_cd = ((cd+2)%4);
        if(map[A+ moving_dx[tmp_cd]][B+moving_dy[tmp_cd]] == 1)
        {
          break;
        }
        result +=1;
        A+= moving_dx[tmp_cd];
        B+= moving_dy[tmp_cd];
        map[A][B]+=2;
      }
      //cout<<iter<<endl<<endl;
    /*for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        {
          cout<<map[i][j]<<" ";
        }      
      cout<<endl;
    }*/
    }
  return result;
}
int main() {
  int N,M;
  int A,B,cd;
  cin>>N>>M;
  cin>>A>>B>>cd;
  int **map = new int *[N];
  for(int i=0;i<N;i++)
    {
      map[i] = new int[M];
    }
  for(int i=0;i<N;i++)
    {
      for(int j=0;j<M;j++)
        {
          cin>>map[i][j];
        }      
    }
  //cout<<(0+4)%4<<endl;
  cout<<calc(map,N,M,A,B,cd)<<endl;
  //delete 귀찮아서 생략
}