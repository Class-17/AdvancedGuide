#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> arr(n), cover(m);
    for (auto &[a, b] : arr)
        cin >> a >> b;
    for (auto &[a, b] : cover)
        cin >> a >> b;
    sort(rbegin(arr), rend(arr));
    sort(rbegin(cover), rend(cover));
    auto find = [&](int l, int r) {
        for (auto &[val, cnt] : cover) {
            if (l > val or val > r or !cnt) continue;
            --cnt;
            return true;
        }
        return false;
    };
    int res = 0;
    for (auto &[l, r] : arr)
        res += find(l, r);
    cout << res << '\n';
    return 0;
}