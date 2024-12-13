#include <bits/stdc++.h>

using i64 = long long;

namespace Matrix {
    template<class T>
    using Mat = std::vector<std::vector<T>>;

    template<class T>
    Mat<T> e(int n) {
        std::vector a(n, std::vector(n, T()));
        for (int i = 0; i < n; ++i)
            a[i][i] = 1;
        return a;
    }

    template<class T>
    Mat<T> multi(const Mat<T> &a, const Mat<T> &b) {
        assert(!a.empty() and !b.empty() and a[0].size() == b.size());
        int n = a.size(), m = b.size(), p = b[0].size();
        std::vector c(n, std::vector(m, T()));
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < m; ++k)
                for (int j = 0; j < p; ++j)
                    c[i][j] += a[i][k] * b[k][j];
        return c;
    }

    template<class T>
    Mat<T> pow(Mat<T> x, unsigned long long n) {
        assert(!x.empty() and x.size() == x[0].size());
        auto res = e<T>(x.size());
        while (n) {
            if (n & 1)
                res = multi(res, x);
            x = multi(x, x);
            n >>= 1;
        }
        return res;
    }

    template<class T>
    void print(Mat<T> mat) {
        if (mat.empty()) return;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                std::cout << mat[i][j] << " \n"[j + 1 == m];
    }
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    int t, act;
    std::cin >> t >> act;
    std::string grid = "#";
    for (int i = 0; i < n; ++i) {
        std::string s; std::cin >> s;
        grid += s;
    }
    std::vector<std::string> seq(act);
    for (auto &s : seq) std::cin >> s;
    int round = 1;
    for (auto &s : seq)
        round = std::lcm(round, s.size());
    std::vector<Matrix::Mat<i64>> a(round + 1, Matrix::e<i64>(n * m + 1));
    for (int i = 1; i <= round; ++i) {
        for (int r = 1; r <= n; ++r)
            for (int c = 1; c <= m; ++c) {
                auto f = [&](int i, int j) {return (i - 1) * m + j;};
                auto s = seq[grid[f(r, c)] - '0'];
                auto op = s[(i - 1) % s.size()];
                if (isdigit(op))
                    a[i][0][f(r, c)] = op - '0';
                else {
                    if (op == 'N' and r > 1)
                        a[i][f(r, c)][f(r - 1, c)] = 1;
                    else if (op == 'W' and c > 1)
                        a[i][f(r, c)][f(r, c - 1)] = 1;
                    else if (op == 'S' and r < n)
                        a[i][f(r, c)][f(r + 1, c)] = 1;
                    else if (op == 'E' and c < m)
                        a[i][f(r, c)][f(r, c + 1)] = 1;
                    a[i][f(r, c)][f(r, c)] = 0;
                }
            }
        a[i] = Matrix::multi(a[i - 1], a[i]);
    }
    auto [d, r] = std::div(t, round);
    auto at = Matrix::multi(Matrix::pow(a[round], d), a[r]);
    Matrix::Mat<i64> dp = {std::vector(n * m + 1, i64())};
    dp[0][0] = 1;
    dp = Matrix::multi(dp, at);
    std::cout << *std::max_element(dp[0].begin(), dp[0].end()) << '\n';
    return 0;
}