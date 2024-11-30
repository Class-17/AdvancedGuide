#include <bits/stdc++.h>

constexpr int INF = 1e9;

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

    T prod(int l, int r) const {
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

struct Node {
    int sum, lmax, rmax, vmax;
    
    Node() {}
    Node(int x) {sum = lmax = rmax = vmax = x;}
    Node(int sum, int lmax, int rmax, int vmax) :
        sum(sum), lmax(lmax), rmax(rmax), vmax(vmax) {}

    Node e() {return Node(-INF);}   
};

Node op(Node a, Node b) {
    return Node(a.sum + b.sum,
        std::max(a.lmax, a.sum + b.lmax),
        std::max(b.rmax, a.rmax + b.sum),
        std::max({a.vmax, b.vmax, a.rmax + b.lmax}));
}

Node e() {return Node(-INF);}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<Node> a(n);
    for (auto &x : a)  {
        int v; std::cin >> v;
        x = Node(v);
    }
    Segtree<Node, op, e> sgt(a);
    for (int i = 0; i < m; ++i) {
        int k, x, y;
        std::cin >> k >> x >> y;
        if (k == 1 and x > y) std::swap(x, y);
        if (k == 1)
            std::cout << sgt.prod(x - 1, y).vmax << '\n';
        else
            sgt.set(x - 1, Node(y));
    }
    return 0;
}