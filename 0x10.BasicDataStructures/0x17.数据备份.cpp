#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int maxn = 1e5;
constexpr ll inf = 1e16;

struct node {
    ll val;
    list<pair<ll, ll>>::iterator it;
    node(ll val, list<pair<ll, ll>>::iterator it) : val(val), it(it) {};
    bool operator < (const node &x) const {
        return val > x.val;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    list<pair<ll, ll>> lt;
    priority_queue<node> pq;
    pq.emplace(inf, lt.emplace(end(lt), inf, 0));
    for (int i = 0; i + 1 < n; ++i) {
        ll d = arr[i + 1] - arr[i];
        auto it = lt.emplace(end(lt), d, i + 1);
        pq.emplace(d, it);
    }
    pq.emplace(inf, lt.emplace(end(lt), inf, n + 1));
    ll cost = 0;
    bitset<maxn> st;
    while (k--) {
        while (!pq.empty() and st[pq.top().it->second]) pq.pop();
        auto [val, it] = pq.top(); pq.pop();
        cost += val;
        ll l = prev(it)->first, r = next(it)->first;
        st[prev(it)->second] = st[next(it)->second] = 1;
        lt.erase(prev(it));
        lt.erase(next(it));
        it->first = l + r - it->first;
        pq.emplace(it->first, it);
    }
    cout << cost << '\n';
    return 0;
}