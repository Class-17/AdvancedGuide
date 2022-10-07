#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 9901;

ll quick_pow(ll a, ll p) {
    ll res = 1 % mod;
    while (p) {
        if (p & 1) res = res * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return res;
}

int sum(int p, int c) {
    if (c <= 1) return (1 + (c ? p : 0)) % mod;
    int res = 1 + quick_pow(p, (c + 1)/ 2);
    res = res * sum(p, (c - 1) / 2) % mod;
    if (c & 1 ^ 1) res = (res + quick_pow(p, c)) % mod;
    return res;
}

int count(int a, int b) {
    if (!a or !b) return a ? 1 : 0;
    vector<pair<int, int>> seq;
    int cnt = 0;
    for (int i = 2; i <= a; ++i) {
        int cnt = 0;
        while (a % i == 0) {
            a /= i;
            ++cnt;
        }
        if (cnt) seq.emplace_back(i, cnt);
    }
    int res = 1;
    for (auto &[x, cnt] : seq)
        res = (res * sum(x, cnt * b)) % mod;
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    cout << count(a, b) << '\n';
    return 0;
}