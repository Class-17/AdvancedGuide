#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m and n) {
        vector<int> a(n), c(n);
        for (auto &x : a) cin >> x;
        for (auto &x : c) cin >> x;
        vector<int> dp(m + 1);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            vector<int> cnt(m + 1);
            for (int j = a[i]; j <= m; ++j)
                if (!dp[j] and dp[j - a[i]] and cnt[j - a[i]] < c[i])
                    tie(dp[j], cnt[j]) = pair{1, cnt[j - a[i]] + 1};
        }
        cout << accumulate(begin(dp) + 1, end(dp), 0) << '\n';
    }
    return 0;
}