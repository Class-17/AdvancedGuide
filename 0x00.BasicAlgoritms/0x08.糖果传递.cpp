#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> arr(n);
    for (auto &x : arr) cin >> x;
    int avg = accumulate(begin(arr), end(arr), 0LL) / n;
    for (auto &x : arr) x -= avg;
    partial_sum(begin(arr), end(arr), begin(arr));
    sort(begin(arr), end(arr));
    ll med = arr[n / 2], cnt = 0;
    for (auto &x : arr)
       cnt += abs(x - med);
    cout << cnt << '\n';
    return 0;
}