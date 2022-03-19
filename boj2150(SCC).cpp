#include<stdio.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include<stack>
#define MAXN 2100000000

using namespace std;

int n, m;


int dfsn[100000];
vector<int> graph[10000];
stack<int> s;
vector< vector<int> > scc;
int cnt=0;
int id=0;
int sccn[10000];
bool finished[100000];



int dfs(int curr){
  dfsn[curr] = ++id;
  s.push(curr);

  int result = dfsn[curr];
  for(int next : graph[curr]){
    if(dfsn[next] == 0){
      result = min(result, dfs(next));
    }
    else if(!finished[next]) result = min(result, dfsn[next]);
  }

  if(result == dfsn[curr]){
    vector<int> currscc;

    while(1){
      int tmp = s.top();
      s.pop();
      currscc.push_back(tmp);
      finished[tmp] = 1;
      sccn[tmp] = cnt;
      if(tmp == curr) break;
    }
    cnt++;
    sort(currscc.begin(), currscc.end());

    scc.push_back(currscc);


  }

  return result;
}


int main(){

  scanf("%d %d", &n, &m);
  //vector<int> par(n+1);

  for(int i=0; i<m; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    graph[a].push_back(b);
  }


  for(int i=1; i<=n; i++){
    if(dfsn[i] == 0){
      dfs(i);
    }
  }


  sort(scc.begin(), scc.end());

  printf("%d\n", cnt);

  for(auto& currscc : scc){
    for(int curr:currscc){
      printf("%d ", curr);
    }
    printf("-1\n");
  }


  return 0;
}
