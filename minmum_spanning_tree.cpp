#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int parent[100001];

struct edge{
  int node1;
  int node2;
  int value;
};


bool cmp(edge a, edge b){
  if(a.value != b.value) return a.value <  b.value;
  return min(a.node1, a.node2) < min(b.node1, b.node2);
};



int find(int u){
  if(u == parent[u])return u;
  return find(parent[u]);
}

void uni(int n1, int n2){
  int tmp1 = find(n1);
  int tmp2 = find(n2);

  if(tmp1 == tmp2)return;
  if(tmp1 < tmp2){
    parent[tmp2] = tmp1;
  }
  else parent[tmp1] = tmp2;
  return;
}

bool cycle(int n1, int n2){
  n1 = find(n1);
  n2 = find(n2);
  if(n1==n2) return true;
  else return false;

}





int main(){

  int v, e;

  scanf("%d %d", &v, &e);

  struct edge arr[100001];

  for(int i=0; i<=v; i++){
    parent[i] = i;
  }
  for(int i=0; i<e; i++){
    scanf("%d %d %d", &arr[i].node1, &arr[i].node2, &arr[i].value);
  }

  int sum=0;

  sort(arr, arr+e, cmp);

  for(int i=0; i<e; i++){
      //printf("||%d||", parent[2]);
      if(!cycle(arr[i].node1, arr[i].node2)){
        //printf("*%d %d %d %d\n", arr[i].node1, find(arr[i].node1), arr[i].node2, find(arr[i].node2));
        sum += arr[i].value;
        uni(arr[i].node1, arr[i].node2);
      }
  }


  printf("%d", sum);


  return 0;
}
