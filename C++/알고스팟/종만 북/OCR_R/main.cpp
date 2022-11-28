#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;
/*
  OCR
  과거 자료로 부터 추출한 정보 이용해
문자인식의 정확도를 높이기
  원본일 조건부 확률이 가장 높은 문장
  단어의 수 m 문장의 수 q
  조건부 출현확률 가장 높은 문장 출력
  너무 어려워서 다시 풀어볼 필요가 있음


*/
int n,m,q;
double first_prob[501];
double next_prob[501][501];
double corr_prob[501][501];
string name_to_idx[501];
string sentences[100];
int choice[102][502];
double cache[102][502];
int classified[100];

double recog(int seg,int prev)
{
  if(seg ==n) return 0;
  double &ret = cache[seg][prev];
  if(ret!=1) return ret;
  ret = -1e200;
  int &choose = choice[seg][prev];
  for(int thisM = 1;thisM<=m;thisM++)
    {
      double cand = next_prob[prev][thisM] + corr_prob[thisM][classified[seg]] + recog(seg+1,thisM);
      if(ret<cand)
      {
        ret = cand;
        choose = thisM;
      }
    //여기서 최선의 선택을 저장함



      
    }
    return ret;
  




  
}
string reconst(int seg,int prev)
{
  int choose = choice[seg][prev];
  string result = name_to_idx[choose];
  if(seg < n-1)
    result = result+" "+reconst(seg+1,choose);
  return result;


  
}







int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>m>>q;
  for(int i=1;i<=m;i++)
    {
      cin>>name_to_idx[i];
    }
    for(int i=1;i<=m;i++)
      {
        cin>>first_prob[i];
        first_prob[i] = log(first_prob[i]);
      }
    for(int r=0;r<=m;r++)
      for(int c=1;c<=m;c++)
        {
          if(r==0)
            next_prob[r][c] = first_prob[c];
          else
          {
            cin>>next_prob[r][c];
            next_prob[r][c] = log(next_prob[r][c]);
          }
        }
    for(int r=1;r<=m;r++)
      for(int c=1;c<=m;c++)
        {
          cin>>corr_prob[r][c];
          corr_prob[r][c] = log(corr_prob[r][c]);
        }
    for(int i=0;i<q;i++)
      {
        cin>>n;
        for(int r=0;r<102;r++)
          for(int c=0;c<502;c++)
            cache[r][c] = 1;
        for(int j=0;j<n;j++)
          {
            cin>>sentences[j];
            for(int k=1;k<=m;k++)
              {
                if(sentences[j] == name_to_idx[k])
                {
                  classified[j] = k;
                  //해당 위치에 있는 단어의 인덱스를 알기 위해서
                  break;
                }

                
              }

            
          }
      recog(0,0);
      cout<<reconst(0,0)<<'\n';

        
      }

}