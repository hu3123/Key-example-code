#include<stdio.h>
#include<algorithm>
#include<iostream>


using namespace std;

int n, k;

int memo[101][100001];

struct bag{
  int w;
  int v;
} arr[101];

int f(int p,  int we){

  //printf("%d %d\n", p, we);

  if(memo[p][we]>0) return memo[p][we];
  if(p == n) return 0;

  int n1=0;

  if(we + arr[p].w <= k){
    n1 = arr[p].v + f(p + 1, we + arr[p].w);
  }
  int n2 = f(p+1, we);
  return memo[p][we] = max(n1, n2);

}

int main(){
  scanf("%d %d", &n, &k);
  for(int i=0; i<n; i++){
    scanf("%d %d", &arr[i].w, &arr[i].v);
  }
  printf("%d", f(0, 0));


  return 0;
}
