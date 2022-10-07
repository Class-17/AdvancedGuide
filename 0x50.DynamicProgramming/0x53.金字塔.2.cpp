#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int n = size(s);
    vector dp(n + 1, vector(n + 1, -1));
    auto dfs = [&](auto &f, int l, int r)->long long {
        if (l + 1 >= r) return l + 1 == r;
        if (s[l] != s[r - 1]) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        dp[l][r] = 0;
        for (int k = l + 2; k < r; ++k)
            dp[l][r] = (dp[l][r] + f(f, l + 1, k) * f(f, k, r)) % mod;
        return dp[l][r];
    };
    cout << dfs(dfs, 0, n) << '\n';
    return 0;
}