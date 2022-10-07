#include <bits/stdc++.h>
using namespace std;

constexpr int n = 12;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<int> f(n + 1, INT_MAX), d(n + 1);
    d[1] = 1;
    for (int i = 2; i <= n; ++i)
        d[i] = 2 * d[i - 1] + 1;
    f[1] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j < i; ++j)
            f[i] = min(f[i], 2 * f[j] + d[i - j]);
    for (int i = 1; i <= n; ++i)
        cout << f[i] << '\n';
    return 0;
}