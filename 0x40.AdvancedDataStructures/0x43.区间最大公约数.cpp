#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int maxn = 5e5 + 1;

ll arr[maxn], diff[maxn];

template<class T>
class FenwickTree {
private:
    int n;
    vector<T> sum;
    int lowbit(int x) {return x & -x;}
public:
    FenwickTree(int n) : n(n), sum(n + 1) {}
 
    void add(int x, T d) {
        for (; x <= n; x += lowbit(x))
            sum[x] += d;
    }

    T ask(int x) {
        T res = 0;
        for (; x; x -= lowbit(x))
            res += sum[x];
        return res;
    }
};

struct SegmentTree {
    int l, r;
    ll val;
} t[maxn << 2];

void update(int p) {
    t[p].val = gcd(t[p << 1].val, t[p<<1|1].val);
}

void build(int p, int l, int r) {
    tie(t[p].l, t[p].r) = pair{l, r};
    if (l == r) {t[p].val = diff[l]; return;}
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p<<1|1, mid + 1, r);
    update(p);
}

void add(int p, int x, ll delta) {
    if (t[p].l == t[p].r) {t[p].val += delta; return;}
    int mid = t[p].l + t[p].r >> 1;
    if (x <= mid) add(p << 1, x, delta);
    else          add(p<<1|1, x, delta);
    update(p);
}

ll ask(int p, int l, int r) {
    if (r < t[p].l or t[p].r < l) return 0;
    if (l <= t[p].l and t[p].r <= r) return t[p].val;
    return gcd(ask(p << 1, l, r), ask(p<<1|1, l, r));
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        diff[i] = arr[i] - arr[i - 1];
    }
    build(1, 1, n);
    FenwickTree<ll> bit(n);
    for (int i = 0; i < m; ++i) {
        char q; cin >> q;
        int l, r; cin >> l >> r;
        if (q == 'C') {
            ll d; cin >> d;
            add(1, l, d);
            bit.add(l, d);
            if (r >= n) continue;
            add(1, r + 1, -d);
            bit.add(r + 1, -d);
        }
        else {
            ll a = arr[l] + bit.ask(l);
            ll b = ask(1, l + 1, r);
            cout << gcd(a, b) << '\n';
        }
    }
    return 0;
}