#include <bits/stdc++.h>
using namespace std;

using ll = long long;

double f(pair<ll, ll> a, pair<ll, ll> b) {
    ll x = a.first - b.first;
    ll y = a.second - b.second;
    return sqrt(x * x + y * y) * 10;
}

pair<ll, ll> count(ll n, ll p) {
    if (n == 0) return {0, 0};
    ll len = 1LL << (n - 1), cnt = 1LL << (n * 2 - 2);
    auto [x, y] = count(n - 1, p % cnt);
    ll z = p / cnt;
    pair<ll, ll> pos;
    if (z == 0) pos = {y, x};
    if (z == 1) pos = {x, y + len};
    if (z == 2) pos = {x + len, y + len};
    if (z == 3) pos = {-y - 1 + len * 2, -x - 1 + len};
    return pos;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        ll n, a, b;
        cin >> n >> a >> b;
        double d = f(count(n, a - 1), count(n, b - 1));
        cout << fixed << setprecision(0) << d << '\n';
    }
    return 0;
}