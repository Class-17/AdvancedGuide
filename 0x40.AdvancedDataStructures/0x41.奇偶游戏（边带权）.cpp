#include <bits/stdc++.h>

class UnionFind {
public:
    int n;
    std::vector<int> fa, d;
public:
    UnionFind(int n = 0) : n(n), fa(n, -1), d(n) {}

    int find(int x) {
        if (fa[x] < 0) return x;
        int root = find(fa[x]);
        d[x] ^= d[fa[x]];
        return fa[x] = root;
    }

    void unite(int x, int y, int w) {
        int faX = find(x), faY = find(y);
        if (faX == faY) return;
        fa[faY] = faX;
        d[faY] = d[x] ^ d[y] ^ w;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int get(int x) {
        return d[x];
    }
};

int compress(auto &input) {
    std::vector<int> a;
    for (auto &[l, r, op] : input)
        for (int i = -1; i <= 1; ++i) {
            a.push_back(l + i);
            a.push_back(r + i);
        }
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    for (auto &[l, r, op] : input) {
        l = std::lower_bound(a.begin(), a.end(), l) - a.begin();
        r = std::lower_bound(a.begin(), a.end(), r) - a.begin();
    }
    return a.size();
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::tuple<int, int, int>> input(m);
    for (auto &[l, r, op] : input) {
        std::string s;
        std::cin >> l >> r >> s;
        op = (s == "odd");
    }
    n = compress(input);
    UnionFind dsu(n);
    for (int i = 0; auto &[l, r, op] : input) {
		if (dsu.same(l - 1, r)) {
            if ((dsu.get(l - 1) ^ dsu.get(r)) != op) {
                std::cout << i << '\n';
                return 0;
            }
        }
        else {
            dsu.unite(l - 1, r, op);
        }
        i += 1;
    }
    std::cout << m << '\n';
    return 0;
}