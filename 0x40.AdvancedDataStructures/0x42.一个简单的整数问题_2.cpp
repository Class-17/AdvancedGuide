#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;

vector<ll> arr;

vector<ll> s, is;

int lowbit(int x) {return x & -x;}

void add(vector<ll> &sum, int idx, int val) {
    for (; idx <= n; idx += lowbit(idx))
        sum[idx] += val;
}

ll ask(vector<ll> &sum, int idx) {
    ll res = 0;
    for (; idx > 0; idx -= lowbit(idx))
        res += sum[idx];
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    arr = vector<ll>(n + 1);
    s = is = vector<ll>(n + 2);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    partial_sum(begin(arr), end(arr), begin(arr));
    for (int i = 0; i < m; ++i) {
        string q; cin >> q;
        if (q == "Q") {
            int l, r;
            cin >> l >> r;
            ll res = arr[r] - arr[l - 1];
            res += (r + 1) * ask(s, r) - ask(is, r);
            res -= l * ask(s, l - 1) - ask(is, l - 1);
            cout << res << '\n';
        }
        else {
            int l, r, d;
            cin >> l >> r >> d;
            add(s, l, d);
            add(s, r + 1, -d);
            add(is, l, l * d);
            add(is, r + 1, -(r + 1) * d);
        }
    }
    return 0;
}