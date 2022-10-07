#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    set<pair<int, int>> st{{arr.front(), 0}};
    for (int i = 1; i < n; ++i) {
        auto hi = st.upper_bound({arr[i], -1});
        auto lo = hi;
        if (hi != begin(st)) --lo;
        if (hi == end(st)) --hi;
        auto comp = [&](const pair<int, int> &a, const pair<int, int> &b) {
            int da = abs(arr[i] - a.first);
            int db = abs(arr[i] - b.first);
            return da <= db ? pair{da, a.second} : pair{db, b.second};
        };
        auto [d, p] = comp(*lo, *hi);
        cout << d << ' ' << p + 1 << '\n';
        st.emplace(arr[i], i);
    }
    return 0;
}