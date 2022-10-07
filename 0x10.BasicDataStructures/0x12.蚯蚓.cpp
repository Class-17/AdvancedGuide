#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q, u, v, t;
    cin >> n >> m >> q >> u >> v >> t;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    sort(rbegin(arr), rend(arr));
    queue<int> a, b, c;
    for (int i = 0; i < n; ++i)
        a.push(arr[i]);
    auto get_max = [&]() {
        auto f = [](queue<int> &q) {
            return q.empty() ? INT_MIN : q.front();
        };
        int max_val = max({f(a), f(b), f(c)});
        if (max_val == f(a))      a.pop();
        else if (max_val == f(b)) b.pop();
        else                      c.pop();
        return max_val;
    };
    for (int i = 0; i < m; ++i) {
        int x = get_max();
        x += i * q;
        if ((i + 1) % t == 0)
            cout << x << (i + t < m ? ' ' : '\n');
        int l = x * 1LL * u / v, r = x - l;
        if (l > r) swap(l, r);
        b.push(l - (i + 1) * q);
        c.push(r - (i + 1) * q);
    }
    if (m / t == 0) cout << '\n';
    for (int i = 0; i < n + m; ++i) {
        int x = get_max();
        if ((i + 1) % t == 0)
            cout << x + m * q << (i + t < n + m ? ' ' : '\n');
    }
    return 0;
}