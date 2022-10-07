#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<pair<int, int>>> g(n);
    vector<int> de(n);
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        ++de[u];
        ++de[v];
    }
    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (de[i] == 1) q.push(i);
    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto &[v, w] : g[u])
            --de[v];
    }
    int a = -1, b = -1;
    for (int i = 0; i < n; ++i)
        if (de[i] == 1) b = i;
    for (int i = n - 1; i >= 0; --i)
        if (de[i] == 1) a = i;
    multiset<int> left, right;
    left.insert(INT_MAX);
    right.insert(INT_MAX);
    int curr = a;
    vector<int> st(n);
    st[a] = 1;
    while (true) {
        int idx = curr;
        for (auto &[x, w] : g[curr])
            if (de[x] and !st[x]) idx = x;
        if (idx == curr) break;
        
    }
    return 0;
}