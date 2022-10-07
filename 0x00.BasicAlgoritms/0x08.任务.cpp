#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m) {
        vector<tuple<int, bool, int>> arr(n + m);
        for (int i = 0; i < n; ++i) {
            auto &[x, t, y] = arr[i];
            cin >> x >> y;
            t = 1;
        }
        for (int i = n; i < n + m; ++i) {
            auto &[x, t, y] = arr[i];
            cin >> x >> y;
            t = 0;
        }
        sort(rbegin(arr), rend(arr));
        multiset<pair<int, int>> st;
        long long cnt = 0, profit = 0;
        for (auto &[x, t, y] : arr) {
            if (t) st.insert({y, x});
            else {
                auto obj = st.lower_bound({y, x});
                if (obj == end(st)) continue;
                st.erase(obj);
                profit += x * 500 + y * 2;
                ++cnt;
            }
        }
        cout << cnt << ' ' << profit << '\n';
    }
    return 0;
}