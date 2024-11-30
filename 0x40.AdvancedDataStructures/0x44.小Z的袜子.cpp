#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> Mo(const std::vector<std::pair<int, int>> &queries, int len) {
    std::vector<int> ord(queries.size());
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), [&](const auto &x, const auto &y) {
        const auto &[lx, rx] = queries[x];
        const auto &[ly, ry] = queries[y];
        int xid = lx / len, yid = ly / len;
        if (xid != yid) return lx < ly;
        return (~xid & 1) ? rx < ry : rx > ry;
    });
    return ord;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    std::vector<std::pair<int, int>> queries(m);
    for (auto &[l, r] : queries) std::cin >> l >> r;
    std::vector<std::pair<i64, i64>> res(m);
    i64 sum = 0;
    std::vector<int> cnt(n + 1);
    auto add = [&](int x) {
        sum += cnt[x]; cnt[x] += 1;
    };
    auto del = [&](int x) {
        cnt[x] -= 1; sum -= cnt[x];
    };
    for (int l = 1, r = 0; auto &i : Mo(queries, std::sqrt(n))) {
        const auto &[il, ir] = queries[i];
        if (il == ir) {res[i] = {0, 1}; continue;}
        while (l > il) add(a[--l]);
        while (r < ir) add(a[++r]);
        while (l < il) del(a[l++]);
        while (r > ir) del(a[r--]);
        i64 x = sum, y = (ir - il + 1LL) * (ir - il) / 2;
        i64 z = std::gcd(x, y);
        res[i] = {x / z, y / z};
    }
    for (auto &[x, y] : res)
        std::cout << x << "/" << y << '\n';
    return 0;
}