#include <bits/stdc++.h>
using namespace std;

constexpr int n = 9;

array<int, n> x, y, z;

string board;

void flip(int r, int c, int d) {
    x[r] ^= 1 << d;
    y[c] ^= 1 << d;
    z[r / 3 * 3 + c / 3] ^= 1 << d;
}

bool dfs() {
    int val = n + 1, r, c;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            if (isdigit(board[i * n + j])) continue;
            int curr = x[i] | y[j] | z[i / 3 * 3 + j / 3];
            curr = n - __builtin_popcount(curr);
            if (curr < val)
                tie(val, r, c) = tuple{curr, i, j};
        }
    if (val > n) return true;
    int bit = ~(x[r] | y[c] | z[r / 3 * 3 + c / 3]) & ((1 << n) - 1);
    while (bit > 0) {
        int d = __builtin_ctz(bit);
        flip(r, c, d);
        board[r * n + c] = d + '1';
        if (dfs()) return true;
        flip(r, c, d);
        bit &= bit - 1;
    }
    board[r * n + c] = '.';
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    while (cin >> board and board[0] != 'e') {
        x.fill(0), y.fill(0), z.fill(0);
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < n; ++c)
                if (isdigit(board[r * n + c])) 
                    flip(r, c, board[r * n + c] - '1');
        dfs();
        cout << board << '\n';
    }
    return 0;
}