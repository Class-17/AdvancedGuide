#include <bits/stdc++.h>
using namespace std;

using ull = uint64_t;

constexpr int P = 131;

vector<ull> get_f(const string &s, int len, ull p) {
    int n = size(s);
    vector<ull> f(n + 1);
    for (int i = 1; i <= n; ++i)
        f[i] = f[i - 1] * P + s[i - 1] - '0' + 1;
    vector<ull> vals(n - len + 1);
    for (int i = 0; i + len <= n; ++i)
        vals[i] = f[i + len] - f[i] * p;
    return vals;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<string> mat(n);
    for (auto &s : mat) cin >> s;
    vector<ull> p(m + 1);
    p[0] = 1;
    for (int i = 1; i <= m; ++i)
        p[i] = p[i - 1] * P;
    vector<vector<ull>> f;
    for (auto &s : mat)
        f.push_back(get_f(s, b, p[b]));
    set<ull> st;
    for (int r = 0; r + a <= n; ++r)
        for (int c = 0; c + b <= m; ++c) {
            ull val = 0;
            for (int i = r; i < r + a; ++i)
                val = val * p[m] + f[i][c];
            st.insert(val);
        }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        ull val = 0;
        for (int j = 0; j < a; ++j) {
            string s; cin >> s;
            ull curr = 0;
            for (auto &ch : s)
                curr = curr * P + ch - '0' + 1;
            val = val * p[m] + curr;
        }
        cout << st.count(val) << '\n';
    }
    return 0;
}