#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 5e5 + 1;

constexpr int inf = 0x3f3f3f3f;

int arr[maxn];

struct SegmentTree {
    int l, r;
    int sum, lmax, rmax, val;

    SegmentTree() : sum(0), lmax(-inf), rmax(-inf), val(-inf) {}

    void assign(int x) {
        sum = lmax = rmax = val = x;
    }

} t[maxn << 2];

void update(int p) {
    t[p].sum = t[p << 1].sum + t[p<<1|1].sum;
    t[p].lmax = max(t[p << 1].lmax, t[p << 1].sum + t[p<<1|1].lmax);
    t[p].rmax = max(t[p<<1|1].rmax, t[p<<1|1].sum + t[p << 1].rmax);
    t[p].val = max({t[p << 1].val, t[p<<1|1].val, t[p << 1].rmax + t[p<<1|1].lmax});
}

void build(int p, int l, int r) {
    tie(t[p].l, t[p].r) = pair{l, r};
    if (l == r) {t[p].assign(arr[l]); return;}
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p<<1|1, mid + 1, r);
    update(p);
}

void change(int p, int x, int val) {
    if (t[p].l == t[p].r) {t[p].assign(val); return;}
    int mid = t[p].l + t[p].r >> 1;
    if (x <= mid) change(p << 1, x, val);
    else          change(p<<1|1, x, val);
    update(p);
}

SegmentTree query(int p, int l, int r) {
    if (r < t[p].l or t[p].r < l) return SegmentTree();
    if (l <= t[p].l and t[p].r <= r) return t[p];
    int mid = t[p].l + t[p].r >> 1;
    SegmentTree a, b, curr;
    if (l <= mid) a = query(p << 1, l, r);
    if (r > mid) b = query(p<<1|1, l, r);
    curr.sum = a.sum + b.sum;
    curr.lmax = max(a.lmax, a.sum + b.lmax);
    curr.rmax = max(b.rmax, b.sum + a.rmax);
    curr.val = max({a.val, b.val, a.rmax + b.lmax});
    return curr;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    build(1, 1, n);
    for (int i = 0; i < m; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            if (x > y) swap(x, y);
            cout << query(1, x, y).val << '\n';
        }
        else {
            change(1, x, y);
        }
    }    
    return 0;
}