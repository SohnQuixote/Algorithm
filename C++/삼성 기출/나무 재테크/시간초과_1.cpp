#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dr[8] = {-1,-1,-1,0,0,1,1,1};
int dc[8] = {-1,0,1,-1,1,-1,0,1};
int N,M;
bool calc_range(int a, int b)
{
  if(a>=1 && a<=b)
    return true;
  return false;
}
vector<vector<int>> lands(11,vector<int>(11,5));
//1~10
priority_queue<int,vector<int>,greater<int>>trees[11][11];
//나무 좌표에 우선순위 큐 사용 -> 매번 작은 나이가 나오게 됨
vector<vector<int>>A(11,vector<int>(11,0));
//해당 좌표에 나무 추가
//나무 우선순위큐 사용?
/*
  나무 재테크
  N * N 크기의 땅
  (r,c) ->1부터 시작
  양분 모든칸에 5만큼
  M개 나무 땅에 심음 (하나에 여러개 나무 가능)
  봄 -> 나이만큼 양분 먹음  나이 1증가
  하나칸 여러개일 경우 나이 어린 나무부터 양분 먹음
  양분 못먹으면 즉시 죽음

  여름 -> 봄에 죽은 나무 양분 변화
  죽은 나무 나이 /2 양분 추가
  가을 -> 나이 5의 배수 나무 번식
인접 8개 칸 나무 생김
  겨울 -> 땅에 양분 추가
  K년 지난 후 살아있는 나무의 개수
*/
void time(int K)
{
  //재귀 구현
  if(K==0)
    return;
  vector<int> dead;
  //봄,여름
  for(int i=1;i<=N;i++)
    {
      for(int j=1;j<=N;j++)
        {
          vector<int>survived;
          vector<int>dead;
          while(!trees[i][j].empty())
            {
              int age = trees[i][j].top();
              trees[i][j].pop();
              if(lands[i][j]>=age)
              {
                lands[i][j] -=age;
                survived.push_back(age+1);
                
                
              }
              else
              {
                dead.push_back(age);
              }
            }
          for(int k=0;k<survived.size();k++)
            {
              trees[i][j].push(survived[k]);
            }
          for(int k=0;k<dead.size();k++)
            {
              lands[i][j] += dead[k]/2;
              
            }
          
        }
      
    }
  
  //가을
  priority_queue<int,vector<int>,greater<int>> tmp;
  for(int i=1;i<=N;i++)
    {
      for(int j=1;j<=N;j++)
        {
          tmp = trees[i][j];
          while(!tmp.empty())
            {
              int age = tmp.top();
              tmp.pop();
              if((age%5) == 0)
              {
                for(int d=0;d<8;d++)
                  {
                    int mov_i = i+dr[d];
                    int mov_j = j+dc[d];
                    if(calc_range(mov_i,N) && calc_range(mov_j,N))
                    {
                      trees[mov_i][mov_j].push(1);

                      
                    }
                  }
              }
              
            }

          
        }
      
    }
  

  //겨울
  for(int i=1;i<=N;i++)
    {
      for(int j=1;j<=N;j++)
        lands[i][j] += A[i][j];
    }

  //내년
  time(K-1);
}
int main() {
  int result = 0;
  int K;
  cin>>N>>M>>K;
  for(int r=1;r<=N;r++)
    {
      for(int c=1;c<=N;c++)
        cin>>A[r][c];
    }
  for(int i=0;i<M;i++)
    {
      int a,b,c;
      cin>>a>>b>>c;
      trees[a][b].push(c);
    }
  time(K);
  //마지막으로 남은 나무들 계산
  for(int i=1;i<=N;i++)
    {
      for(int j=1;j<=N;j++)
        result+=trees[i][j].size();
    }
  cout<<result<<endl;
}