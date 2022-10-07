#include <bits/stdc++.h>
using namespace std;

constexpr int n = 4;

void trans(vector<string> &mat, int r, int c) {
    for (int i = 0; i < n; ++i)
        mat[i][c] = (mat[i][c] == '+' ? '-' : '+');
    for (int j = 0; j < n; ++j)
        mat[r][j] = (mat[r][j] == '+' ? '-' : '+');
    mat[r][c] = (mat[r][c] == '+' ? '-' : '+');
}

bool check(vector<string> &mat) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (mat[i][j] == '+') return false;
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<string> mat(n);
    for (auto &s : mat) cin >> s;
    int min_moves = n * n, state = 0;
    for (int i = (1 << (n * n)) - 1; i >= 0; --i) {
        int moves = __builtin_popcount(i);
        if (moves > min_moves) continue;
        auto temp = mat;
        for (int r = 0; r < n; ++r)
            for (int c = 0; c < n; ++c)
                if (i >> (r * n + c) & 1)
                    trans(temp, r, c);
        if (!check(temp)) continue;
        tie(min_moves, state) = pair{moves, i};
    }
    cout << min_moves << '\n';
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (state >> (i * n + j) & 1)
                cout << i + 1 << ' ' << j + 1 << '\n';
    return 0;
}