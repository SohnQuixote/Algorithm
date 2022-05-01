#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>
using namespace std;
/*
    우선순위 큐 사용
    접근 방법은 맞았으나 자료구조가 틀렸음
    시간은 괜찮아짐
    우선순위 큐에 넣어서 적은 시간의 음식이 앞으로 오게됨
    다먹고 큐에서 빼버림
    0이면 바로 다음 음식
    남으면 size 나머지 연산해서 인덱스 얻음
*/
int solution(vector<int> food_times, long long k) {
    long long sum = 0;
    int size = food_times.size();
    for(int i=0;i<size;i++)
    {
        sum+= static_cast<long long>(food_times[i]);
    }
    if(sum <=k)
        return -1;
    //다먹어 버림
    int answer = 0;
    long long min_times = 0;//먹은데 걸린 시간들 누적
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<size;i++)
        pq.push(make_pair(food_times[i] , i+1));
    while(!pq.empty())
    {
        long long min_time = static_cast<long long>(pq.top().first) - min_times;
        if(k>= static_cast<long long>(min_time) *static_cast<long long>(size))
        {
            min_times += min_time;
            k-=static_cast<long long>(min_time)*static_cast<long long>(size);
            size -=1;
            pq.pop();  
        }
        else
        {
            vector<int> indexes;
            while(!pq.empty())
            {
                int index = pq.top().second;
                pq.pop();
                indexes.push_back(index);
            }
            
            sort(indexes.begin() , indexes.end());
            long long tmp_size = k % static_cast<long long>(size);
            answer = indexes[static_cast<int>(tmp_size)];
        }
    }
    return answer;
}