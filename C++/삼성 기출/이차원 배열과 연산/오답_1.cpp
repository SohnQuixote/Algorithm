#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
  이차원 배열과 연산
  크기 3*3 배열 A
  R연산 - 모든 행 정렬 
-> 행의 개수>= 열개수
  C연산 - 모든열 정렬 행의 개수 < 열 개수
  정렬 기준 등장 횟수 커지는 순
*/
int r,c,k;
vector<vector<int>>A(100,vector<int>(100,0));
void print(int r_size,int c_size)
{
  cout<<endl<<"printing::"<<endl;
  for(int i=0;i<r_size;i++)
    {
      for(int j=0;j<c_size;j++)
        {
          cout<<A[i][j]<<' ';
        }
      cout<<endl;
    }
}
bool cmp(const pair<int,int>&a, const pair<int,int>&b)
{
  if(a.first>b.first)
  {
    return false;
  }
  else if(a.first == b.first)
  {
    if(a.second<b.second)
      return true;
  else 
      return false;
  }
  else
  {
    return true;
  }
}

vector<int> unit_sort(vector<int>b)
{
  vector<int>tmp(100,0);
  vector<int>result; 
  vector<pair<int,int>>s;
  for(int i=0;i<b.size();i++)
    {
      if(b[i])
        tmp[b[i]]++;
    }
  for(int i=1;i<100;i++)
    {
      if(tmp[i])
      {
        s.push_back(make_pair(tmp[i],i));
      }
    }
    sort(s.begin(),s.end(),cmp);
    int t = 0;
    for(int i=0;i<s.size();i++)
      {
        result.push_back(s[i].second);
        result.push_back(s[i].first);
        t+=2;
        if(t==100)
          break;
      }
  return result;
}
void sp_sort(vector<vector<int>>&a, int &r_size,int &c_size)
{
  int chged_size;
  //vector<int>tmp;
  if(r_size>=c_size)
  {
    //행 정렬
    chged_size = c_size;
    for(int r=0;r<r_size;r++)
      {
        vector<int>tmp;
        //앞에서부터 0이 있을 수도 있음 -0없는거만 넣는것 -비효율
        //정렬에서 0을 무시 
        for(int c=0;c<c_size;c++)
          {
            if(a[r][c])
              tmp.push_back(a[r][c]);
          }
          tmp = unit_sort(tmp);
          int size = tmp.size();
        for(int c=0;c<size;c++)
          {
            a[r][c] = tmp[c];
          }
        for(int c=size;c<c_size;c++)
          {
            a[r][c] = 0;
          }
          chged_size = max(chged_size,size);
      }
    c_size = chged_size;
  }
  else
  {
    //열 정렬
    chged_size = r_size;
    for(int c=0;c<c_size;c++)
      {
        vector<int>tmp;
        //앞에서부터 0이 있을 수도 있음 -0없는거만 넣는것 -비효율
        //정렬에서 0을 무시 
        for(int r=0;r<r_size;r++)
          {
            if(a[r][c])
              tmp.push_back(a[r][c]);
          }
          tmp = unit_sort(tmp);
          int size = tmp.size();
        for(int r=0;r<size;r++)
          {
            a[r][c] = tmp[r];
          }
        for(int r=size;r<r_size;r++)
          {
            a[r][c] = 0;
          }
          chged_size = max(chged_size,size);
      }
    r_size = chged_size;

  }
  //최대의 크기
}

int chk(int sec)
{
  if(A[r][c]==k)
    return 0;
  //기저사례
  sec++;
  int r_size = 3;
  int c_size = 3;
  while(sec<=100)
    {
      sp_sort(A,r_size,c_size);
      //print(r_size,c_size);
      if(A[r][c] == k)
        return sec;
      sec++;
    }
  return -1;
}
int main() {
  cin>>r>>c>>k;
  r--;
  c--;
  for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
        cin>>A[i][j];
    }
  cout<<chk(0)<<endl;
  
}