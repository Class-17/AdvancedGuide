#include <bits/stdc++.h>
using namespace std;

constexpr int N = 26;

int floyd(vector<int> g[], int n) {
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                g[i][j] |= g[i][k] & g[k][j];
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (g[i][j] == 1 and g[j][i] == 1)
                return 0;
            else if (g[i][j] == 0 and g[j][i] == 0)
                return -1;
    return 1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m and n) {
        vector<int> g[N];
        fill(g, g + N, vector<int>(26));
        int finish = 0, conflict = 0;
        for (int i = 1; i <= m; ++i) {
            string e; cin >> e;

            int u = e[0] - 'A', v = e[2] - 'A';
            if (finish > 0 or conflict > 0) continue;
            if (g[v][u] == 1 or u == v) {
                conflict = i;
                continue;
            }
            g[u][v] = 1;
            int res = floyd(g, n);
            if (res == 1) finish = i;
            if (res == 0) conflict = i;
        }
        if (finish > 0) {
            cout << "Sorted sequence determined after " << finish << " relations: ";
            string s(n, 'A');
            iota(begin(s), end(s), 'A');
            sort(begin(s), end(s), [&](const auto &a, const auto &b) {
                return g[a - 'A'][b - 'A'];
            });
            cout << s << ".\n"; 
        }
        else if (conflict > 0)
            cout << "Inconsistency found after " << conflict << " relations." << '\n';
        else
            cout << "Sorted sequence cannot be determined." << '\n';
    }
    return 0;
}