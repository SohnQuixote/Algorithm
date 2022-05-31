#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
  연산자 끼워 넣기
  N개의 수로 이루어진 수열 A1 ~ AN
  수와 수 N-1 연산자
  주어진 수의 순서 바꾸면 안됨
  연산자 - 결과 최솟값/최댓값
  BFS 사용  
*/
const int MAX = 12;
const int CHOIDAE =  1234583647;
const int CHOISOE =  -1234583647;//최솟값 최댓값 비교용
int max_result = CHOISOE;
int min_result = CHOIDAE;
vector<int> operators; //덥 뺄 곱 나
int numbers[MAX] = {0,};
int N;
void calc(int start_index, vector<int> operators, int added)
{//시작 인덱스 사용한 오퍼레이터 더해진 결과
  //vector<int>tmp_operators = operators;
  queue<int> q;
  //cout<<added<<endl<<endl;
  if(start_index == N-1)
  {
    max_result = max(max_result,added);
    min_result = min(min_result,added);
    return;
  }
  for(int i=0;i<4;i++)
    {
      if(operators[i] != 0)
        q.push(i);
    }
    while(!q.empty())
      {
        int index = q.front();
        q.pop();
        int tmp = added;
        switch(index)
          {
            case 0: //덥
              added += numbers[start_index+1];
            break;
            case 1: //뺄
              added -= numbers[start_index+1];
            break;
            case 2: //곱
              added *= numbers[start_index+1];
            break;
            case 3: //나
              added /= numbers[start_index+1];
            break;
            default:
            break;
          }
          operators[index]-=1;
          //tmp = added;
          calc(start_index+1,operators,added);
          added = tmp;
          operators[index]+=1;
  
      }
}
int main() {
  cin>>N;
  for(int i=0;i<N;i++)
    {
      cin>>numbers[i];
    }
  for(int i=0;i<4;i++)
    {
      int temp;
      cin>>temp;
      operators.push_back(temp);
    }
  calc(0,operators,numbers[0]);
  cout<<max_result<<endl;
  cout<<min_result<<endl;
}