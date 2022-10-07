#include <bits/stdc++.h>
using namespace std;

int n, len, cnt, num;

vector<int> arr, st;

bool dfs(int idx, int cab, int pre) {
    if (idx == num) return true;
    if (cab == len) return dfs(idx + 1, 0, 0);
    int fail = 0;
    for (int i = pre; i < n; ++i) {
        if (st[i] or cab + arr[i] > len or fail == arr[i]) continue;
        st[i] = 1;
        if (dfs(idx, cab + arr[i], pre)) return true;
        st[i] = 0;
        fail = arr[i];
        if (cab == 0 or cab + arr[i] == len) return false;
    }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    while (cin >> n and n) {
        arr = st = vector<int>(n);
        for (auto &x : arr) cin >> x;
        sort(rbegin(arr), rend(arr));
        int tot = accumulate(begin(arr), end(arr), 0);
        for (len = arr[0]; len <= tot; ++len) {
            if (tot % len) continue;
            num = tot / len;
            if (dfs(0, 0, 0)) break;
        }
        cout << len << '\n';
    }
    return 0;
}