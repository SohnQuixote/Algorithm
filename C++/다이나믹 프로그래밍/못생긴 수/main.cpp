#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> ugly_number;
int mult[3] = {2,3,5};
/*
  못생긴 수
  오직 2,3,5만을 약수로 가지는 수
  1,2,3,4,5,6,8,9,...
  1000개니까 전부다 계산 가능?
*/
int main() {
  int N;
  cin>>N;
  if(N<=6)
  {
    cout<<N<<endl;
    return 0;
  }
  ugly_number.push_back(1);
  ugly_number.push_back(2);
  ugly_number.push_back(3);
  ugly_number.push_back(5);
  //효율적으로 계산?
  int first_idx = 1;
  int lst_idx = 3;
  for(int i=0;i<5;i++)
    {
      //int degree = lst_idx - first_idx +1;
      for(int j= first_idx; j<= lst_idx;j++)
        {
          for(int k=0;k<3;k++)
            {
              ugly_number.push_back(ugly_number[j] * mult[k]);
            }
        }
      first_idx = lst_idx+1;
      lst_idx = first_idx + static_cast<int>(pow(3,i+2)) -1;
     //cout<<first_idx<<' '<<lst_idx<<endl;   
    }
  sort(ugly_number.begin(),ugly_number.end());
  ugly_number.erase(unique(ugly_number.begin(), ugly_number.end()), ugly_number.end());
  cout<<ugly_number[N-1]<<endl;
}