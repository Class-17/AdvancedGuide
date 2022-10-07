#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    for (auto &[l, r] : arr) cin >> l >> r;
    vector<int> idx(n), pos(n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](const auto &a, const auto &b) {
        return arr[a] < arr[b];});
    queue<int> q;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    q.push(1);
    for (int i = 0; i < n; ++i) {
        auto [l, r] = arr[idx[i]];
        while (!pq.empty() && pq.top().first < l) {
            q.push(pq.top().second);
            pq.pop();
        }
        int p = size(pq) + 1;
        if (!q.empty()) {
            p = q.front();
            q.pop();
        }
        pq.emplace(r, p);
        pos[idx[i]] = p;
    }
    cout << *max_element(begin(pos), end(pos)) << '\n';
    for (auto &x : pos) cout << x << '\n';
    return 0;
}