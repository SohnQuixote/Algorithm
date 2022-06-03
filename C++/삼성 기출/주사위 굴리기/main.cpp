#include <iostream>
#include <vector>

using namespace std;
/*
  주사위 굴리기
  크기 N * M 지도
  r,c -> 행 열
  지도 바깥 이동 명령 무시
  1 동 2 서 3 북 4 남
*/
int dr[5] = {0,0,0,-1,1};
int dc[5] = {0,1,-1,0,0};
int N,M;
const int MAX =20;
vector<vector<int>> map(20,vector<int>(20,0));
bool calc_range(int a, int b)
{
  if(a>=0 && a<b)
    return true;
  return false;
}
typedef struct dice_pos
{
  int front = 5;//앞면
  int back = 2;//뒷면
  int left = 4;
  int right = 3;
  int top = 1;
  int bottom = 6;
}dice_pos;
//현재 위치
typedef struct dice_char
{
  int front = 0;//앞면
  int back = 0;//뒷면
  int left = 0;
  int right = 0;
  int top = 0;
  int bottom = 0;
}dice_char;
//초기 값
void print_dice(dice_char& c)
{
  cout<<"top::"<<c.top<<endl;
  cout<<"bottom::"<<c.bottom<<endl;
  cout<<"front::"<<c.front<<endl;
  cout<<"back::"<<c.back<<endl;
  cout<<"left::"<<c.left<<endl;
  cout<<"right::"<<c.right<<endl;
  
}
void moving_dice(dice_char& c, int dir)
{
  
//좌 한칸 이동 -> left-> bottom, top -> left , right -> top , bottom -> right
//우 한칸 이동 -> right-> bottom, top -> right,  left -> top, bottom -> left
//위 한칸 이동 back -> bottom, top -> back , front -> top , bottom -> front
//하 한칸 이동 -> front -> bottom, bottom -> back, back-> top, top -> front
  dice_char orig_c = c;
  switch(dir)
    {
      case 1: //우
        c.bottom = orig_c.right;
        c.right = orig_c.top;
        c.top = orig_c.left;
        c.left = orig_c.bottom;
      break;

      case 2: //좌
        c.bottom = orig_c.left;
        c.left = orig_c.top;
        c.top = orig_c.right;
        c.right = orig_c.bottom;
      break;

      case 3: //상
        c.bottom = orig_c.back;
        c.back = orig_c.top;
        c.top = orig_c.front;
        c.front = orig_c.bottom;
      break;

      case 4: //하
        c.bottom = orig_c.front;
        c.back = orig_c.bottom;
        c.top = orig_c.back;
        c.front = orig_c.top;
      break;

      default:
      break;

      
    }
}
vector<int> calc_top(vector<int>commands, int K,dice_char di, int x, int y)
{
  vector<int> result;
  int mov_x =x;
  int mov_y = y;
  for(int i=0;i<K;i++)
    {
  //이동 먼저
      int direction  =commands[i];
      if(calc_range(mov_x+dr[direction] , N) && calc_range(mov_y+dc[direction] , M))
      {
        //범위 안에 있을 때만
        /*cout<<direction<<endl;
        cout<<dr[direction]<<' '<<dc[direction]<<endl;
        
        cout<<"moving to::"<<endl;
        cout<<mov_x<<' '<<mov_y<<endl;
        print_dice(di);*/
        mov_x += dr[direction];
        mov_y += dc[direction];
        moving_dice(di,direction);

        if(map[mov_x][mov_y] == 0)
        {
          map[mov_x][mov_y] = di.bottom;
        }
        else
        {
          di.bottom = map[mov_x][mov_y];
          map[mov_x][mov_y] = 0;
        }
        result.push_back(di.top);
      }
      
  //밑면 복사 or 복사 당하기
  
  //윗면 추가
    }
  return result;
  
}
int main() {
  //dice_pos character_pos;
  dice_char
    character;
  vector<int> commands;
  vector<int> answer;
  int x,y,K;
  cin>>N>>M>>x>>y>>K;
  for(int r= 0;r<N;r++)
    {
      for(int c=0;c<M;c++)
        {
          cin>>map[r][c];
        }
      
    }
  //주사위 놓은 칸 항상 0
  for(int i=0;i<K;i++)
    {
      int tmp;
      cin>>tmp;
      commands.push_back(tmp);
    }
    answer = calc_top(commands,K,character,x,y);
  for(int i=0;i<answer.size();i++)
    {
      cout<<answer[i]<<endl;
    }
    
  //dice character;
  
}