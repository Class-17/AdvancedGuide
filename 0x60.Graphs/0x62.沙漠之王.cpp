#include <bits/stdc++.h>
using namespace std;

constexpr double LIM = 1e-6;

class UnionFind {
private:
    int n;
    vector<int> dsu;
public:
    UnionFind(int n = 0) : n(n), dsu(n, -1) {}

    int find(int x) {
        return dsu[x] >= 0 ? dsu[x] = find(dsu[x]) : x;
    }

    int size(int x) {
        return -dsu[x = find(x)];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (dsu[x] > dsu[y]) swap(x, y);
        dsu[x] += dsu[y];
        dsu[y] = x;
        return true;
    }
};

double dist(int x1, int y1, int x2, int y2) {
    return pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    while (cin >> n and n) {
        vector<tuple<int, int, int>> arr(n);
        for (auto &[x, y, z] : arr)
            cin >> x >> y >> z;
        vector<tuple<int, int, double, double>> es;
        for (int i = 0; i < n; ++i) {
            auto &[x1, y1, z1] = arr[i];
            for (int j = i + 1; j < n; ++j) {
                auto &[x2, y2, z2] = arr[j];
                es.emplace_back(i, j, abs(z1 - z2), dist(x1, y1, x2, y2));
            }
        }
        auto check = [&](double c) {
            sort(begin(es), end(es), [&](const auto &a, const auto &b) {
                auto &[u1, v1, x1, y1] = a;
                auto &[u2, v2, x2, y2] = b;
                return x1 - y1 * c < x2 - y2 * c;
            });
            UnionFind dsu(n);
            double res = 0;
            for (auto &[u, v, x, y] : es)
                if (dsu.unite(u, v))
                    res += x - y * c;
            return res <= 0;
        };
        double lo = 0, hi = 10;
        while ((hi - lo) > LIM) {
            double mid = (lo + hi) / 2;
            if (check(mid) == false)
                lo = mid;
            else
                hi = mid; 
        }
        cout << setprecision(3) << fixed << lo << '\n';
    }
    return 0;
}