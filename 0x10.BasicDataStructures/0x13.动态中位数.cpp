#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        int t, n;
        cin >> t >> n;
        cout << t << ' ' << (n + 1) / 2 << '\n';
        vector<int> arr(n), id(n);
        for (auto &x : arr) cin >> x;
        iota(begin(id), end(id), 0);
        sort(begin(id), end(id), [&](const auto &a, const auto &b) {
            return arr[a] != arr[b] ? arr[a] < arr[b] : a < b;});
        vector<list<int>::iterator> its(n);
        list<int> lt;
        for (auto &x : id)
            its[x] = lt.insert(end(lt), x);
        auto med = begin(lt);
        int lt_len = size(lt);
        for (int i = 0; i < n / 2; ++i) ++med;
        auto get_med = [&](int idx) {
            int ret = arr[*med];
            bool comp = (arr[idx] != arr[*med] ? arr[idx] < arr[*med] : idx < *med);
            if ((comp or idx == *med) and !(lt_len & 1)) ++med;
            else if (!comp and lt_len & 1) --med;
            lt.erase(its[idx]);
            --lt_len;
            return ret;
        };
        vector<int> res;
        for (int i = n - 1; i >= 0; --i) {
            int curr = get_med(i);
            if (i & 1 ^ 1) res.push_back(curr);
        }
        reverse(begin(res), end(res));
        int pf = 1;
        for (auto &x : res)
            cout << x << ((pf++) % 10 ? ' ' : '\n');
        if ((pf - 1) % 10) cout << '\n';
    }
    return 0;
}