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

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n; std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 1; i < n; ++i)
        std::cin >> a[i];
    FenwickTree<int> fw(n);
    for (int i = n - 1; i >= 0; --i) {
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = lo + hi + 1 >> 1;
            if (mid - fw.sum(0, mid) <= a[i])
                lo = mid;
            else
                hi = mid - 1;
        }
        a[i] = lo;
        fw.add(a[i], 1);
    }
    for (auto &x : a)
        std::cout << x + 1 << '\n';
    return 0;
}