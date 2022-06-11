#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
    WILDCARD
    ? -> 어떤 글자와도 대응
    * -> 0글자 이상 어떤 문자열에도 대응
    와일드 카드 패턴 -> 파일명 집합 -> 패턴 대응 파일명 찾기
    * -> 나눔
    동적 계획 -> 완전 탐색을 한후 반복되는 부분 삭제 
*/
vector<vector<int>>cache(101,vector<int>(101,-1));
//접미사 길이를 사용하여 메모이제이션
string W,S;
bool matchMemo(int w,int s)
{
    int &ret = cache[w][s];
    if(ret!= -1) return ret;
    while(s<S.size() && w<W.size()&&(W[w] == '?' || W[w] == S[s]))
    {
        w++;
        s++;
    }
    if(w==W.size()) return ret = (s == S.size());
    if(W[w] == '*')
    {
        for(int skip = 0;(s+skip)<=S.size();skip++)
        {
            if(matchMemo(w+1,s+skip))
                return ret = 1;

        }

    }
    return ret = 0;
}
bool match(const string &w, const string &s)
{
    //완전탐색 매치
    int p = 0;
    while(p<w.size() &&p<s.size() && (w[p] == s[p]|| w[p] == '?' ))
    {
        p++;
    }
    if(p == w.size())
        return(p==s.size()); //끝까지 갔음 -> 길이가 같아야함
    if(w[p] == '*')
    {
        for(int skip = 0;(p+skip)<=s.size();skip++)
        {
            if(match(w.substr(p+1),s.substr(p+skip)))
                return true;//*와 aa면 "" "" 까지 호출됨
        }

    }

    return false;
}
int main()
{
    //테스트 케이스 수 생략
    //string W;
    vector<string>results;
    int N;
    cin>>W;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        string tmp;
        cin>>tmp;
        if(match(W,tmp))//입력하자마자 체크
            results.push_back(tmp);
    }
    sort(results.begin(),results.end());
    //results출력 생략
}