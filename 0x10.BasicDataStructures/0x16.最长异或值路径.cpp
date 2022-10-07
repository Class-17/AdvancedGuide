#include <bits/stdc++.h>
using namespace std;

constexpr int len = 30;

class Trie {
private:
    array<Trie*, 2> child;
    int tail;
public:
    Trie() : tail(0) {child.fill(nullptr);};

    void insert(int x) {
        Trie *t = this;
        for (int i = len; i >= 0; --i) {
            int curr = x >> i & 1;
            if (!t->child[curr])
                t->child[curr] = new Trie();
            t = t->child[curr];
        }
        ++t->tail;
    }

    int search(int x) {
        Trie *t = this;
        int val = 0;
        for (int i = len; i >= 0; --i) {
            int curr = x >> i & 1;
            if (!t->child[0] and !t->child[1]) return val;
            if (t->child[!curr]) {
                val |= (!curr) << i;
                t = t->child[curr ^ 1];
            }
            else {
                val |= curr << i;
                t = t->child[curr];
            }
        }
        return val ^ x;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector<int> d(n, -1);
    d[0] = 0;
    auto dfs = [&](auto &dfs, int u, int val)->void {
        for (auto &[v, w] : g[u]) {
            if (d[v] != -1) continue;
            d[v] = val ^ w;
            dfs(dfs, v, d[v]);
        }
    };
    dfs(dfs, 0, 0);
    Trie *t = new Trie();
    int max_val = 0;
    for (auto &x : d) {
        max_val = max(max_val, t->search(x));
        t->insert(x);
    }
    cout << max_val << '\n';
    return 0;
}