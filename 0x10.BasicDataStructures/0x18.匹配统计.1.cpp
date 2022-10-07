#include <bits/stdc++.h>
using namespace std;

using ull = uint64_t;

constexpr int P = 131;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    string a, b;
    cin >> a >> b;
    vector<ull> fa(n + 1), fb(m + 1), p(max(n, m) + 1);
    p[0] = 1;
    for (int i = 1; i < size(p); ++i)
        p[i] = p[i - 1] * P;
    for (int i = 1; i <= n; ++i)
        fa[i] = fa[i - 1] * P + a[i - 1] - 'a' + 1;
    for (int i = 1; i <= m; ++i)
        fb[i] = fb[i - 1] * P + b[i - 1] - 'a' + 1;
    map<int, int> st;
    auto check = [&](int idx, int len) {
        return fa[idx + len] - fa[idx] * p[len] == fb[len];
    };
    for (int i = 0; i < n; ++i) {
        int lo = 0, hi = min(n - i, m);
        while (lo < hi) {
            int mid = lo + hi + 1 >> 1;
            if (check(i, mid)) lo = mid;
            else               hi = mid - 1;
        }
        ++st[lo];
    }
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        cout << st[x] << '\n';
    }
    return 0;
}