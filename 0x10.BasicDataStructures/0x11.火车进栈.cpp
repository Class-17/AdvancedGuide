#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> seq, st;
    int cnt = 0;
    auto dfs = [&](auto &dfs, int idx)->void {
        if (cnt >= 20) return;
        if (size(seq) == n) {
            for (auto &x : seq) cout << x;
            cout << '\n';
            ++cnt;
            return;
        }
        if (!st.empty()) {
            seq.push_back(st.back());
            st.pop_back();
            dfs(dfs, idx);
            st.push_back(seq.back());
            seq.pop_back();
        }
        if (idx <= n) {
            st.push_back(idx);
            dfs(dfs, idx + 1);
            st.pop_back();
        }
    };
    dfs(dfs, 1);
    return 0;
}