#include<stdio.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdlib.h>

using namespace std;

vector<int> ans;
int *res = (int*)malloc(sizeof(int)*1000000);
int i;

void binary_search(int tar) {
    int lo;
    vector<int>::iterator itr = lower_bound(ans.begin(), ans.end(), tar);
    int pos = itr - ans.begin();
    //printf("%d\n", pos);
    if (pos == ans.size()) {
        ans.push_back(tar);
        res[i] = ans.size();
    }
    else {
        ans[pos] = tar;
        res[i] = pos + 1;
    }
    return;
}



int main() {
    int n;

    scanf("%d", &n);

    vector<int> arr(n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (ans.size()) {
            binary_search(arr[i]);
        }
        else {
            ans.push_back(arr[i]);
            res[i] = 1;
        }
    }

    printf("%ld\n", ans.size());

    int k = ans.size();

    vector<int> result(k);

    int m = k;

    for (int i = n - 1; i >= 0 || k > 0; i--) {
        if (res[i] == k) {
            k--;
            result[k] = arr[i];
        }
    }



    for (int i = 0; i < m; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}
