#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll multi(ll a, ll b, ll mod) {
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        a = a * 2 % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll a, b, p;
    cin >> a >> b >> p;
    cout << multi(a, b, p) << '\n';
    return 0;
}