#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, p, h, m;
    cin >> n >> p >> h >> m;
    set<pair<int, int>> st;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        st.emplace(a, b);
    }
    vector<int> diff(n);
    for (auto &[a, b] : st) {
        --diff[a];
        ++diff[b - 1];
    }
    for (int i = 1; i < n; ++i)
        diff[i] += diff[i - 1];
    for (auto &x : diff)
        cout << h + x << '\n';
    return 0;
}