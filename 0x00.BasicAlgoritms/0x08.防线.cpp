#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        vector<tuple<int, int, int>> arr(n);
        for (auto &[s, e, d] : arr)
            cin >> s >> e >> d;
        auto check = [&](ll x) {
            ll cnt = 0;
            for (auto &[s, e, d] : arr) {
                if (x < s) continue;
                cnt += (min(x, ll(e)) - s) / d + 1;
            }
            return cnt;
        };
        ll lo = 0, hi = 1LL << 31;
        while (lo < hi) {
            ll mid = lo + (hi - lo) / 2;
            if (check(mid) & 1 ^ 1) lo = mid + 1;
            else                    hi = mid;
        }
        ll cnt = check(lo) - check(lo - 1);
        if (cnt & 1)
            cout << lo << ' ' << cnt << '\n';
        else
            cout << "There's no weakness." << '\n';
    }
    return 0;
}