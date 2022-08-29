#include <iostream>
#include <vector>
using namespace std;
int n,m,c;
int arr[10][10] = {0,};
vector<int>path;
int get_profit(vector<int> arr,int lvl)
{
  int result = 0;
  //해당 arr의 최대 수익 반환
  //모든 집합을 나열해야함
  //O,X로 선택해서 집합을 선택해서 풀이
  if(lvl==m)
  {
    int chk =0;
    int chk_result = 0;
    for(int i=0;i<arr.size();i++)
      {
        if(path[i])
        {
          chk+=arr[i];
          chk_result +=arr[i] * arr[i];
        }


        
      }
      if(chk<=c)
      {
        return chk_result;
      }

    return 0;
  }


  

  for(int i=0;i<2;i++)
    {
      path.push_back(i);
      result = max(result,get_profit(arr,lvl+1));
      path.pop_back();
    }
  return result;
}
int main() {
  //  vector<int>tong = {7,2,9};
  // m = 3;
  // c = 10;
  // cout<<get_profit(tong,0);
  int tc;
  cin>>tc;
  for(int t=1;t<=tc;t++)
    {
      //벌통 크기 벌통 개수 최대 양
      cin>>n>>m>>c;
      for(int r=0;r<n;r++)
        for(int c=0;c<n;c++)
          cin>>arr[r][c];
      //일단 두 양봉업자의 시작 벌통
      //조합
      //두명이니까 반복문으로 구현 가능
      //그 다음 해당 배열에서 C이하의 합을 가지면서 더하면 최댓값인 것을 구함
      //이것도 조합
      int result= 0;
      for(int fr=0;fr<n;fr++)
        {
          for(int fc=0;fc<=n-m;fc++)
            {
              int start_c = fc+m;
              vector<int>first_honey;
              for(int idx = fc;idx<fc+m;idx++)
                first_honey.push_back(arr[fr][idx]);
              int profit = get_profit(first_honey, 0);
              for(int sr=fr;sr<n;sr++)
                {
                  for(int sc=start_c;sc<=n-m;sc++)
                    {
                      vector<int> second_honey;
                      for(int idx = sc;idx<sc+m;idx++)
                        second_honey.push_back(arr[sr][idx]);
                      int second_profit = get_profit(second_honey,0);
                      profit+=second_profit;
                      result = max(result,profit);
                      profit-=second_profit;
                    }
                  start_c = 0;
        



                  
                }






              
            }




          
        }
      cout<<"#"<<t<<' '<<result<<'\n';
        


      
    }
}