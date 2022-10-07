#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 200;

constexpr int maxm = 20;

constexpr int zero = maxm * maxm;

int dp[maxm + 1][zero * 2 + 1];

int path[maxn * 10 + 1][maxm + 1][zero * 2 + 1];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, _ = 1;
    while (cin >> n >> m and n) {
        vector<int> p(n + 1), d(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> p[i] >> d[i];
        memset(dp, 0xcf, sizeof dp);
        dp[0][zero] = 0;
        for (int i = 1; i <= n; ++i) {
            memcpy(path[i], path[i - 1], sizeof path[i]);
            for (int j = m; j > 0; --j) {
                int diff = p[i] - d[i], sum = p[i] + d[i];
                for (int k = 0; k <= zero * 2; ++k) {
                    if (k - diff < 0 or k - diff > zero * 2) continue;
                    if (dp[j - 1][k - diff] + sum <= dp[j][k]) continue;
                    dp[j][k] = dp[j - 1][k - diff] + sum;
                    path[i][j][k] = i;
                }
            }
        }
        int ans = 0;
        for (int i = zero; i >= 0; --i)
            if (dp[m][zero + i] >= max(0, dp[m][zero - i]))
                ans = zero + i;
            else if (dp[m][zero - i] >= 0)
                ans = zero - i;
        vector<int> seq;
        int a = 0, b = 0;
        auto print_path = [&](auto &f, int i, int j, int k) {
            if (i <= 0 or j == 0) return;
            int last = path[i][j][k];
            f(f, last - 1, j - 1, k - (p[last] - d[last]));
            seq.push_back(last);
            a += p[last], b += d[last];
        };
        print_path(print_path, n, m, ans);
        cout << "Jury #" << _++ << '\n';
        cout << "Best jury has value " << a;
        cout << " for prosecution and value " << b << " for defence:\n";
        for (auto &x : seq)
            cout << ' ' << x;
        cout << "\n\n";
    }
    return 0;
}