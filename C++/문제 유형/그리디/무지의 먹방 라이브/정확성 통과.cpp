#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 1;
    int size = food_times.size();
    int tmp_size = size;
    k+=1;
    for(int i=0;k>0;i++)
    {
        i%=size;
        if(food_times[i] != 0 )
        {
            food_times[i]--;
            if(food_times[i] == 0)
                tmp_size -=1;
            k--;
            answer = i+1;
        }
        if(tmp_size ==0 && k!=0)
            return -1; //다먹었는데 시간 남음
    }
    return answer;
}