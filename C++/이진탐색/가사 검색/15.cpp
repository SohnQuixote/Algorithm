//start

#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <algorithm>
using namespace std;
//start
/*
    노래가사 키워드 몇개 포함?
    ex. fro?? ->frogs front O frozen X
    모든 단어 배열 words
    키워드 배열 queries
    각 키워드 매치된 단어
    글자 하나씩 보면서 범위 좁히기 ?는 다 됨 첫글자 f면 f인것만
    글자 길이도 생각해야함
    문자열 하나씩 보면서 이진 탐색으로 해당 범위 축출해서 또 이진 탐색
    처음부터 글자 첫번째와 size맞는거  length()
    글자길이에 맞게 처음부터 매칭되면 편할거 같음
*/
vector<string> words_leng[10001];
//글자 길이에 맞는 곳에 push_back
//하나씩 정렬
//찾을때는 글자 수에 맞는 곳으로 가서 글자 하나씩
const int IMPOSSIBLE = -1;
int bi_search_big(vector<string>words,int idx,int start, int end, char target)
{
    //시작점 반환
    //정렬을 해도 두번째 원소는 정렬이 안되있음
    if(start>end)
        return IMPOSSIBLE;
    int mid = static_cast<int>((start+end)/2);
    //cout<<"big check    "<<words[mid][idx]<<endl;
   //첫번째 인덱스 우선이라서 글자마다 정렬해야함
    if((mid == words.size()-1 || target < words[mid+1][0]) && target == words[mid][0] )
        return mid;
    else if(target>= words[mid][0])//원하는 글자가 앞에 있음
        return bi_search_big(words,idx,mid+1,end,target);
    else
        return bi_search_big(words,idx,start,mid-1,target);
}
int bi_search_small(vector<string>words,int idx,int start, int end, char target)
{
    //시작점 반환
    if(start>end)
        return IMPOSSIBLE;
    int mid = static_cast<int>((start+end)/2);
    if((mid == 0 || target> words[mid-1][0]) && target == words[mid][0] )
        return mid;
    else if(target<= words[mid][0])//원하는 글자가 앞에 있음
        return bi_search_small(words,idx,start,mid-1,target);
    else
        return bi_search_small(words,idx,mid+1,end,target);
}
pair<int,int> bi_search_cha(vector<string>words, string query,int idx,int start, int end)
{
    //글자 물음표면 그냥 반환
    //볼 문자열, 문자 , 볼 문자 하나, 시작 지점, 끝 지점
    //해당 문제 체크
    pair<int,int> result;
    char temp = query[idx];
    //char que ="?";
    //글자 비교가 안됨
    if(temp =='?') //"?"로 하면 const char *로 되버림 타입오류로 비교 불가능 
    {
        return make_pair(start,end);
    }
    result.first = bi_search_small(words,idx,start,end,temp);
    result.second = bi_search_big(words,idx,start,end,temp);
    //cout<<"finding  "<<query[idx]<<' '<<result.first<<' '<<result.second<<endl;
    return result;
}
int bi_search_whole(vector<string> words,string query)
{
    //해당 길이 문자 배열, 원하는 단어
    int q_length = query.length();
    //cout<<"쿼리와 길이"<<query<<"    "<<q_length<<endl;
    pair<int,int> range;
    range.first = 0;
    range.second = words.size()-1;
    /*for(int i=0;i<=range.second;i++)
      {
        cout<<"정렬된 특정 길이 문자열들" <<words[i]<<endl;
      }*/
    //처음 사이즈
    vector<string> tmp_words = words;
    //매번 할때마다 맨앞 원소 지워야함 그리고 재정렬
    for(int i=0;i<q_length;i++)
    {
        //cout<<"범위"<<range.first<<' '<<range.second<<endl;
        /*for(int i=0;i<tmp_words.size();i++)
          {
            cout<<"검색 배열"<<tmp_words[i]<<endl;
          }
        cout<<endl<<endl;*/
        vector<string> pre_words = tmp_words;//범위 찾기전
        range = bi_search_cha(tmp_words,query,i,0,tmp_words.size()-1); //해당 범위 찾음
        tmp_words.clear();
        if(i!= q_length-1)  //글자 하나
        {
        for(int j=range.first;j<=range.second;j++)
        {
            tmp_words.push_back(pre_words[j]); //해당 범위만큼 넣음
        }
        for(int j=0;j<tmp_words.size();j++)
        {
            tmp_words[j].erase(0,1);//앞글자 삭제
        }
        sort(tmp_words.begin(),tmp_words.end());
        }
        if(range.first == IMPOSSIBLE || range.second == IMPOSSIBLE)
        {
            return 0;
        }
    }
    return range.second - range.first +1;
}
vector<int> solution(vector<string> words, vector<string> queries) 
{
    vector<int> answer;
    vector<int> leng_idxes;//글자 길이 저장
    //sort(words.begin(),words.end());
    for(int i=0;i<words.size();i++)
    {
        if(words_leng[words[i].length()].size()==0)
            leng_idxes.push_back(words[i].length()); //글자 길이 확인
        words_leng[words[i].length()].push_back(words[i]);
        //글자 길이에 맞는 곳에 push_back
    }
    for(int i=0;i<leng_idxes.size();i++)
    {
        sort(words_leng[leng_idxes[i]].begin(),words_leng[leng_idxes[i]].end());
    }
    for(int i=0;i<queries.size();i++)
    {
        bool flag = false;
        for(int j=0;j<leng_idxes.size();j++)
        {
            if(queries[i].length() == leng_idxes[j])
            {
                flag = true;
                break;
            }
        }
        if(flag)
        {
            //answer.push_back(1);
            answer.push_back(bi_search_whole(words_leng[queries[i].length()],queries[i]));
        }
        else //원하는 길이 없음
        {
            answer.push_back(0);
        }
    }
    return answer;
}







//end
int main() {
  vector<string> a = {"fro?o","sumin","good","nice"};
  vector <string> words = {"frodo","front","frost","frozen","frame","kakao"};
  vector<string>queries = {"fro??", "????o","fr???","fro???","pro?"};
  vector<int> result = solution(words,queries);
}