#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
int map[10][10] = {
    0,
};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
int min_result = 987654321;
bool calc_range(int x, int y) {
  if (x >= 0 && x < n && y >= 0 && y < m)
    return true;
  return false;
}
void print_island(int ma[10][10]) {
  cout << "\nprinting::\n";
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      cout << ma[r][c] << ' ';
    }
    cout << '\n';
  }
}
bool chk_finished(int visited[7])
{
  for(int i=0;i<7;i++)
    if(visited[i] == 0)
      return false;
  return true;


  
  //모든 점에서 다 이동가능한지 체크하는 함수
  // bool result = false;
  // queue<pair<int,int>> q;
  // int chk[10][10] = {0,};
  // int island_num = 0;
  // for(int i=0;i<n;i++)
  //   {
  //   for(int j=0;j<m;j++)
  //     {
  //       if(tmp[i][j] >0){
  //         island_num+=1;
  //         //cout<<i<<' '<<j<<'\n';
  //         }
  //       chk[i][j] = tmp[i][j];
  //     }
  //   }
  // //cout<<island_num<<endl;
  // //print_island(chk);
  // for(int i=0;i<n && q.empty();i++)
  //   {
  //   for(int j=0;j<m;j++)
  //     {
  //       if(chk[i][j])
  //       {
  //         island_num--;
  //         chk[i][j] = 0;
  //         q.push({i,j});
  //         break;
  //         //모든점에서 이동가능해야함
  //       }
        
  //     }
  

      
  //   }
  
  // while(!q.empty()){
  //   int x,y;
  //   tie(x,y) = q.front();
  //   q.pop();
  //   for(int d=0;d<4;d++)
  //     {
  //       int mov_x = x+dx[d];
  //       int mov_y = y+dy[d];
  //       if(calc_range(mov_x,mov_y) && chk[mov_x][mov_y])
  //       {
  //         island_num--;
  //         chk[mov_x][mov_y] = 0;
  //         q.push({mov_x,mov_y});
  //       }

        
  //     }


    
  // }
  // //print_island(chk);
  // //cout<<island_num<<endl;
  // if(island_num)
  //   return false;
  // else
  //   return true;
}
int  bridge_coord(int x, int y, int tmp[10][10], int d,int connected[7]) {
  int e_x, e_y;
  int found = 0;
  int mov_x = x + dx[d];
  int mov_y = y + dy[d];
  int start = tmp[x][y];
  int end;
  while (calc_range(mov_x, mov_y) && tmp[mov_x][mov_y] == 0) {
    //최대한 가보기
    mov_x += dx[d];
    mov_y += dy[d];
  }
  if ((abs(mov_x - x) + abs(mov_y - y)) > 2) {
    //다리 생성조건만족
    if (tmp[mov_x][mov_y] != tmp[x][y] && tmp[mov_x][mov_y] && tmp[mov_x][mov_y] != 9) {
      //다른 섬임
      found = (abs(mov_x-x) + abs(mov_y-y))-1;
      x += dx[d];
      y += dy[d];
      while (!(x == mov_x && y == mov_y)) {
        tmp[x][y] = 9;
        x += dx[d];
        y += dy[d];
      }
      end = tmp[mov_x][mov_y];
      //여기서 칠하는 작업 필요
      //cout << x << ' ' << y << ' ' << mov_x << ' ' << mov_y << endl; //테스트
    }
  }
  if(found)
  {
    connected[start] = 1;
    connected[end] =1;
    
  }
  return found;
  //임시로 생성한 배열을 칠하기
}

void chk_conn(int tmp[10][10], int sx, int sy, int bridges, int connected[7]) {
  //재귀 호출
  if(chk_finished(connected))
  {
    if(min_result>bridges)
    {
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        map[i][j] = tmp[i][j];
      print_island(map);
    }
    min_result  = min(min_result,bridges);

    //print_island(tmp);
    return;
  }

  //기저조건 함수
  for(int x =sx ;x<n;x++)
    {
      if(x>sx)
        sy = 0;
      for(int y=sy;y<m;y++)
        {

          if(tmp[x][y] && tmp[x][y]<=6)
          {
            for(int d=0;d<4;d++)
              {
                int prev[10][10] = {0,};
                  for(int i=0;i<n;i++)
                    for(int j=0;j<m;j++)
                      prev[i][j] = tmp[i][j];

                int prev_connected[7] = {0,};
                for(int i=0;i<7;i++)
                  prev_connected[i] = connected[i];
                int added = bridge_coord(x, y, tmp,d,connected);
                if(added > 0)
                {
                  chk_conn(tmp,sx,sy+1,bridges+added,connected);
                }
                  //print_island(tmp);
                  for(int i=0;i<n;i++)
                    for(int j=0;j<m;j++)
                      tmp[i][j] = prev[i][j];
                for(int i=0;i<7;i++)
                  connected[i] = prev_connected[i];
              }
            
          }

          
        }

      
    }
  
}

int seperate_island() {
  int island_num = 7;
  //섬을 6부터 역으로 카운팅함
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (map[i][j] && map[i][j] < island_num) {
        island_num--;
        queue<pair<int, int>> q;
        q.push({i, j});
        // visited필요 없음 바꿀거기 때문에
        map[i][j] = island_num;
        while (!q.empty()) {
          int x, y;
          tie(x, y) = q.front();
          q.pop();
          for (int d = 0; d < 4; d++) {
            int mov_x = x + dx[d];
            int mov_y = y + dy[d];
            if (calc_range(mov_x, mov_y) && map[mov_x][mov_y] == 1) {
              map[mov_x][mov_y] = island_num;
              q.push({mov_x, mov_y});
            }
          }
        }
        // print_island();
      }
    }
  }
  return island_num;
}

int main() {
  cin >> n >> m;
  cin.tie(NULL);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> map[i][j];
  int island_num = seperate_island(); //섬분리 완료
  cout<<island_num<<'\n';
  int connected[7] = {0,};
  for(int i=0;i<island_num;i++)
    connected[i] = 1;
  for(int i=island_num;i<7;i++)
    connected[i] = 0;
  // 해당 번호부터 연결 안됨 표시 
  int tmp[10][10] = {0,};
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
      tmp[i][j] = map[i][j];
  chk_conn(tmp,0,0,0,connected);
  //print_island(map);
  cout<<min_result<<'\n';
  //cout<<chk_finished(map);
  //print_island(map);  
}