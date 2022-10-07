#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    long long posti = 0, negati = 0;
    for (int i = 1; i < n; ++i) {
        int diff = a[i] - a[i - 1];
        if (diff > 0) posti += diff;
        else          negati -= diff;
    }
    cout << max(posti, negati) << '\n';
    cout << abs(posti - negati) + 1 << '\n';
    return 0;
}