#include <iostream>
#include <vector>
using namespace std;
/*
  숫자 배열 회전
*/
vector<vector<int>> cw_spin(vector<vector<int>> a, int n)
{
  vector<vector<int>> result = a;
  for(int r= 0;r<n;r++)
    {
    for(int c=0;c<n;c++)
      {
        result[r][c] = a[n-1-c][r];

        
      }
    }

  return result;
}
int main() {
  int T;
  cin>>T;
  for(int i=0;i<T;i++)
    {
      int N;
      cin>>N;
      vector<vector<int>>arr(N,vector<int>(N,0));
      for(int r=0;r<N;r++)
        for(int c=0;c<N;c++)
          cin>>arr[r][c];
      vector<vector<int>>arr_one = cw_spin(arr,N);
      vector<vector<int>> arr_two = cw_spin(arr_one,N);
      vector<vector<int>> arr_thr = cw_spin(arr_two,N);
    cout<<"#"<<i+1<<endl;
      for(int r=0;r<N;r++)
        {
          for(int c=0;c<N;c++)
            {
              cout<<arr_one[r][c];
            }
        cout<<' ';
          for(int c=0;c<N;c++)
            {
              cout<<arr_two[r][c];
            }
        cout<<' ';
          for(int c=0;c<N;c++)
            {
              cout<<arr_thr[r][c];
            }
        cout<<endl;
        }
      

      
    }
}