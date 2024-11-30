#include <bits/stdc++.h>

using i64 = long long;

template<class T>
class FenwickTree {
public: // fenwickTree for interval [0, n)
    int n;
    std::vector<T> data;

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

    T sum(int r) {// return sum of [0, r)
        assert(0 <= r and r <= n);
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }

    T sum(int l, int r) {// return sum of [l, r)
        assert(0 <= l and l <= r and r <= n);
        return sum(r) - sum(l);
    }
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    FenwickTree<i64> fw(n + 2);
    for (int i = 0; i < m; ++i) {
        std::string op;
        std::cin >> op;
        if (op == "1") {
            int l, r, d;
            std::cin >> l >> r >> d;
            fw.add(l, +d);
            fw.add(r + 1, -d);
        }
        else {
            int x;
            std::cin >> x;
            std::cout << a[x] + fw.sum(x + 1) << '\n';
        }
    }
    return 0;
}