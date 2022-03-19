#include <algorithm>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

int indegree[1002];
int ch[1002][1002];
int chr[1002];

int main() {
  int n, m;

  scanf("%d %d", &n, &m);

  vector<int> adj[1002];
  vector<int> res;
  queue<int> q;

  for (int i = 0; i < m; i++) {
    int k;
    scanf("%d", &k);
    int pos;
    scanf("%d", &pos);
    // printf("k : %d\n", k);
    for (int i = 1; i < k; i++) {

      int tmp;
      scanf("%d", &tmp);
      if (ch[pos][tmp] == 0) {
        adj[pos].push_back(tmp);
        indegree[tmp]++;
        ch[pos][tmp] = 1;
      }
      pos = tmp;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }
  int i;
  for (i = 0; i <= n; i++) {
    if (q.empty())
      break;
    int p = q.front();
    if (chr[p] == 1)
      break;
    res.push_back(p);
    chr[p] = 1;
    // printf("%d\n", p);
    q.pop();
    int k = adj[p].size();
    // printf("%d %d = size\n", k, adj[p][0]);
    for (int j = 0; j < k; j++) {
      indegree[adj[p][j]]--;
      if (!indegree[adj[p][j]]) {
        q.push(adj[p][j]);
      }
    }
  }
  if (i == n) {
    for (i = 0; i < n; i++) {
      printf("%d\n", res[i]);
    }
  } else
    printf("0");

  return 0;
}
