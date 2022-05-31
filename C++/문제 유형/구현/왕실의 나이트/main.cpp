#include <iostream>
#include <string>
/*
  왕실의 나이트
  
*/
int calc(int x, int y)
{
  int result = 0;
  int x_dir[8]= { -2,-1,  1,2,2,1,-1,-2};
  int y_dir[8] = {-1,-2,-2,-1,1,2, 2,  1};
  int tmp_x =x;
  int tmp_y = y;
  //std::cout<<x<<' '<<y<<std::endl;
  for (int i=0;i<8;i++)
    {
      tmp_x += x_dir[i];
      tmp_y += y_dir[i];
      //std::cout<<tmp_x<<' '<<tmp_y<<std::endl;
      if(tmp_x>=0 && tmp_x<= 7 && tmp_y >=0 && tmp_y<=7)
      {
        result +=1;
      }
      tmp_x = x;
      tmp_y = y;
    }
  return result;
}
int main() {
  std::string position;
  std::cin>>position;
  // 'a' is equal to 97
  position[0]-= 97;
  int x = (int)(position[0]);
  int y = (int)(position[1]-49);
  std::cout<<calc(x,y)<<std::endl;
}