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
    UnionFind dsu(n * 2);
    for (int i = 0; auto &[l, r, op] : input) {
        int l_odd = l - 1, l_even = l - 1 + n;
        int r_odd = r, r_even = r + n;
		if (op == 0) {
            if (dsu.same(l_odd, r_even)) {
                std::cout << i << '\n';
                return 0;
            }
            dsu.unite(l_odd, r_odd);
            dsu.unite(l_even, r_even);
        }
        else {
            if (dsu.same(l_odd, r_odd)) {
                std::cout << i << '\n';
                return 0;
            }
            dsu.unite(l_odd, r_even);
            dsu.unite(l_even, r_odd);
        }
        i += 1;
    }
    std::cout << m << '\n';
    return 0;
}