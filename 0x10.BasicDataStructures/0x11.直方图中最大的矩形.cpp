#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    while (cin >> n and n) {
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;
        arr.push_back(0);
        vector<pair<ll, int>> st;
        ll area = 0;
        for (auto &x : arr) {
            int w = 0;
            while (!st.empty() and x <= st.back().first) {
                w += st.back().second;
                area = max(area, st.back().first * w);
                st.pop_back();
            }
            st.emplace_back(x, w + 1);
        }
        cout << area << '\n';
    }
    return 0;
}