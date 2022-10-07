#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n), id(n);
    for (auto &x : arr) cin >> x;
    iota(begin(id), end(id), 0);
    sort(begin(id), end(id), [&](const auto &a, const auto &b) {
        return arr[a] != arr[b] ? arr[a] < arr[b] : a < b;});
    int cnt = 1, up = 0, pre = n;
    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        while (j < n and arr[id[j]] == arr[id[i]]) ++j;
        int lo = id[i], hi = id[j - 1];
        if (up) {
            if (pre < lo)       pre = hi;
            else ++cnt, up = 0, pre = lo;
        }
        else {
            if (pre > hi) pre = lo;
            else  up = 1, pre = hi;
        }
        i = j - 1;
    }
    cout << cnt << '\n';
    return 0;
}