#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll quick_pow(ll a, ll b, int mod) {
    ll res = 1 % mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int a, b, p;
    cin >> a >> b >> p;
    cout << quick_pow(a, b, p) << '\n';
    return 0;
}