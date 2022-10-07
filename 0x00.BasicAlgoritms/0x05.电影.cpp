#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ++mp[x];
    }
    int m; cin >> m;
    vector<pair<int, int>> arr(m);
    for (auto &[a, b] : arr) cin >> a;
    for (auto &[a, b] : arr) cin >> b;
    int x = 0, y = 0, idx = 0;
    for (int i = 0; i < m; ++i) {
        int xx = mp[arr[i].first], yy = mp[arr[i].second];
        if (xx > x || (xx == x && yy > y))
            tie(x, y, idx) = tuple{xx, yy, i + 1};
    }
    cout << idx << '\n';
    return 0;
}