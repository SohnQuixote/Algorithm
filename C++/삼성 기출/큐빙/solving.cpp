#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
  큐빙
  3 * 3 * 3 정육면체
  U(0) - 흰(10) D(1) - 노(11) F(2) -빨(12) B(3) - 오렌지(13) L(4) -초(14) R(5) -파(15)
  + 시ㄱ  - 반시계
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
    result.second = 0;
    
  }
  else if(a[1] == '-')
  {
    result.second = 1;
    
  }
  return result;
}
int mod_four(int a)
{
  if(a<0)
    return a+4;
  return a%4;
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
        if(cmd.second == 0)
        {
          d = 1;
        }
        else
        {
          d = -1;
        }
        for(int i=0;i<4;i++)
            {
              int r_s = rotating[mod_four(i+d)];
              int s = rotating[i];
              c[r_s][0] = rotate[s];
              
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
        if(cmd.second == 0)
        {
          d = 1;
        }
        else
        {
          d = -1;
        }
        for(int i=0;i<4;i++)
            {
              int r_s = rotating[mod_four(i+d)];
              int s = rotating[i];
              c[r_s][0] = rotate[s];
              
            }
        
      }

      else if(cmd.first == 2) //앞
      {
        vector<vector<int>> rotate;
        rotate.push_back(c[0][2]);
        vector<int> tmp;
        for(int k =0;k<3;k++)
          {
            tmp.push_back(c[5][k][0]);
            
          }
          rotate.push_back(tmp);
          rotate.push_back(c[1][2]);
        for(int k=0;k<3;k++)
          {
            tmp[k] = c[4][k][2];
          }
          rotate.push_back(tmp);
          if(cmd.second == 0)
          {
            for(int k=0;k<3;k++)
              {
                c[5][k][0] = rotate[0][k];          
              }
            for(int k=0;k<3;k++)
              {
                c[1][2][k] = rotate[1][2-k];          
              }
            for(int k=0;k<3;k++)
              {
                c[4][k][2] = rotate[2][k];          
              }
            for(int k=0;k<3;k++)
              {
                c[0][2][k] = rotate[3][2-k];          
              }
            
          }
          else
          {
            for(int k=0;k<3;k++)
              {
               c[4][k][2] = rotate[0][2-k];           
              }
            for(int k=0;k<3;k++)
              {
                c[0][2][k] = rotate[1][k];
              }
            for(int k=0;k<3;k++)
              {
                c[5][k][0] = rotate[2][2-k];
                          
              }
            for(int k=0;k<3;k++)
              {
                c[1][2][k] = rotate[3][k];
                          
              }
            
          }

      }

      else if(cmd.first == 3)
      {
        vector<vector<int>> rotate;
        rotate.push_back(c[0][2]);
        vector<int> tmp;
        for(int k =0;k<3;k++)
          {
            tmp.push_back(c[5][k][0]);
            
          }
          rotate.push_back(tmp);
          rotate.push_back(c[1][2]);
        for(int k=0;k<3;k++)
          {
            tmp[k] = c[4][k][2];
          }
          rotate.push_back(tmp);
          if(cmd.second == 0)
          {
            for(int k=0;k<3;k++)
              {
                c[5][k][0] = rotate[0][k];          
              }
            for(int k=0;k<3;k++)
              {
                c[1][2][k] = rotate[1][2-k];          
              }
            for(int k=0;k<3;k++)
              {
                c[4][k][2] = rotate[2][k];          
              }
            for(int k=0;k<3;k++)
              {
                c[0][2][k] = rotate[3][2-k];          
              }
            
          }
          else
          {
            for(int k=0;k<3;k++)
              {
               c[4][k][2] = rotate[0][2-k];           
              }
            for(int k=0;k<3;k++)
              {
                c[0][2][k] = rotate[1][k];
              }
            for(int k=0;k<3;k++)
              {
                c[5][k][0] = rotate[2][2-k];
                          
              }
            for(int k=0;k<3;k++)
              {
                c[1][2][k] = rotate[3][k];
                          
              }
            
          }


      }

      else if(cmd.first == 4)
      {
        rotating.push_back(0);
        rotating.push_back(2);
        rotating.push_back(1);
        rotating.push_back(3);

      }

      
      else
      {
        rotating.push_back(0);
        rotating.push_back(2);
        rotating.push_back(1);
        rotating.push_back(3);
      }
      

  return c;
}
string chg_char(int a)
{
  //문자 반환
}
void print_cube(vector<vector<vector<int>>> cube)
{
  //윗면만 출력
}
int main() {
  int T;
  cin>>T;
  vector<vector<vector<int>>>cube(6,vector<vector<int>>(3,vector<int>(3,0)));
  for(int s =0;s<6;s++)
    {
      for(int r = 0;r<3;r++)
        {
          for(int c=0;c<3;c++)
            {
              cube[s][r][c] = s+10;
            }
        }
    }
    for(int i=0;i<T;i++)
      {
        vector<vector<vector<int>>> tmp_cube = cube;
        int N;
        cin>>N;
        for(int j=0;j<N;j++)
          {
            string command;
            cin>>command;
            pair<int,int> cmd = chg_cmd(command);
            tmp_cube = rotate(tmp_cube,cmd);
          }
      }
}