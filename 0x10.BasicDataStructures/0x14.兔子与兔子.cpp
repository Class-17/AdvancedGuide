#include <bits/stdc++.h>
using namespace std;

using ull = uint64_t;

constexpr int P = 131;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    int n = size(s), m;
    cin >> m;
    vector<ull> f(n + 1), p(n + 1);
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        f[i] = f[i - 1] * P + s[i - 1] - 'a' + 1;
        p[i] = p[i - 1] * P;
    }
    for (int i = 0; i < m; ++i) {
        int la, ra, lb, rb;
        cin >> la >> ra >> lb >> rb;
        ull a = f[ra] - f[la - 1] * p[ra - la + 1];
        ull b = f[rb] - f[lb - 1] * p[rb - lb + 1];
        cout << (a == b ? "Yes" : "No") << '\n';
    }
    return 0;
}