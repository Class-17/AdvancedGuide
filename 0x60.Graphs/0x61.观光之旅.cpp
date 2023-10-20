#include <bits/stdc++.h>
using namespace std;

constexpr int N = 100;

unsigned int g[N+1][N+1], d[N+1][N+1];

int pos[N+1][N+1];

vector<int> path;

void getPath(int u, int v) {
	if (pos[u][v] == 0) return;
	getPath(u, pos[u][v]);
	path.push_back(pos[u][v]);
	getPath(pos[u][v], v);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; ++i) {
    	int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = min(g[u][v], w * 1u);
        g[v][u] = min(g[v][u], w * 1u);
    }
    memcpy(d, g, sizeof g);
    int res = 0x3f3f3f3f;
    for (int k = 1; k <= n; ++k) {
    	for (int i = 1; i < k; ++i)
    		for (int j = i + 1; j < k; ++j)
    			if (d[i][j] + g[i][k] + g[k][j] < res) {
    				res = d[i][j] + g[i][k] + g[k][j];
    				path.clear();
    				path.push_back(i);
    				getPath(i, j);
    				path.push_back(j);
    				path.push_back(k);
				}
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
					pos[i][j] = k;
				}
	}
	if (res == 0x3f3f3f3f)
		cout << "No solution." << '\n';
	else {
		int len = size(path);
		for (int i = 0; i < len; ++i)
			cout << path[i] << " \n"[i + 1 == len];
	}
	return 0;
}