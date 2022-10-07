#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, root;
    cin >> n >> root;
    vector<int> w(n), cnt(n, 1), tree(n);;
    for (auto &x : w) cin >> x;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        tree[b - 1] = a - 1;
    }
    vector<double> avg(n);
    for (int i = 0; i < n; ++i)
        avg[i] = w[i];
    int cost = accumulate(begin(w), end(w), 0);
    for (int i = 0; i < n - 1; ++i) {
        int u = -1;
        double val = 0;
        for (int i = 0; i < n; ++i)
            if (i != root - 1 and val < avg[i])
                tie(u, val) = pair{i, avg[i]};
        int p = tree[u];
        for (int i = 0; i < n; ++i)
            if (tree[i] == u) tree[i] = p;
        cost += w[u] * cnt[p];
        w[p] += w[u];
        cnt[p] += cnt[u];
        avg[p] = w[p] * 1.0 / cnt[p];
        avg[u] = -1;
    }
    cout << cost << '\n';
    return 0;
}