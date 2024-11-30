#include <bits/stdc++.h>

using i64 = long long;

struct Node {
    i64 x, y, m, p, r;
};

template<class T>
class SquareRoot {
private:
    int n, len, cnt;
    std::vector<T> v;
    std::vector<std::vector<int>> idx;
    std::vector<std::vector<int>> block;
    std::vector<int> id;
    std::vector<std::vector<int>> rid;
    i64 x0, y0;
public:
    SquareRoot() : SquareRoot(0) {}
    explicit SquareRoot(int n) : SquareRoot(std::vector<T>(n)) {}
    explicit SquareRoot(const std::vector<T> &a) : n(a.size()), v(a) {
        len = std::sqrt(n);
        cnt = (n + len - 1) / len;
        id = std::vector<int>(n);
        rid = std::vector<std::vector<int>>(cnt);
        for (int i = 0; i < n; ++i) {
            id[i] = i / len;
            rid[id[i]].push_back(i);
        }
        block = rid;
    }

    void init_block(i64 x, i64 y) {
        x0 = x, y0 = y;
        for (auto &part : block)
            std::sort(part.begin(), part.end(), [&](const auto &x, const auto &y) {
                return dist(v[x].x, v[x].y) > dist(v[y].x, v[y].y);});
    }

    i64 dist(i64 x, i64 y) {
        return (x - x0) * (x - x0) + (y - y0) * (y - y0);
    }

    void select(Node s, std::queue<int> &q) {
        int i = 0;
        while (i < cnt and v[rid[i].back()].m <= s.p) {
            auto &part = block[i];
            while (!part.empty() and dist(v[part.back()].x, v[part.back()].y) <= s.r * s.r) {
                q.push(part.back());
                part.pop_back();
            }
            i += 1;
        }
        if (i >= cnt or v[rid[i][0]].m > s.p) return;
        std::vector<int> st;
        for (auto &j : block[i]) {
            if (v[j].m <= s.p and dist(v[j].x, v[j].y) <= s.r * s.r)
                q.push(j);
            else
                st.push_back(j);
        }
        block[i] = std::move(st);
    }
};

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int x0, y0, p0, r0, n;
    std::cin >> x0 >> y0 >> p0 >> r0 >> n;
    std::vector<Node> a(n);
    for (auto &[x, y, m, p, r] : a)
        std::cin >> x >> y >> m >> p >> r;
    std::sort(a.begin(), a.end(), [](const auto &x, const auto &y) {
        return x.m < y.m;
    });
    SquareRoot<Node> data(a);
    data.init_block(x0, y0);
    a.emplace_back(x0, y0, 0, p0, r0);
    std::queue<int> q;
    q.push(n);
    int res = 0;
    while (!q.empty()) {
        auto i = q.front(); q.pop();
        data.select(a[i], q);
        res += 1;
    }
    std::cout << res - 1 << '\n';
    return 0;
}