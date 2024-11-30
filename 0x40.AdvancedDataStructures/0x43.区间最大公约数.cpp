#include <bits/stdc++.h>

template<class T>
class FenwickTree {
private: // fenwickTree for interval [0, n)
    int n;
    std::vector<T> data;

    T sum(int r) {// return sum of [0, r)
        assert(0 <= r and r <= n);
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
public:
    FenwickTree(int n = 0) : n(n), data(n) {}
    
    void add(int p, T x) {
        assert(0 <= p and p < n);
        p += 1;
        while (p <= n) {
            data[p - 1] += x;
            p += p & -p;
        }
    }

    T sum(int l, int r) {// return sum of [l, r)
        assert(0 <= l and l <= r and r <= n);
        return sum(r) - sum(l);
    }
};

template<class T, T (*op)(T, T), T (*e)()>
class Segtree {
private:
    int n, size, log;
    std::vector<T> d;
    void update(int k) {d[k] = op(d[k * 2], d[k * 2 + 1]);}
public:
    Segtree() : Segtree(0) {}
    Segtree(int n) : Segtree(std::vector<T>(n, e())) {}
    Segtree(const std::vector<T> &v) : n(v.size()) {
        size = 1;
        while (size < n) size *= 2;
        log = __builtin_ctz(size);
        d = std::vector<T>(size * 2, e());
        for (int i = 0; i < n; ++i) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; --i)
            update(i);
    }

    void set(int p, T x) {
        assert(0 <= p and p < n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; ++i) update(p >> i);
    }

    T get(int p) const {
        assert(0 <= p and p < n);
        return d[p + size];
    }

    T prod(int l, int r) const { // [l, r)
        assert(0 <= l and l <= r and r <= n);
        T sml = e(), smr = e();
        l += size;
        r += size;
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    T all_prod() const {return d[1];}
};

using i64 = long long;

i64 e() {return i64();}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n);
    for (auto &x : a) std::cin >> x;
    FenwickTree<i64> ft(n + 1);
    Segtree<i64, std::gcd, e> sgt(n + 1);
    for (int i = 1; i < n; ++i)
        sgt.set(i, a[i] - a[i - 1]);
    for (int i = 0; i < m; ++i) {
        std::string op; std::cin >> op;
        if (op == "C") {
            i64 l, r, d;
            std::cin >> l >> r >> d;
            --l, --r;
            ft.add(l, d);
            ft.add(r + 1, -d);
            sgt.set(l, sgt.get(l) + d);
            sgt.set(r + 1, sgt.get(r + 1) - d);
        }
        else {
            int l, r;
            std::cin >> l >> r;
            --l, --r;
            std::cout << std::gcd(a[l] + ft.sum(0, l + 1), sgt.prod(l + 1, r + 1)) << '\n';
        }
    }
    return 0;
}