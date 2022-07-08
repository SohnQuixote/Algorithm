#include <iostream>
#include <vector>
using namespace std;
/*
  온풍기 안녕
  먹은 초콜릿의 수 - 스텝 수
  조사하는 칸 K이상이면 종료
*/
int R,C,K;
int dx[4] = {-1,0,1,0};
int dy[4] = {};
vector<vector<int>>room(20,vector<int>(20,0));
int spread_dir[4][3][2] = {{{-1,-1},{-1,0},{-1,1}},{{-1,1},{0,1},{1,1}},{{1,-1},{1,0},{1,1}},{{-1,-1},{0,-1},{1,-1}}};
vector<vector<vector<bool>>>wall(4,vector<vector<bool>>(20,vector<bool>(20,false)));
vector<vector<bool>>inspect(20,vector<bool>(20,false));
vector<vector<int>>device(20,vector<int>(20,0));
int chocolate = 0;
int main() {
  int W;
  cin>>R>>C>>K;
  for(int i=0;i<R;i++)
    {
    for(int j=0;j<C;j++)
      {
        int tmp;
        cin>>tmp;
        if(tmp == 5)
          inspect[i][j] = true;
        else if(tmp == 1)
          device[i][j] = tmp;
        else if(tmp ==2)
          device[i][j] =3;
        else if(tmp ==3)
          device[i][j] = 0;
        else if(tmp == 4)
          device[i][j] = 2;
        
      }
    }
  cin>>W;
  for(int i=0;i<W;i++)
    {
      int a,b,c;
      cin>>a>>b>>c;
      
      
    }
}