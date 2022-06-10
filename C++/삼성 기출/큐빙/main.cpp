#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/*
  큐빙
  3 * 3 * 3 정육면체
  U(0) - 흰(10) D(1) - 노(11) F(2) -빨(12) B(3) - 오렌지(13) L(4) -초(14) R(5) -파(15)
  + 시계 1  - 반시계 0
  핵심 부분 재구현    
*/
pair<int,int> chg_cmd(string a)
{
  pair<int,int> result;
  if(a[0] == 'U')
  {
    result.first = 0;
  }
  else if(a[0] == 'D')
  {
    result.first = 1;
  }
  else if(a[0] == 'F')
  {
    result.first = 2;
  }
  else if(a[0] == 'B')
  {
    result.first = 3;
  }
  else if(a[0] == 'L')
  {
    result.first = 4;
  }
  else if(a[0] == 'R')
  {
    result.first = 5;
  }
  if(a[1] == '+')
  {
    result.second = 1;
    
  }
  else if(a[1] == '-')
  {
    result.second = 0;
  }
  return result;
}
void rotate_surface(vector<vector<int>> &a, int dir)
{
  vector<int> surf_one = a[0];
  vector<int> surf_two = a[1];
  vector<int> surf_three = a[2];
  if(dir == 1)
  {
    for(int i=0;i<3;i++)
      {
        a[i][0] = surf_three[i];
      }
    for(int i=0;i<3;i++)
      {
        a[i][1] = surf_two[i];
      }
    for(int i=0;i<3;i++)
      {
        a[i][2] = surf_one[i];
      }
  }
  else
  {
    for(int i=0;i<3;i++)
      {
        a[i][0] = surf_one[2-i];
      }
    
    for(int i=0;i<3;i++)
      {
        a[i][1] = surf_two[2-i];
      }
    
    for(int i=0;i<3;i++)
      {
        a[i][2] = surf_three[2-i];
      }
  }
  //good
}  
int mod_four(int a)
{
  if(a<0)
    return a+4;
  return a%4;
}
void put_col(vector<vector<int>> &a,vector<int> v, int col, bool reversed)
{
  if(reversed)
  {
    for(int i=0;i<3;i++)
    {
       a[i][col] = v[2-i];
    }
  }
  else
  {
   for(int i=0;i<3;i++)
    {
       a[i][col] = v[i];
    }
  }
}
void put_row_rev(vector<int> &a,vector<int> b)
{
  reverse(b.begin(),b.end());
  a = b;
}
void rotate(vector<vector<vector<int>>> &c , pair<int,int> cmd)
{
  rotate_surface(c[cmd.first],cmd.second);
  //면 회전
  //주위 공간 회전
  //모든 면은 해당 면에서 봤을때 좌측 위부터 보는걸로 고려
  vector<pair<int,vector<int>>> surfs;
  vector<int> tmp(3,0);
  if(cmd.first == 0)
  {
    //위
    //2,3,4,5 회전
    surfs.push_back(make_pair(3,c[3][0]));
    surfs.push_back(make_pair(5,c[5][0]));
    surfs.push_back(make_pair(2,c[2][0]));
    surfs.push_back(make_pair(4,c[4][0]));
    //윗면은 회전시 그대로 넣어도 됨
    /*  3
      4 0 5
        2
    */
    int d =0;
    if(cmd.second == 1)
    {
      d = 1;
      
    }
    else
    {
      d = -1;
    }
    for(int i=0;i<4;i++)
      {
        int s_idx = i;
        int r_s_idx = mod_four(i+d);
        int r_s = surfs[r_s_idx].first;
        c[r_s][0] = surfs[s_idx].second;
      }
  }
  else if (cmd.first == 1)
  {
    //아래
    /* 3 
     5 1 4
       2
    */
    //윗면과 똑같이 그대로 함
    surfs.push_back(make_pair(3,c[3][2]));
    surfs.push_back(make_pair(4,c[4][2]));
    surfs.push_back(make_pair(2,c[2][2]));
    surfs.push_back(make_pair(5,c[5][2]));
    int d =0;
    if(cmd.second == 1)
      d = 1;
    else
      d = -1;
    for(int i=0;i<4;i++)
      {
        int s_idx = i;
        int r_s_idx = mod_four(i+d);
        int r_s = surfs[r_s_idx].first;
        c[r_s][2] = surfs[s_idx].second;
      }
  }
  else if(cmd.first ==2)
  {
    
    //앞
    /*  0
      4 2 5
        1
    */ 
    //행과 열이 서로 바뀌어서 그대로 하는 것 불가능
    surfs.push_back(make_pair(0,c[0][2]));
    for(int i=0;i<3;i++) //5면은 0열
      tmp[i] = c[5][i][0];
    surfs.push_back(make_pair(5,tmp));
    surfs.push_back(make_pair(1,c[1][2]));
    for(int i=0;i<3;i++) //그냥 거꾸로 넣어서 순번 상관없게 하기?
      tmp[i] = c[4][2-i][2];
    surfs.push_back(make_pair(4,tmp)); 
    //열이 있어서 자동화 불가능?
    int d = 0;
    if(cmd.second == 1)
      d = 1;
    else
      d= -1;
    for(int i=0;i<4;i++)
      {
        int s_idx = i;
        int r_s_idx = mod_four(i+d);
        int r_s = surfs[r_s_idx].first;
        if(r_s == 5)
        {
          put_col(c[r_s],surfs[s_idx].second,0,false);
        }
        else if(r_s == 4)
        {
          put_col(c[r_s],surfs[s_idx].second,2,true);
          
        }
        else
        {
          c[r_s][2] = surfs[s_idx].second;
        }
      }
    //함수 필요
  }
  else if(cmd.first == 3)
  {
    //뒤
    /*  0
      5 3 4
        1
      뒤집었을때 기존의 표시방향 유의하며 대체
    */
    surfs.push_back(make_pair(0,c[0][0]));
    for(int i=0;i<3;i++)
      tmp[i] = c[4][2-i][0];
    surfs.push_back(make_pair(4,tmp));
    for(int i=0;i<3;i++)
      tmp[i] = c[1][0][i];
    surfs.push_back(make_pair(1,tmp));
    for(int i=0;i<3;i++)
      tmp[i] = c[5][i][2];
    surfs.push_back(make_pair(5,tmp));

    int d =0;
    if(cmd.second == 1)
      d = 1;
    else
      d = -1;
    for(int i=0;i<4;i++)
      {
        int s_idx = i;
        int r_s_idx = mod_four(i+d);
        int r_s = surfs[r_s_idx].first;
  
        if(r_s == 4)
        {
          put_col(c[r_s],surfs[s_idx].second,0,true);
        }
        
        else if(r_s == 5)
        {
          put_col(c[r_s],surfs[s_idx].second,2,false);
        }
        else
        {
          c[r_s][0] = surfs[s_idx].second;
        }
      }
    
  }
  else if(cmd.first == 4)
  {
    //왼
    /* 0
     3 4 2 
       1
    */
    for(int i=0;i<3;i++)
      tmp[i] = c[0][i][0];
    surfs.push_back(make_pair(0,tmp));
    
    for(int i=0;i<3;i++)
      tmp[i] = c[2][i][0];
    surfs.push_back(make_pair(2,tmp));
    
    for(int i=0;i<3;i++)
      tmp[i] = c[1][2-i][2];
  surfs.push_back(make_pair(1,tmp));
    
    for(int i=0;i<3;i++)
      tmp[i] = c[3][2-i][2];
    surfs.push_back(make_pair(3,tmp));

    int d =0;
    if(cmd.second == 1)
      d = 1;
    else
      d = -1;
    for(int i=0;i<4;i++)
      {
        int s_idx = i;
        int r_s_idx = mod_four(i+d);
        int r_s = surfs[r_s_idx].first;
        if(r_s== 0 || r_s == 2)
        {
          put_col(c[r_s],surfs[s_idx].second,0,false);
        }
        else
        {
          put_col(c[r_s],surfs[s_idx].second,2,true);
        }
      }
    
  }
  else
  {
    //오
    /*
      0
    2 5 3 
      1
    */
    for(int i=0;i<3;i++)
      tmp[i] = c[0][i][2];
    surfs.push_back(make_pair(0,tmp));
    
    for(int i=0;i<3;i++)
      tmp[i] = c[3][2-i][0];
    surfs.push_back(make_pair(3,tmp));
    
    for(int i=0;i<3;i++)
      tmp[i] = c[1][2-i][0];
  surfs.push_back(make_pair(1,tmp));
    
    for(int i=0;i<3;i++)
      tmp[i] = c[2][i][2];
    surfs.push_back(make_pair(2,tmp));

    int d =0;
    if(cmd.second == 1)
      d = 1;
    else
      d = -1;
    for(int i=0;i<4;i++)
      {
        int s_idx = i;
        int r_s_idx = mod_four(i+d);
        int r_s = surfs[r_s_idx].first;
        if(r_s== 0 || r_s == 2)
        {
          put_col(c[r_s],surfs[s_idx].second,2,false);
        }
        else
        {
          put_col(c[r_s],surfs[s_idx].second,0,true);
        }
      }
    
  }
}
string chg_char(int a)
{
  //문자 반환
  //wyrogb
  if(a==0)
  {
    return "w";
  }
  else if(a==1)
  {
    return "y";
  }
  else if(a==2)
  {
    return "r";
  }
  else if(a==3)
  {
    return "o";
  }
  else if(a==4)
  {
    return "g";
  }
  return "b";
}
void print_3d_cube(vector<vector<vector<int>>> cube)
{
  cout<<endl<<endl;
  for(int i=0;i<6;i++)
    {
      cout<<i<<"면::"<<endl;
      for(int r=0;r<3;r++)
        {
          for(int c=0;c<3;c++)
            {
              cout<<chg_char(cube[i][r][c]);
              //cout<<cube[i][r][c]<<' ';
            }
          cout<<endl;
        }
    }
  
}
void print_cube(vector<vector<int>> cube)
{
  //윗면만 출력
      for(int r=0;r<3;r++)
        {
          for(int c=0;c<3;c++)
            {
              cout<<chg_char(cube[r][c]);
            }
          cout<<endl;
        }
}
int main() {
 
  
  int T;
  cin>>T;
  vector<vector<vector<int>>>cube(6,vector<vector<int>>(3,vector<int>(3,0)));
  for(int s =0;s<6;s++)
    {
      int k = 0;
      for(int r = 0;r<3;r++)
        {
          for(int c=0;c<3;c++)
            {
              cube[s][r][c] = s;
            }
        }
    }
    vector<vector<vector<int>>>results;
    for(int i=0;i<T;i++)
      {
        vector<vector<vector<int>>> tmp_cube = cube;
        //print_cube(cube[0]);
        int N;
        cin>>N;
        for(int j=0;j<N;j++)
          {
            string command;
            cin>>command;
            pair<int,int> cmd = chg_cmd(command);
            rotate(tmp_cube,cmd);
            
            //cout<<endl<<j+1<<"cmd:::"<<endl;
            //print_3d_cube(tmp_cube);
          }
        results.push_back(tmp_cube[0]);
        
      }
    for(int i=0;i<T;i++)
      {
        print_cube(results[i]);
      } 
  //L+ L+ F+ B+ U- L+
  //7
//D+ L- B- U+ D+ B+ B+
}