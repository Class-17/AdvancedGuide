#include <bits/stdc++.h>
using namespace std;

constexpr int n = 5;
constexpr int inf = 7;
constexpr int dirs[][2] {0, 1, 1, 0, 0, -1, -1, 0};

int mat[n], flip[n];

int f(int r, int c) {
    int x = (mat[r] >> c & 1) ^ (flip[r] >> c & 1);
    for (auto &[dr, dc] : dirs) {
        auto [nr, nc] = pair{r + dr, c + dc};
        if (nr < 0 or nr >= n or nc < 0 or nc >= n) continue;
        x ^= flip[nr] >> nc & 1;
    }
    return x ^ 1;
}

int count() {
    for (int i = 1; i < n; ++i)
        for (int j = 0; j < n; ++j)
            flip[i] |= f(i - 1, j) << j;
    for (int i = 0; i < n; ++i)
        if (f(n - 1, i)) return inf;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += __builtin_popcount(flip[i]);
    return cnt;
}

int solve() {
    int cnt = inf;
    for (int i = 0; i < (1 << n); ++i) {
        memset(flip, 0, sizeof flip);
        for (int j = 0; j < n; ++j)
            if (i >> j & 1) flip[0] |= 1 << j;
        cnt = min(cnt, count());
    }
    return cnt < inf ? cnt : -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            mat[i] = bitset<n>(s).to_ulong();
        }
        cout << solve() << '\n';
    }
    return 0;
}