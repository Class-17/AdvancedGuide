#include <bits/stdc++.h>

template<class T>
class SquareRoot {
private:
    int n, len, cnt;
    std::vector<T> v;
    std::vector<std::vector<int>> idx;
    std::vector<std::vector<T>> block;
    std::vector<int> d;
    std::vector<int> id;
    std::vector<std::vector<int>> rid;
public:
    SquareRoot() : SquareRoot(0) {}
    explicit SquareRoot(int n) : SquareRoot(std::vector<int>(n)) {}
    explicit SquareRoot(const std::vector<T> &a) : n(a.size()), v(a), d(a) {
        len = n / std::sqrt(n * std::log2(n));
        cnt = (n + len - 1) / len;
        block = std::vector(cnt, std::vector<T>(cnt));
        id = std::vector<int>(n);
        rid = std::vector<std::vector<int>>(cnt);
        for (int i = 0; i < n; ++i) {
            id[i] = i / len;
            rid[id[i]].push_back(i);
        }
        std::sort(d.begin(), d.end());
        d.erase(std::unique(d.begin(), d.end()), d.end());
        for (auto &x : v)
            x = std::lower_bound(d.begin(), d.end(), x) - d.begin();
        idx = std::vector<std::vector<int>>(d.size());
        for (int i = 0; i < n; ++i)
            idx[v[i]].push_back(i);
        for (int i = 0; i < cnt; ++i) {
            std::vector<int> cnt(d.size());
            int mode = 0, modec = 0;
            for (int j = rid[i][0]; j < n; ++j) {
                update(modec, mode, ++cnt[v[j]], v[j]);
                block[i][id[j]] = mode;
            }
        }
    }

    bool update(int &c, int &x, const int &c1, const int &x1) {
        if (c > c1 or (c == c1 and x <= x1)) return false;
        c = c1, x = x1;
        return true;
    }

    int count(int l, int r, int x) {
        auto hi = std::lower_bound(idx[x].begin(), idx[x].end(), r);
        auto lo = std::lower_bound(idx[x].begin(), idx[x].end(), l);
        return hi - lo;
    }

    T prod(int l, int r) {
        if (l >= r) return 0;
        T mode = 0, modec = 0;
        int sid = id[l], eid = id[r - 1];
        if (sid == eid) {
            for (int i = l; i < r; ++i)
                update(modec, mode, count(l, r, v[i]), v[i]);
            return d[mode];
        }
        for (int i = l; id[i] == sid; ++i)
            update(modec, mode, count(l, r, v[i]), v[i]);
        if (sid + 1 <= eid - 1)
            update(modec, mode, count(l, r, block[sid + 1][eid - 1]), block[sid + 1][eid - 1]);
        for (int i = r - 1; id[i] == eid; --i)
            update(modec, mode, count(l, r, v[i]), v[i]);
        return d[mode];
    }
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, q; std::cin >> n >> q;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    SquareRoot<int> data(a);
    for (int i = 0, x = 0; i < q; ++i) {
        int l, r;
        std::cin >> l >> r;
        l = ((l + x - 1) % n) + 1;
        r = ((r + x - 1) % n) + 1;
        if (l > r) std::swap(l, r);
        x = data.prod(l, r + 1);
        std::cout << x << '\n';
    }
    return 0;
}