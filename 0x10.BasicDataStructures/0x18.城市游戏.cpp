#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    (cin >> n >> m).get();
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        for (int j = 0; j < m; ++j)
            mat[i][j] = (s[j * 2] == 'F');
    }
    for (int c = 0; c < m; ++c)
        for (int r = 1; r < n; ++r)
            if (mat[r][c])
                mat[r][c] += mat[r - 1][c];
    int max_area = 0;
    for (int r = 0; r < n; ++r) {
        int area = 0;
        vector<pair<int, int>> st;
        mat[r].push_back(0);
        for (auto &x : mat[r]) {
            int w = 0;
            while (!st.empty() and x <= st.back().first) {
                w += st.back().second;
                area = max(area, w * st.back().first);
                st.pop_back();
            }
            st.emplace_back(x, w + 1);
        }
        max_area = max(max_area, area);
    }
    cout << max_area * 3 << '\n';     
    return 0;
}