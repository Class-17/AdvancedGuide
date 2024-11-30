#include <bits/stdc++.h>

class UnionFind {
private:
    int n;
    std::vector<int> dsu;
public:
    UnionFind(int n = 0) : n(n), dsu(n, -1) {}

    int find(int x) {
        if (dsu[x] < 0) return x;
        return dsu[x] = find(dsu[x]);
    }

    int unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return x;
        if (dsu[x] > dsu[y]) std::swap(x, y);
        dsu[x] += dsu[y];
        dsu[y] = x;
        return x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return -dsu[find(x)];
    }
};

int compress(std::vector<std::tuple<int, int, int>> &input) {
    std::vector<int> a;
    for (auto &[x, y, z] : input) {
        a.push_back(x);
        a.push_back(y);
    }
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    for (auto &[x, y, z] : input) {
        x = std::lower_bound(a.begin(), a.end(), x) - a.begin();
        y = std::lower_bound(a.begin(), a.end(), y) - a.begin();
    }
    return a.size();
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int _; std::cin >> _;
    while (_--) {
        int n; std::cin >> n;
        std::vector<std::tuple<int, int, int>> input(n);
        for (auto &[x, y, z] : input)
            std::cin >> x >> y >> z;
        int m = compress(input);
        UnionFind dsu(m);
        for (auto &[x, y, z] : input)
            if (z == 1) dsu.unite(x, y);
        bool valid = true;
        for (auto &[x, y, z] : input)
            if (z == 0 and dsu.same(x, y))
                valid = false;
        std::cout << (valid ? "YES" : "NO") << '\n';
    }
    return 0;
}