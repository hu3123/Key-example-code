#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<list>
#include<vector>
#include<string.h>
#include<math.h>
#define P pair<int, int>
#define N 10007



using namespace std;
int v, e;

struct edge{
    int node;
    int cost;
};

struct psum{
    int node;
    int sum;

};
bool operator<(psum a,psum b){
    return a.sum > b.sum;
}
vector<edge> vec[1001];
int dist[1001];

void dijkstra(int start){

    priority_queue<psum> pq;

    for(int i=0; i<v+1; i++){
        dist[i]=2100000000;
    }
    dist[start]=0;
    pq.push({start, 0});
    while(!pq.empty()){
        //printf("!");

        int l=vec[pq.top().node].size();
        int here=pq.top().node;
        int cost=pq.top().sum;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<l; i++){
            if(dist[vec[here][i].node] < cost + vec[here][i].cost) continue;
            if(dist[vec[here][i].node] > cost + vec[here][i].cost){
                //printf("%d %d %d %d %d\n", here, vec[here][i].node, dist[vec[here][i].node], cost, cost + vec[here][i].cost);
                dist[vec[here][i].node]=cost+vec[here][i].cost;
                pq.push({vec[here][i].node, cost+vec[here][i].cost});
            }
        }

    }


}



int main(){
    scanf("%d", &v);
    scanf("%d", &e);
    for(int i=0; i<e; i++){
        int tmp1, tmp2, tmp3;
        scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
        vec[tmp1].push_back({tmp2, tmp3});
        vec[tmp2].push_back({tmp1, tmp3});
    }

    int start, end;
    scanf("%d %d", &start, &end);

    dijkstra(1);
    int rute1=dist[start];
    int rute2=dist[end];

    dijkstra(start);
    int rute3=dist[end];

    dijkstra(v);
    int rute4=dist[start];
    int rute5=dist[end];

    //printf("%d %d %d %d %d\n", rute1, rute2, rute3, rute4, rute5);
    long ans=min(rute1+rute3+rute5, rute2+rute3+rute4);
    if(ans==2100000000*3)printf("-1");
    else printf("%d", ans);



    return 0;
}
