#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll count(vector<int> &a) {
    int n = size(a);
    ll sum = accumulate(begin(a), end(a), 0LL);
    if (sum % n) return -1;
    for (auto &x : a) 
        x = sum / n - x;
    partial_sum(begin(a), end(a), begin(a));
    sort(begin(a), end(a));
    int med = a[n / 2];
    ll cnt = 0;
    for (auto &x : a)
        cnt += abs(med - x);
    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> row(n), col(m);
    for (int i = 0; i < t; ++i) {
        int x, y; cin >> x >> y;
        ++row[x - 1], ++col[y - 1];
    }
    ll rr = count(row);
    ll cc = count(col);
    if (rr >= 0 && cc >= 0)
        cout << "both " << rr + cc << '\n';
    else if (rr >= 0)
        cout << "row " << rr << '\n';
    else if (cc >= 0)
        cout << "column " << cc << '\n';
    else
        cout << "impossible" << '\n';
    return 0;
}