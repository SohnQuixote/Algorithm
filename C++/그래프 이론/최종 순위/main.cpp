#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
/*
  최종 순위
  순위가 주어짐
  상대적으로 순위가 바뀐 사람들이 주어짐
  바뀐 것으로 순위 확정 -> 출력
  순위 모르겠음 -> ?
  순위에 모순이 있음 -> IMPOSSIBLE ->그래프에 루프가 존재함
  처음 순위 그래프
  위상정렬 사용해서 변경된 그래프에서 정렬해서 출력
  seg fault 발생  
*/
vector<string> fin_results;
void print_adj_rank(vector<vector<bool>> graphs, vector<int> ranks, vector<int> degrees)
{
  //위상 정렬 잘됨
  int N = ranks.size();
  //degrees를 보고 0인 값을 ranks의 인덱스로 하여 출력
  //처음부터 0인 값이 없으면 IMPOSSIBLE
  queue<int> q;
  vector<int> results;
  for(int i =0;i<N;i++)
    {
      if(degrees[i] == 0)
        q.push(i);
    }
  for(int i=0;i<N;i++)
    {
      if(q.empty())
      {
        //cout<<"?"<<endl;
        //fin_results.push_back("IMPOSSIBLE");
        cout<<"IMPOSSIBLE"<<endl;
        return;
      }
      if(q.size() >=2)
      {
        //fin_results.push_back("?");
        cout<<"?"<<endl;
        return;
      }
      int cur = q.front();
      q.pop();
      results.push_back(ranks[cur]);
      for(int j = 0;j<N;j++)
      {
        if(graphs[cur][j])
        {
          
          graphs[cur][j] = false;
          if(--degrees[j] == 0)
          {
            q.push(j);
          }
        }
      }
      
    }
  /*string tmp;
  for(int i=0;i<N;i++)
    {
      //cout<<results[i]<<endl;
      tmp.push_back(results[i] +48); //숫자가 10이하인것만 됨
      tmp.push_back(' ');
    }
  fin_results.push_back(tmp);*/
  for(int i=0;i<N;i++)
    {
      cout<<results[i]<<' ';
    }
  cout<<endl;
}
int find_rank(vector<int> ranks, int tn)
{
  int result =0;
  for(int i=0;i<ranks.size();i++)
    {
      if(ranks[i] == tn)
      {
        result = i;
        break;        
      }
      
    }
  return result;
}
int main() {
  //std::cout << "Hello World!\n";
  int T;
  cin>>T;
  for(int te=0;te<T;te++)
    {
      int N,M;
      vector<int> ranks;
      vector<int> degrees;
      //vector<pair<int,int>> changed;
      cin>>N;
      for(int j=0;j<N;j++)
        {
          int tmp;
          cin>>tmp;
          ranks.push_back(tmp);
          //순위 낮은 사람이 자기 앞에 있는거 전부 다 가리키는 형식으로 변경
          //뒤에 있는게 앞으로 가리켜야 하기에 배열로 표현하기에는 무리
          degrees.push_back(0); //가리킴 당하는 수
          //정렬시 앞에 있는 거 모두 1뺌
          //0인거 큐에 넣음
          //처음부터 degree 0인게 없음 -> IMPOSSIBLE
          //다 안했는데 degree 0인게 없음 -> ?
        }
      //graphs.clear();
      vector<vector<bool>> b_graph(N,vector<bool>(N,false));
      //vector<int> graphs[N];
      for(int i=0;i<N-1;i++)
        {
          for(int j=i+1;j<N;j++)
            {
              //graphs[i].push_back(j);
              b_graph[i][j] = true;
              degrees[j] +=1;
              //cout<<i<<' '<<j<<endl;
            }
          
        }
      cin>>M;
      for(int i=0;i<M;i++)
        {
          int a,b;
          cin>>a>>b;
          //changed.push_back(make_pair(a,b));
          int r_a,r_b;
          r_a = find_rank(ranks,a);
          r_b = find_rank(ranks,b);
          //cout<<ranks[r_a]<<' '<<ranks[r_b]<<endl;
          //해당 팀의 인덱스임
          if(b_graph[r_a][r_b])
          {
            degrees[r_b] -=1;
            degrees[r_a] +=1;
            b_graph[r_a][r_b] = false;
            b_graph[r_b][r_a] = true;
          }

          else
          {
            degrees[r_a] -=1;
            degrees[r_b] +=1;
            b_graph[r_b][r_a] = false;
            b_graph[r_a][r_b] = true;  
          }
          /*if(r_a<r_b)
          {
            //a가 b를 가리키고 있었음
            //b가 a를 가리키고 있게 변경
            degrees[r_b] -=1;
            degrees[r_a] +=1;
            int diff = r_b -r_a-1;
            
            graphs[r_a].erase(graphs[r_a].begin()+diff);
            graphs[r_b].push_back(r_a);
          }
          else
          {
            //b가 a를
            degrees[r_a] -=1;
            degrees[r_b] +=1;
            int diff = r_a-r_b-1;
            
            //cout<<diff<<endl;
            //cout<<graphs[b][diff]<<endl;
            graphs[r_b].erase(graphs[r_b].begin()+diff);
            graphs[r_a].push_back(r_b);
          }*/
          //위상정렬
          
          //뭐가 뒤에 있는지 판별 해야함
          //앞에서 뒤로 가리키는거 삭제
          //뒤에서 앞으로 가리킴
        }
      print_adj_rank(b_graph,ranks,degrees);
      ranks.clear();
      vector<int>().swap(ranks);
      degrees.clear();
      vector<int>().swap(degrees);
      /*for(int i=0;i<N;i++)
        {
          graphs[i].clear();
          vector<int>().swap(graphs[i]);
        }*/
      
    }
  /*for(int i=0;i<T;i++)
    {
      cout<<fin_results[i]<<endl;
    }*/
}