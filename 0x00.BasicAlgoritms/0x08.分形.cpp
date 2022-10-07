#include <bits/stdc++.h>
using namespace std;

constexpr int f[] {1, 3, 9, 27, 81, 243, 729};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    while (cin >> n and n > 0) {
        int len = f[n - 1];
        vector<string> mat(len, string(len, ' '));
        mat[0][0] = 'X';
        for (int i = 1; i < n; ++i) {
            for (int r = 0; r < f[i - 1]; ++r)
                for (int c = 0; c < f[i - 1]; ++c) {
                    if (mat[r][c] == ' ') continue;
                    mat[r][c + f[i - 1] * 2] = 'X';
                    mat[r + f[i - 1] * 2][c] = 'X';
                    mat[r + f[i - 1]][c + f[i - 1]] = 'X';
                    mat[r + f[i - 1] * 2][c + f[i - 1] * 2] = 'X';
                }
        }
        for (auto &line : mat)
            cout << line << '\n';
        cout << "-\n";
    }
    return 0;
}