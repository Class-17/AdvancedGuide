#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        pq.emplace(x, 0);
    }
    while ((size(pq) - 1) % (k - 1))
        pq.emplace(0, 0);
    ll sum = 0;
    while (size(pq) > 1) {
        ll val = 0, depth = 0;
        for (int i = 0; i < k; ++i) {
            auto [x, d] = pq.top(); pq.pop();
            val += x;
            depth = max(depth, d);
        }
        sum += val;
        pq.emplace(val, depth + 1);
    }
    cout << sum << '\n';
    cout << pq.top().second << '\n';
    return 0;
}