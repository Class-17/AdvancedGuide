#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> combs;
vector<int> comb;

int n, m;

void dfs(int x) {
    if (x > n || size(comb) == m || size(comb) + n - x + 1 < m) {
        if (size(comb) == m)
            combs.push_back(comb);
        return;
    }
    comb.push_back(x);
    dfs(x + 1);
    comb.pop_back();
    dfs(x + 1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    dfs(1);
    for (auto &seq : combs)
        for (int i = 0; i < m; ++i)
            cout << seq[i] << (i + 1 < m ? ' ' : '\n');
    return 0;
}