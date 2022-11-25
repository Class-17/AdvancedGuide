#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int inf = INT_MAX;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        vector<vector<pair<int, ll>>> g(n + 1);
        vector<int> de(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
            ++de[u];
            ++de[v];
        }
        vector<ll> dp(n + 1);
        auto dfs = [&](auto &f, int p, int u)->void {
            for (auto &[v, w] : g[u]) {
                if (v == p) continue;
                f(f, u, v);
                if (de[v] == 1)   dp[u] += w;
                else dp[u] += min(dp[v], w);
            }
        };
        dfs(dfs, 0, 1);
        queue<pair<int, int>> q;
        q.emplace(0, 1);
        while (!q.empty()) {
            auto [p, u] = q.front(); q.pop();
            for (auto &[v, w] : g[u]) {
                if (v == p) continue;
                if (de[u] == 1)
                    dp[v] += w;
                else if (de[v] == 1)
                    dp[v] += min(dp[u] - w, w);
                else
                    dp[v] += min(dp[u] - min(dp[v], w), w);
                q.emplace(u, v);
            }
        }
        cout << *max_element(begin(dp), end(dp)) << '\n';
    }
    return 0;
}