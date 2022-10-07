#include <bits/stdc++.h>
using namespace std;

vector<int> row, col, pos;
vector<vector<int>> mat;

int compress() {
    for (auto &x : row) pos.push_back(x);
    for (auto &x : col) pos.push_back(x);
    sort(begin(pos), end(pos));
    pos.erase(unique(begin(pos), end(pos)), end(pos));
    for (auto &x : row)
        x = lower_bound(begin(pos), end(pos), x) - begin(pos);
    for (auto &x : col)
        x = lower_bound(begin(pos), end(pos), x) - begin(pos);
    return size(pos);
}

int f(int r, int c) {
    if (r < 0 or c < 0) return 0;
    return mat[r][c];
}

void partial_sum() {
    int n = size(mat);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            mat[i][j] += f(i - 1, j) + f(i, j - 1) - f(i - 1, j - 1);
}

int check(int len, int c) {
    int n = size(mat);
    int s = upper_bound(begin(pos), end(pos), len) - begin(pos) - 1;
    for (int i = s; i < n; ++i)
        for (int j = s; j < n; ++j) {
            int ii = upper_bound(begin(pos), end(pos), pos[i] - len) - begin(pos) - 1;
            int jj = upper_bound(begin(pos), end(pos), pos[j] - len) - begin(pos) - 1;
            int cnt = f(i, j) - f(ii, j) - f(i, jj) + f(ii, jj);
            if (cnt >= c) return true;
        }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, c;
    cin >> c >> n;
    row = col = vector<int>(n);
    for (int i = 0; i < n; ++i)
        cin >> row[i] >> col[i];
    int m = compress();
    mat = vector<vector<int>>(m, vector<int>(m));
    for (int i = 0; i < n; ++i)
        mat[row[i]][col[i]] += 1;
    partial_sum();
    int lo = 1, hi = pos.back() + 1;
    while (lo < hi) {
        int mid = lo + hi >> 1;
        if (!check(mid, c)) lo = mid + 1;
        else                hi = mid;
    }
    cout << lo << '\n';
    return 0;
}