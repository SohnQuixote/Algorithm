#include <iostream>
#include <vector>
using namespace std;
/*
  정확한 순위
  N개 성적 분실후 성적 비교 결과 일부
  성적 순위 알수 있는 학생 수
  플로이드 워셜 사용하여 자신을 제외한 모든 학생 으로부터 갈 수 있으면 순위를 알 수 있는 학생
*/
const int INF = 987654321;
int main() {
  int n,m;
  cin>>n>>m;
  vector<vector<int>> students = vector<vector<int>>(n,vector<int>(n,INF));
  for(int i=0;i<n;i++)
    students[i][i] = 0;
  for(int i=0;i<m;i++)
    {
      int a,b;
      cin>>a>>b;
      students[a-1][b-1] = 1;
      students[b-1][a-1] = 1;
    }
  for(int k=0;k<n;k++)
    {
      for(int r = 0;r<n;r++)
        {
        for(int c=0;c<n;c++)
          {
            students[r][c] = min(students[r][c] , students[r][k]+students[k][c]);
          }
        }
    }
  int result = 0;
  for(int r=0;r<n;r++)
    {
      int tmp = 0;
      for(int c=0;c<n;c++)
        { 
          tmp+= students[r][c];
          cout<<students[r][c]<<' ';
        }
      cout<<endl;
      if(tmp<INF)
      {
        result++;
      }
    }
  cout<<result<<endl;
}