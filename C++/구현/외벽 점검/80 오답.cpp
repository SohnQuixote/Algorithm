#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
    외벽 점검 
    특정 인원 조합으로 골라서 모든 시작지 채워봄
*/
const int MAX  =201;
int wall[MAX] = {0,};
bool calc_clock(vector<int> comb, vector<int> weak_comb,vector<int> weak,vector<int>dist,vector<int> temp_wall,vector<int> cc_wall)
{
    bool result = false;
    if(accumulate(temp_wall.begin(),temp_wall.end() , 0) == temp_wall.size() || accumulate(cc_wall.begin(),cc_wall.end() , 0) == cc_wall.size())
    {
        return true;
    }
    for(int i=0;i<comb.size();i++)
    {
        for(int j=0;j<weak_comb.size();j++)
        {
            if(comb[i] == 1)
            {
                if(weak_comb[j] == 1)
                {
                    for(int s=weak[j];s<=weak[j] + dist[i];s++)
                    {
                        //시계 방향 체크
                        int idx = s % temp_wall.size();
                        if(temp_wall[idx]== 0)
                            temp_wall[idx] = (temp_wall[idx] +1);
                    }
                    for(int s = weak[j];s>=weak[j] - dist[i];s--)
                    {
                        //반시계 체크
                        int idx = s% cc_wall.size();
                        if(idx<0)
                            idx += cc_wall.size();
                        if(cc_wall[idx] == 0)
                            cc_wall[idx] = (cc_wall[idx] +1 );
                    }
                    comb[i] =0;
                    weak_comb[j] = 0;
                    return calc_clock(comb,weak_comb,weak,dist,temp_wall,cc_wall);
                    comb[i] = 1;
                    weak_comb[j] = 1;
                    for(int s=weak[j];s<=weak[j] + dist[i];s++)
                    {
                        int idx = s % temp_wall.size();
                        temp_wall[idx] = wall[idx];
                    }
                    for(int s = weak[j];s>=weak[j] - dist[i];s--)
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
    vector<int> weak_comb;
  for(int i=0;i<n_friends;i++)
    {
      comb.push_back(0);
    }
    for(int i=0;i<n_weaks;i++)
    {
        weak_comb.push_back(0);
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
     for(int i=0;i<M;i++)
    {
        weak_comb[i] = 1;
    }
      sort(weak_comb.begin(),weak_comb.end());
      do{
          if(calc_clock(comb,weak_comb,weak,dist,temp_wall,cc_wall))
          {
              return M;
          }
          
      }while(next_permutation(weak_comb.begin(), weak_comb.end()));
    for(int i=0;i<n_weaks;i++)
  {
      weak_comb[i] = 0;
  }
  }while(next_permutation(comb.begin(),comb.end()));
  for(int i=0;i<n_friends;i++)
  {
      comb[i] = 0;
  }
  
}
    
    return answer;
}

















int main() {
}