#include <bits/stdc++.h>

using i64 = long long;

template<class T>
class FenwickTree {
private: // fenwickTree for interval [0, n)
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
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (auto &x : a) std::cin >> x;
    FenwickTree<int> fw(n + 1);
    std::vector<i64> lcnt(n), rcnt(n);
    for (int i = 0; i < n; ++i) {
        lcnt[i] = fw.sum(a[i]);
        fw.add(a[i], 1);
    }
    fw = FenwickTree<int>(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        rcnt[i] = fw.sum(a[i]);
        fw.add(a[i], 1);
    }
    i64 cntA = 0, cntB = 0;
    for (int i = 0; i < n; ++i) {
        cntA += (i - lcnt[i]) * (n - i - 1 - rcnt[i]);
        cntB += lcnt[i] * rcnt[i];
    }
    std::cout << cntA << ' ' << cntB << '\n';
    return 0;
}