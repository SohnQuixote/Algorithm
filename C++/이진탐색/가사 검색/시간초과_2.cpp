#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//외부 코드 참고 -> resize가 아니라 aaa~zzz?
//lower/ upper 사용
//왜 시간 초과 뜨는지 모르겠음
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
int bi_calc(pair<int,int> query_range, string query)
{
    int front_rear = query_range.first;
    int range = query_range.second;
    string tmp_query =query;
    vector<string> tmp_words;
    if(front_rear == 1)
    {
        if(range == query.size())
            return words_not_re.size();
            //return words.size();
            
        else
        {
            reverse(tmp_query.begin(),tmp_query.end());
            //tmp_words = reversed_words[query.length()];
            tmp_words = words_re;
            range = query.length()- range;
            //뒤로 정렬하는 과정 필요 reverse
            //뒤로 찾기
        }
    }
    //그리고 찾기 range로
    //resize 사용
    //?는 언제나 최소 하나
    else
    {
    tmp_words= words_not_re;
      range+=1;
    }
    /*tmp_query.resize(range);
    for(int i=0;i<tmp_words.size();i++)
    {
        tmp_words[i].resize(range);
    }*/
    string tmp_query_left = tmp_query;
    string tmp_query_right = tmp_query;
    for(int i= range; i< tmp_query.length();i++)
    {
        tmp_query_left[i] = 'a';
        tmp_query_right[i] = 'z';
    }
    //cout<<tmp_query_left<<' '<<tmp_query_right<<endl;
    auto start_ptr = lower_bound(tmp_words.begin(),tmp_words.end(),tmp_query_left,comp);
    auto end_ptr  = upper_bound(tmp_words.begin(),tmp_words.end(),tmp_query_right,comp);
    return end_ptr-start_ptr;
    //cout<<"finding words::"<<tmp_query<<endl<<endl;
    //for(int i=0;i<tmp_words.size();i++)
      //cout<<tmp_words[i]<<endl;
    //int first = find_small(tmp_words,tmp_query_left,0,tmp_words.size()-1);
    //int last = find_big(tmp_words,tmp_query_right,0,tmp_words.size()-1);
    //cout<<first<<' '<<last<<endl;
    //if(first == -1 || last == -1)
        //return 0;
    //return last-first+1;
    
}
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    vector<string> tmp_words = words;
    //reversed_words = words;
    vector<int> leng_idxes;
    vector<pair<int,int>> query_range; //앞/뒤 몇번째 까지 글자/몇번째 부터 글자
    sort(words.begin(),words.end(),comp);
    for(int i=0;i<words.size();i++)
    {
        reverse(tmp_words[i].begin(),tmp_words[i].end());
    }
    sort(tmp_words.begin(),tmp_words.end(),comp);
    words_not_re = words;
    words_re = tmp_words;
    for(int i=0;i<words.size();i++)
    {
        if(words_leng[words[i].length()].size()==0)
            leng_idxes.push_back(words[i].length());
        words_leng[words[i].length()].push_back(words[i]);
        //reverse(tmp_words[i].begin(),tmp_words[i].end());
        //reversed_words[words[i].length()].push_back(tmp_words[i]);
    }
    /*for(int i=0;i<leng_idxes.size();i++)
    {
        sort(words_leng[leng_idxes[i]].begin(),words_leng[leng_idxes[i]].end());
        sort(reversed_words[leng_idxes[i]].begin(),reversed_words[leng_idxes[i]].end());
    }*/
    for(int i =0;i<queries.size();i++)
    {
        bool flag = false;
        
        if(queries[i][0] == '?')
            flag = true;
        for(int j=0;j<queries[i].length();j++)
        {
            if(!flag) //앞은 문자
            {
                if(queries[i][j] == '?')
                {
                    query_range.push_back(make_pair(0,j-1)); //j-1까지 글자
                    break;
                }
            }
            else //앞부터 ?
            {
                if(queries[i][j] != '?')
                {
                    query_range.push_back(make_pair(1,j)); //범위보다 크면 그냥 해당 문자배열 길이 반환
                    break;
                }
                else if(j == queries[i].length() -1) //마지막인데도 ?임
                {
                    query_range.push_back(make_pair(1,j+1));
                    break;
                }
            }
        }
    }
    //cout<<query_range.size();
    for(int i=0;i<query_range.size();i++)
    {
        if(words_leng[queries[i].length()].size()!= 0)
        { 
            answer.push_back(bi_calc(query_range[i],queries[i]));
        }
        else
        {
            answer.push_back(0);
        }
    }
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