#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
  큐빙
  3 * 3 * 3 정육면체
  U(0) - 흰(10) D(1) - 노(11) F(2) -빨(12) B(3) - 오렌지(13) L(4) -초(14) R(5) -파(15)
  + 시계 1  - 반시계 0
  너무 복잡하게 구현함
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
int mod_four(int a)
{
  if(a<0)
    return a+4;
  return a%4;
}
vector<vector<int>> rotate_surface(vector<vector<int>> a, int dir)
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
  return a;
  //good
}  
vector<vector<vector<int>>> rotate(vector<vector<vector<int>>> c , pair<int,int> cmd)
{
  vector<int>rotating;   
      if(cmd.first == 0) //위
      {
        rotating.push_back(2);
        rotating.push_back(4);
        rotating.push_back(3);
        rotating.push_back(5);
        vector<vector<int>> rotate;
        for(int i=0;i<4;i++)
          {
            rotate.push_back(c[rotating[i]][0]);
          }
        int d;
        if(cmd.second == 1)
        {
          d = 1;
          c[0] = rotate_surface(c[0],1);
        }
        else
        {
          d = -1;
          c[0] = rotate_surface(c[0],0);
        }
        for(int i=0;i<4;i++)
            {
              int r_s = rotating[mod_four(i+d)];
              c[r_s][0] = rotate[i];
              
            }
      }

      else if(cmd.first == 1) //아래
      {
        rotating.push_back(2);
        rotating.push_back(4);
        rotating.push_back(3);
        rotating.push_back(5);
        vector<vector<int>> rotate;
        for(int i=0;i<4;i++)
          {
            rotate.push_back(c[rotating[i]][2]);
          }
        int d;
        if(cmd.second == 1)
        {
          
          c[1] = rotate_surface(c[1],1);
          d = -1;
        }
        else
        {
          c[1] = rotate_surface(c[1],0);
          d = 1;
        }
        for(int i=0;i<4;i++)
            {
              int r_s = rotating[mod_four(i+d)];
              c[r_s][2] = rotate[i];
              
            }
        
      }

      else if(cmd.first == 2) //앞
      {
        vector<int>surf_zero = c[0][2];
        vector<int>surf_five;
        for(int i=0;i<3;i++)
          {
            surf_five.push_back(c[5][i][0]);
          }
        vector<int>surf_one = c[1][0];
        vector<int>surf_four;
        for(int i=0;i<3;i++)
          {
            surf_four.push_back(c[4][i][2]);
          }
        if(cmd.second ==1)
        {
          //시계
          c[2] = rotate_surface(c[2],1);
          for(int i=0;i<3;i++)
            {
              c[0][2][i] = surf_four[2-i];
            }
          for(int i=0;i<3;i++)
            {
              c[5][i][0] = surf_zero[i];
            }
          for(int i=0;i<3;i++)
              {
                c[1][0][i] = surf_five[i];
              }
          for(int i=0;i<3;i++)
            {
              c[4][i][2 ] = surf_one[2-i];
            }
        }
        else
        {
          //반시계
          c[2] = rotate_surface(c[2],0);
          for(int i=0;i<3;i++)
            {
              c[0][2][i] = surf_five[i];
            }
          for(int i=0;i<3;i++)
            {
              c[5][i][0] = surf_one[i];
            }
          for(int i=0;i<3;i++)
              {
                c[1][0][i] = surf_four[2-i];
              }
          for(int i=0;i<3;i++)
            {
              c[4][i][2] = surf_zero[2-i];
            }
          
        }
      }

      else if(cmd.first == 3)
      {
        vector<int>surf_zero,surf_four,surf_one,surf_five;
        surf_zero = c[0][0];
        surf_one = c[1][2];
        for(int i=0;i<3;i++)
          {
            surf_four.push_back(c[4][i][0]);
            
          }
        for(int i=0;i<3;i++)
          {
            surf_five.push_back(c[5][i][2]);
          }
        if(cmd.second == 1)
        {
          c[3] = rotate_surface(c[3],1);
          for(int i=0;i<3;i++)
            {
              c[0][0][i] = surf_five[i];
            }
          for(int i=0;i<3;i++)
            {
              c[4][i][0] = surf_zero[2-i];
            }
            for(int i=0;i<3;i++)
            {
               c[1][2][i] = surf_four[2-i]; 
            }
            for(int i=0;i<3;i++)
            {
             c[5][i][2] = surf_one[i]; 
            }
        }
        else
        {
          c[3] = rotate_surface(c[3],0);
          for(int i=0;i<3;i++)
            {
              c[0][0][i] = surf_four[2-i];
            }
          for(int i=0;i<3;i++)
            {
              c[4][i][0] = surf_one[2-i];
            }
            for(int i=0;i<3;i++)
            {
               c[1][2][i] = surf_five[i]; 
            }
            for(int i=0;i<3;i++)
            {
             c[5][i][2] = surf_zero[i]; 
            }
        }
      }
      else if(cmd.first == 4)
      {
        vector<int>surf_zero,surf_two,surf_three,surf_one;
        for(int i=0;i<3;i++)
          {
            surf_zero.push_back(c[0][i][0]);
            
          }
        for(int i=0;i<3;i++)
          {
            surf_one.push_back(c[1][i][2]);
          }
        for(int i=0;i<3;i++)
          {
            surf_two.push_back(c[2][i][0]);
          }
        for(int i=0;i<3;i++)
          {
            surf_three.push_back(c[3][i][2]);
            
          }
        if(cmd.second == 1)
        {
          c[4] = rotate_surface(c[4],1);
          for(int i=0;i<3;i++)
            {
              c[0][i][0] = surf_three[2-i];
            }
          for(int i=0;i<3;i++)
            {
              c[2][i][0] = surf_zero[i];
            }
          for(int i=0;i<3;i++)
            {
              c[1][i][2] = surf_two[i];
            }
          for(int i=0;i<3;i++)
            {
              c[3][i][2] = surf_one[2-i];
              
            }
        }
        else
        {
          c[4] = rotate_surface(c[4],0);
          for(int i=0;i<3;i++)
            {
              c[0][i][0] = surf_two[i];
            }
          for(int i=0;i<3;i++)
            {
              c[2][i][0] = surf_one[i];
            }
          for(int i=0;i<3;i++)
            {
              c[1][i][2] = surf_three[2-i];
            }
          for(int i=0;i<3;i++)
            {
              c[3][i][2] = surf_zero[2-i];
              
            }
        }
      }

      
      else
      {
        vector<int>surf_zero,surf_two,surf_three,surf_one;
        for(int i=0;i<3;i++)
          {
            surf_zero.push_back(c[0][i][2]);
            
          }
        for(int i=0;i<3;i++)
          {
            surf_one.push_back(c[1][i][2]);
          }
        for(int i=0;i<3;i++)
          {
            surf_two.push_back(c[2][i][2]);
          }
        for(int i=0;i<3;i++)
          {
            surf_three.push_back(c[3][i][0]);
            
          }
        if(cmd.second == 1)
        {
          c[5] = rotate_surface(c[5],1);
          for(int i=0;i<3;i++)
            {
              c[0][i][2] = surf_two[i];
            }
          for(int i=0;i<3;i++)
            {
              c[3][i][0] = surf_zero[2-i];
            }
          for(int i=0;i<3;i++)
            {
              c[1][i][2] = surf_three[2-i];
            }
          for(int i=0;i<3;i++)
            {
              c[2][i][2] = surf_one[i];
              
            }
        }
        else
        {
          c[5] = rotate_surface(c[5],0);
          for(int i=0;i<3;i++)
            {
              c[0][i][2] = surf_three[2-i];
            }
          for(int i=0;i<3;i++)
            {
              c[3][i][0] = surf_one[2-i];
            }
          for(int i=0;i<3;i++)
            {
              c[1][i][2] = surf_two[i];
            }
          for(int i=0;i<3;i++)
            {
              c[2][i][2] = surf_zero[i];
              
            }
          
        }
      }
      
  return c;
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
  //cin>>T;

  
  vector<vector<vector<int>>>cube(6,vector<vector<int>>(3,vector<int>(3,0)));
  //int k = 0;
  for(int s =0;s<6;s++)
    {
      int k = 0;
      for(int r = 0;r<3;r++)
        {
          for(int c=0;c<3;c++)
            {
              cube[s][r][c] = s;
              //k++;
            }
        }
    }
    cube = rotate(cube,chg_cmd("R-"));
    print_3d_cube(cube);
  
    cube = rotate(cube,chg_cmd("L-"));
    print_3d_cube(cube);

  
    cube = rotate(cube,chg_cmd("L-"));
    print_3d_cube(cube);
    
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
            tmp_cube = rotate(tmp_cube,cmd);
          }
        results.push_back(tmp_cube[0]);
        //print_3d_cube(tmp_cube);
      }
    for(int i=0;i<T;i++)
      {
        print_cube(results[i]);
      
      } 
  
}