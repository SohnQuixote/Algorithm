#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
  KLIS

  단조 증가 할때
  이중 가장 긴것을 LIS
  LIS 두개 이상 가능
  중복 숫자 없는 수열 주어질 때 사전 순서대로 맨 앞에서 K번째 있는 LIS 구하기
  모든 숫자가 서로 다른 수열이 주어짐
  이 수열중 사전순서대로 맨앞에서 K번째에 있는 LIS를 구하기
  LIS는 어떻게 구했지?
  오랫동안 고민해서 답지
  -> 재귀 호출 -> 동적 계획법
  k번째 답을 구하는 문제를 풀기 위해서
  -> 답의 수를 세는 문제를 푼다
  -> 답의 수를 기반으로 문제를 재구성한다.
  바탕이 되는 최적화 문제를 푼다
  -> 최적화 문제의 최적해를 세는 문제를 푼다
  -> 답의 수를 기반으로 답안을 재구성한다.
  필요한 함수
  lis(start) -> start에서 시작하는 LIS의 길이
  count(start) -> start에서 시작하는 LIS의 수
  -1부터 시작
  arr[-1] = -INF
*/
int C;
int N, K;
int cache_length[501];
int cache_cnt[501];
int arr[501];
const int INF = 2147483646;
int lis(int start) {
  int &ret = cache_length[start + 1];
  if (ret != -1)
    return ret;
  ret = 1;
  for (int next = start + 1; next < N; next++) {
    if (start == -1 || (arr[next] > arr[start]))
      ret = max(ret, lis(next) + 1);
  }
  return ret;
}
// start에서 시작하는 LIS의 길이

int count(int start) {
  //하나만 있는 경우는 1개임
  //기저사례
  if (lis(start) == 1)
    return 1;
  int &ret = cache_cnt[start + 1];
  if (ret != -1)
    return ret;
  ret = 0;
  // 0으로 시작해서 모든 경우의 수를 다 판별해야함
  for (int next = start + 1; next < N; next++) {
    if ( (start == -1 || arr[next] > arr[start]) && lis(next) + 1 == lis(start))
      ret = min<long long>(INF, (long long)ret + (long long)count(next));
    //오버 플로우 방지해야함
  }
  return ret;
}
void reconst(int start, int k, vector<int> &klis) {
  if (start != -1)
    klis.push_back(arr[start]);
  vector<pair<int, int>> candid;
  for (int next = start + 1; next < N; next++) {
    if ( (start == -1 || arr[next] > arr[start]) && lis(next) + 1 == lis(start))
      candid.push_back({arr[next], next});
  }
  sort(candid.begin(),candid.end());
  for (int i = 0; i < candid.size(); i++) {
    int idx = candid[i].second;
    int cnt = count(idx);
    if(k>=cnt)
      k-=cnt;
    else
    {
      reconst(idx , k, klis);
      break;
    }
  }
}
// start에서 시작하는 LIS의 수
// LIS(start) = LIS(next)+1이어야지 해당 숫자로 가서 LIS를 갖고옴
int main() {

  cin >> C;
  for (int tc = 0; tc < C; tc++) {
    cin >> N >> K;
    memset(cache_cnt,-1,sizeof(cache_cnt));
    memset(cache_length , -1 , sizeof(cache_length));
    
    for (int i = 0; i < N; i++)
      cin >> arr[i];
    vector<int>klis;
    klis.clear();
    reconst(-1,K-1,klis); //K-1번을 건너뛰어야함
    cout<<klis.size()<<'\n';
    for(int i=0;i<klis.size();i++)
      cout<<klis[i]<<' ';
    cout<<'\n';
  }
}