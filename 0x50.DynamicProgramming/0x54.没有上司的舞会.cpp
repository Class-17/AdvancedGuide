#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<vector<int>> g(n);
    vector<int> outD(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[v - 1].push_back(u - 1);
        ++outD[u - 1];
    }
    vector<int> dp(n, - 1);
    auto dfs = [&](auto &f, int idx)->int {
        dp[idx] = arr[idx];
        int sub = 0;
        for (auto &x : g[idx]) {
            int curr = f(f, x);
            sub += max(curr, dp[x]);
            dp[idx] += curr;
        }
        return sub;
    };
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (outD[i]) continue;
        int curr = dfs(dfs, i);
        res += max(curr, dp[i]);
    }
    cout << res << '\n';
    return 0;
}