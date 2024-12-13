#include <bits/stdc++.h>

template<int m>
class Modint {
private:
    unsigned int _v;
    static constexpr unsigned int umod() {return m;}
public:
    static constexpr int mod() {return m;}
    static Modint raw(int v) {
        Modint x;
        x._v = v;
        return x;
    }

    Modint() : _v(0) {}
    template<class T>
    Modint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }

    unsigned int val() const {return _v;}

    Modint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    Modint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    Modint operator++(int) {
        Modint result = *this;
        ++*this;
        return result;
    }
    Modint operator--(int) {
        Modint result = *this;
        --*this;
        return result;
    }

    Modint& operator+=(const Modint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    Modint& operator-=(const Modint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    Modint& operator*=(const Modint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    Modint& operator/=(const Modint& rhs) {return *this = *this * rhs.inv();}

    Modint operator+() const {return *this;}
    Modint operator-() const {return Modint() - *this;}

    Modint pow(long long n) const {
        if (n < 0) return pow(-n).inv();
        Modint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    Modint inv() const {
        assert(_v);
        return pow(umod() - 2);
    }

    friend Modint operator+(const Modint& lhs, const Modint& rhs) {
        return Modint(lhs) += rhs;
    }
    friend Modint operator-(const Modint& lhs, const Modint& rhs) {
        return Modint(lhs) -= rhs;
    }
    friend Modint operator*(const Modint& lhs, const Modint& rhs) {
        return Modint(lhs) *= rhs;
    }
    friend Modint operator/(const Modint& lhs, const Modint& rhs) {
        return Modint(lhs) /= rhs;
    }
    friend bool operator==(const Modint& lhs, const Modint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const Modint& lhs, const Modint& rhs) {
        return lhs._v != rhs._v;
    }
};

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
        assert(!a.empty() and !b.empty());
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
            if (n & 1) res = multi(res, x);
            x = multi(x, x);
            n >>= 1;
        }
        return res;
    }
}

using mint = Modint<10000>;

int solve(int n) {
    Matrix::Mat<mint> dp = {{0, 1}};
    if (n < 2) {
        std::cout << dp[0][n].val() << '\n';
        return 0;
    }
    Matrix::Mat<mint> a = {{0, 1}, {1, 1}};
    dp = Matrix::multi(dp, Matrix::pow(a, n - 1));
    std::cout << dp[0][1].val() << '\n';
    return 0;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    while (std::cin >> n and n != -1) solve(n);
    return 0;
}