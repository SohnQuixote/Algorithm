#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;
/*
    외벽 점검 
    특정 인원 조합으로 골라서 모든 시작지 채워봄
*/
const int MAX  =201;
int wall[MAX] = {0,};
vector<vector<int>> repeated_comb;
void Combination(vector<int> weak, vector<int> comb, int index, int depth)
{
    if (depth == comb.size()) 
    {
        vector<int> temp;
        for(int i = 0; i < comb.size(); i++)
            temp.push_back(comb[i]);
        repeated_comb.push_back(temp);
        return;
    }
    else
    {
        for(int i = index; i < weak.size(); i++)
        {
            comb[depth] = weak[i];
            Combination(weak, comb, i, depth + 1);
        }
    }
}

bool calc_clock(vector<int> comb, vector<int>dist,vector<int> temp_wall,vector<int> cc_wall,int M)
{
    bool result = false;
    if(accumulate(temp_wall.begin(),temp_wall.end() , 0) == temp_wall.size() || accumulate(cc_wall.begin(),cc_wall.end() , 0) == cc_wall.size())
    {
        return true;
    }

        for(int j=0;j<repeated_comb.size();j++)
        {
            for(int p=0;p<M;p++)
            {
                int start = repeated_comb[j][p];
            for(int i=0;i<comb.size();i++)
            {
            if(comb[i] == 1)
            {
                    for(int s=start;s<=start + dist[i];s++)
                    {
                        //시계 방향 체크
                        int idx = s % temp_wall.size();
                        if(temp_wall[idx]== 0)
                            temp_wall[idx] = (temp_wall[idx] +1);
                    }
                    for(int s = start;s>=start - dist[i];s--)
                    {
                        //반시계 체크
                        int idx = s% cc_wall.size();
                        if(idx<0)
                            idx += cc_wall.size();
                        if(cc_wall[idx] == 0)
                            cc_wall[idx] = (cc_wall[idx] +1 );
                    }
                    comb[i] =0;
                    //고른거 없애야 함?
                    return calc_clock(comb,dist,temp_wall,cc_wall,M);
                    comb[i] = 1;
                    for(int s=start;s<=start + dist[i];s++)
                    {
                        int idx = s % temp_wall.size();
                        temp_wall[idx] = wall[idx];
                    }
                    for(int s = start;s>=start - dist[i];s--)
                    {
                        int idx = s% cc_wall.size();
                        if(idx<0)
                            idx += cc_wall.size();
                        cc_wall[idx] = wall[idx];
                    }
                
            }
            }
        }
    }
    return result;
}
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1;
    int n_weaks = weak.size();
    int n_friends = dist.size();
    vector<int> temp_wall;
    vector<int> cc_wall;
    for(int i=0;i<n;i++)
    {
        wall[i] = 1;
        temp_wall.push_back(1);
        cc_wall.push_back(1);
    } //1로 초기화
    for(int i=0;i<n_weaks;i++)
    {
        wall[weak[i]] = 0;
        temp_wall[weak[i]] = 0;
        cc_wall[weak[i]] = 0;
    } //취약점 0
    // n_friends에서 1부터 n_friends까지 뽑아서 시도 해봄
    //다 해봐도 안되면 -1
    //성공하면 볼 필요가 없음
    vector<int>comb;
  for(int i=0;i<n_friends;i++)
    {
      comb.push_back(0);
    }
for(int M=1;M<=n_friends;M++)
{
    //1명부터 모두 까지
  for(int i=0;i<M;i++)
    {
      comb[i] = 1;
    }
    
    sort(comb.begin(),comb.end());
    
  do{
    //조합 사용
    //조합용 배열 comb
    //comb가 1일때만 봄
      repeated_comb.clear();
      vector<int>weak_comb(M);
      Combination(weak,weak_comb,0,0);
          if(calc_clock(comb,dist,temp_wall,cc_wall,M))
          {
              return M;
          }
          //weak_comb는 중복조합 필요 
  }while(next_permutation(comb.begin(),comb.end()));
  for(int i=0;i<n_friends;i++)
  {
      comb[i] = 0;
  }
  
}
    
    return answer;
}











int main() {
  int r=2;
  vector<int>weaks = {1,5,6,10};
  vector<int>weak_comb(r);
  Combination(weaks,weak_comb,0,0);
  for(int i=0;i<repeated_comb.size();i++)
    {
      for(int j=0;j<r;j++)
        {
          cout<<repeated_comb[i][j]<<' ';
        }
      cout<<endl;
    }
}