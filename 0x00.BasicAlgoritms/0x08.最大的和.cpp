#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mat;

int f(int r, int c) {
    return r < 0 or c < 0 ? 0 : mat[r][c];
}

void partial_sum() {
    int n = size(mat);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            mat[i][j] += f(i - 1, j) + f(i, j - 1) - f(i - 1, j - 1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    mat = vector<vector<int>>(n, vector<int>(n));
    for (auto &row : mat) for (auto &x : row) cin >> x;
    partial_sum();
    int max_sum = -1e3;
    for (int i = -1; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            int sum = 0;
            for (int p = 0; p < n; ++p) {
                if (sum < 0) sum = 0;
                sum += mat[j][p] - f(j, p - 1) - f(i, p) + f(i, p - 1);
                max_sum = max(max_sum, sum);
            }
        }
    cout << max_sum << '\n';
    return 0;
}