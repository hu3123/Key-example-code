#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<list>
#include<vector>
#include<string.h>
#include<math.h>


using namespace std;
int n, m;

int getParent(vector<int>& parent, int x) {
    if (parent[x] == x) {
        return x;
    }
    else {
        return parent[x] = getParent(parent, parent[x]);
    }
}

void unionParent(vector<int>& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b)parent[b] = a;
    else parent[a] = b;

}

int findParent(vector<int>& parent, int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (b == a) return 1;
    else return 0;
}


int main() {

    scanf("%d %d", &n, &m);
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int tmp;
        int a, b;
        scanf("%d %d %d", &tmp, &a, &b);
        if (tmp == 0) {
            unionParent(parent, a, b);
        }
        else {
            if (findParent(parent, a, b)) {
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }

    }




    return 0;
}
