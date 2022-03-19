#include <map>
#include <stdio.h>
#include <vector>

using namespace std;
map<long, long> mp;
int arr[42];
int n;
int s;
long ans;

void le(int d, long sum) {
  if (d == n / 2) {
    mp[sum]++;

    return;
  }
  le(d + 1, sum + arr[d]);
  le(d + 1, sum);
  return;
}

void ri(int d, long sum) {
  if (d == n) {
    ans += mp[s - sum];
    return;
  }
  ri(d + 1, sum);
  ri(d + 1, sum + arr[d]);
  return;
}

int main() {

  scanf("%d %d", &n, &s);

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  le(0, 0);
  ri(n / 2, 0);

  if (s)
    printf("%ld", ans);
  else
    printf("%ld", ans - 1);

  return 0;
}
