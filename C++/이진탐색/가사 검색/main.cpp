#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//외부 코드 참고 -> resize가 아니라 aaa~zzz?
//lower/ upper 사용
//왜 시간 초과 뜨는지 모르겠음
//길이로 분류해서 하는 방법은 C++에서는 시간초과 뜸
//아예 비교함수 + bound 함수 사용
vector<string> words_leng[10001];
vector<string> reversed_words[10001];
vector <string> words_not_re;
vector <string> words_re;
bool comp(const string& a, const string& b) {
    if (a.length() < b.length())
        return true;
    else if (a.length() == b.length())
        if (a < b) return true;
    return false;
}
static bool cmp(string& a, string &b)
{
    if(a.length() < b.length())
    {
        return true;
    }
    else if(a.length() == b.length())
    {
        if(a< b)
        {
            return true;
        }
        else 
            return false;
    }
    else
    {
        return false;
    }
}
int find_small(vector<string>words,string query, int start, int end)
{
    //cout<<query<<' '<<start<<' '<<end<<endl;
    int w_size = words.size();
    if(start>end)
        return -1;
    int mid = static_cast<int>((start+end)/2);
    //cout<<mid<<endl;
    if((mid == 0 || words[mid-1].compare(query) < 0) && words[mid].compare(query) == 0)
        return mid;
    else if (words[mid].compare(query)>=0)
        return find_small(words,query,start,mid-1);
    else
        return find_small(words,query,mid+1,end);
}
int find_big(vector<string>words,string query,int start, int end)
{
    int w_size = words.size();
    if(start>end)
        return -1;
    int mid = static_cast<int>((start+end)/2);
    if((mid == w_size -1 || words[mid+1].compare(query)>0) && words[mid].compare(query) == 0)
        return mid;
    else if(words[mid].compare(query)<=0)
        return find_big(words,query,mid+1,end);
    else
        return find_big(words,query,start,mid-1);
        
}
vector<int> bi_calc(vector<string> queries)
{
    vector<int> answer;
        for (string query : queries) {
        if (query[0] != '?') { 
            string start(query);
            for (int i = 0; i < start.length(); ++i)
                if (start[i] == '?') 
                    start[i] = 'a';
            auto start_ptr = lower_bound(words_not_re.begin(), words_not_re.end(), start, comp);

            string end(query);
            for (int i = 0; i < end.length(); ++i)
                if (end[i] == '?') 
                    end[i] = 'z';
            auto end_ptr = upper_bound(words_not_re.begin(), words_not_re.end(), end, comp);
            answer.push_back(end_ptr-start_ptr);
        }
        else { 
            reverse(query.begin(), query.end());
            string start(query);
            for (int i = 0; i < start.length(); ++i)
                if (start[i] == '?')
                    start[i] = 'a';
            auto start_ptr = lower_bound(words_re.begin(), words_re.end(), start, comp); 

            string end(query);
            for (int i = 0; i < end.length(); ++i)
                if (end[i] == '?')
                    end[i] = 'z';
            auto end_ptr = upper_bound(words_re.begin(), words_re.end(), end, comp);

            answer.push_back(end_ptr - start_ptr);
        }
    }
    return answer;
}
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> tmp_words = words;
    sort(words.begin(),words.end(),comp);
    for(int i=0;i<words.size();i++)
    {
        reverse(tmp_words[i].begin(),tmp_words[i].end());
    }
    sort(tmp_words.begin(),tmp_words.end(),comp);
    words_not_re = words;
    words_re = tmp_words;
    answer = bi_calc(queries);
    //정렬된 데이터에 쿼리 한글자씩 이진 탐색 -> 첫글자로는 이진 가능 허나 두번째 글자부터는 정렬이 안되있음
    //뒤 물음표인것 - 물음표 전 범주로 전체 비교해서 이진 탐색 - 글자 단위 X
    //앞 물음표인것 - 뒤집어서 정렬후 앞 문자로 비교(범주 필요함)
    //한글자씩 정렬?-> 시간 초과 예상
    //기존 아이디어 -> 앞에 문자 지우고 매번 정렬 -> 코드 복잡해짐,시간 초과,복잡해져서 나타나는 에러
    return answer;
}
//end
int main() {
  vector<string> a = {"fro?o","sumin","good","nice"};
  vector <string> words = {"frodo","front","frost","frozen","frame","kakao"};
  vector<string>queries = {"fro??", "????o","fr???","fro???","pro?"};
  vector<int> result = solution(words,queries);
}