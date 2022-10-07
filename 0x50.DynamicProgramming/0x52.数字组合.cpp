#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = m; j >= arr[i]; --j)
            dp[j] += dp[j - arr[i]];
    cout << dp[m] << '\n';
    return 0;
}