#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5;
constexpr double eps = 1e-5;
constexpr double inf = 1e9;

int n, f, arr[maxn + 1];
double val[maxn + 1];

bool check(double x) {
    for (int i = 1; i <= n; ++i)
        val[i] = arr[i] - x;
    partial_sum(val, val + n + 1, val);
    double max_sum = -inf, min_pre = inf;
    for (int i = f; i <= n; ++i) {
        min_pre = min(min_pre, val[i - f]);
        max_sum = max(max_sum, val[i] - min_pre);
    }
    return max_sum >= 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> f;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    double l = 1, r = 2000;
    while (r - l > eps) {
        double mid = l + (r - l) / 2;
        if (check(mid)) l = mid;
        else            r = mid;
    }
    cout << int(r * 1e3) << '\n';
    return 0;
}