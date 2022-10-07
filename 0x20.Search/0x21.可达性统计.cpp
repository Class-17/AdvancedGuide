#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 3e4;

vector<int> g[maxn];

bitset<maxn> st[maxn];

void dfs(int u) {
    st[u][u] = 1;
    for (auto &v : g[u]) {
        if (!st[v][v]) dfs(v);
        st[u] |= st[v];
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> deg(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        ++deg[y - 1];
    }
    for (int i = 0; i < n; ++i)
        if (!deg[i]) dfs(i);
    for (int i = 0; i < n; ++i)
        cout << st[i].count() << '\n';
    return 0;
}