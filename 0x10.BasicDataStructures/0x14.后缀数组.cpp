#include <bits/stdc++.h>
using namespace std;

using ull = uint64_t;

constexpr int P = 131;

constexpr int maxn = 3e5;

ull f[maxn + 1], p[maxn + 1];

int suffix[maxn], h[maxn];

bool check(int a, int b, int len) {
    return f[a + len] - f[a] * p[len] == f[b + len] - f[b] * p[len];
}

int get(int a, int b, int n) {
    int lo = 0, hi = min(n - a, n - b);
    while (lo < hi) {
        int mid = lo + hi + 1 >> 1;
        if (check(a, b, mid)) lo = mid;
        else                  hi = mid - 1;
    }
    return lo;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int n = size(s);
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] * P + s[i - 1] - 'a' + 1;
        p[i] = p[i - 1] * P;
    }
    iota(suffix, suffix + n, 0);
    sort(suffix, suffix + n, [&](const auto &a, const auto &b) {
        int len = get(a, b, n);
        if (len == min(n - a, n - b)) return a > b;
        return s[a + len] < s[b + len];
    });
    for (int i = 1; i < n; ++i)
        h[i] = get(suffix[i - 1], suffix[i], n);
    for (int i = 0; i < n; ++i)
        cout << suffix[i] << (i + 1 < n ? ' ' : '\n');
    for (int i = 0; i < n; ++i)
        cout << h[i] << (i + 1 < n ? ' ' : '\n');
    return 0;
}