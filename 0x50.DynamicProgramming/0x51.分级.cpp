#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, vector<int> &seq) {
    int len = size(seq);
    vector<int> dp(len);
    for (auto &x : arr) {
        int diff = INT_MAX;
        for (int i = 0; i < len; ++i) {
            diff = min(diff, dp[i]);
            dp[i] = abs(seq[i] - x) + diff;
        }
    }
    return *min_element(begin(dp), end(dp));
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    auto seq = arr;
    sort(begin(seq), end(seq));
    seq.erase(unique(begin(seq), end(seq)), end(seq));
    int res = solve(arr, seq);
    reverse(begin(arr), end(arr));
    res = min(res, solve(arr, seq));
    cout << res << '\n';
    return 0;
} 