#include <iostream>
#include <queue>
#include <vector>
using namespace std;
/*
  버스 갈아타기/버스 환승
  1,1 - m,n
  격자형식으로는 무조건 안됨 -> 행/열 아주 범위가 큼
  격자형식 데이터를 그래프 간선 데이터로 변경하기만 하면 풀리는 문제
  n번 버스 -> 몇번과 연결 -> 양방향 그래프
*/
vector<int> graphs[5001];
struct pos{
  int sx;
  int sy;
  int dx;
  int dy;
};
pos prev_graph[5001];
int m,n;
void make_graph(int a, int b, pos a_coord,pos b_coord)
{
  //수직으로 연결되어 있거나
  //수평으로 이어져 있음
  //그렇다면 양방향 연결
  int a_sx,a_sy,a_dx,a_dy;
  int b_sx,b_sy,b_dx,b_dy;
  a_sx = a_coord.sx; a_sy = a_coord.sy; a_dx = a_coord.dx; a_dy = a_coord.dy;
  b_sx = b_coord.sx; b_sy = b_coord.sy; b_dx = b_coord.dx; b_dy = b_coord.dy;

  //수직 연결 케이스 
  //
  if(a_sy == a_dy)
  {
    //a가 수평


    //1.b 수직
    if(b_sx == b_dx && (a_sx<= b_sx && a_dy>= b_sx))
    {
      if(b_sy<= a_sy && b_dy >=a_sy)
      {
        //겹친다!
        graphs[a].push_back(b);
        graphs[b].push_back(a);
      }
    }

    //2. b 수평

    if(b_sy== b_dy &&(b_sy == a_sy))
    {
      if(b_dx>=a_sx && b_sx<= a_dx)
      {
        //겹친다!
        graphs[a].push_back(b);
        graphs[b].push_back(a);
      }
      
    }



    
  }
  else if(a_sx == a_dx)
  {
    //a가 수직

    //1.b 수직


    //2.b 수평

    
  }
}
vector<int> to_node(int x, int y)
{
  //순환해서 노드 넘버 반환하는 함수

  //노드넘버를 기반으로 모든 경우의 수 BFS 수행해서 최단노드거치는 경로 출력

  
}

int main() {
  cin>>m>>n;
  int k;
  cin>>k;
  for(int i=0;i<k;i++)
    {
      int b,sx,sy,dx,dy;
      cin>>b>>sx>>sy>>dx>>dy;
      prev_graph[b] = {sx,sy,dx,dy};
    }
    int sx,sy,dx,dy;
    cin>>sx>>sy>>dx>>dy;
    for(int i=1;i<=k-1;i++)
      {
        pos a = prev_graph[i];
        for(int j=i+1;j<=k;j++)
          {
            pos b= prev_graph[j];
            make_graph(i,j,a,b);

            
          }



        
      }
    
  
    //시작지 좌표 끝 좌표를 노드 정점으로 변경하는 과정도 필요
    //가능한 출발지 여러개 가능 -> 최소로 가는 법 반환
}