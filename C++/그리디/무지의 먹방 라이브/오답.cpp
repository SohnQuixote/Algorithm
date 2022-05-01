#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
    min_index가 두개일 수도 있음
    food 없는것은 없음
*/
int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int size = food_times.size();
    int tmp_size = size;
    int min =  *min_element(food_times.begin(), food_times.end());
    //최솟값만큼 다 먹어버려서 특정 바퀴를 돔
    while(min && k>=min * tmp_size)
    {
        k-=min * tmp_size;
        for(int i=0;i<size;i++)
        {
            if(food_times[i] != 987654321)
                food_times[i] -= min;
            if(food_times[i] == 0)
            {
                //food_times.erase(food_times+i);
                food_times[i] = 987654321;//다 먹음
                tmp_size--;
            }
                
        }
        
        min = *min_element(food_times.begin(),food_times.end());
    }
    if(k==0 && food_times[0] == 987654321)
        return -1;
    //한바퀴 다돌고 아예 다먹음
    else if(k == 0 && food_times[0] != 987654321)
        return 1;
    //한바퀴 돌았는데 남아있음
    // 0이 아닌 값부터 먹기 시작
    while(k)
    {
        for(int i=0;i<size;i++)
        {
            if(food_times[i] != 987654321)
            {
                answer = i;
                food_times[i] -=1;
                if(food_times[i] == 0)
                {
                    food_times[i] = 987654321;
                }
                k--;
            }
            
        }
        
    }
    return answer+1;
}