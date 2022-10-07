#include <bits/stdc++.h>
using namespace std;

using ull = uint64_t;

constexpr int P = 131;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    string s;
    while (cin >> s and s != "END") {
        cout << "Case " << _++ << ": ";
        int n = size(s);
        vector<ull> fa(n + 1), fb(n + 1), p(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fa[i] = fa[i - 1] * P + s[i - 1] - 'a' + 1;
            fb[n - i] = fb[n - i + 1] * P + s[n - i] - 'a' + 1;
            p[i] = p[i - 1] * P;
        }
        int len = 1;
        auto check = [&](int l, int r) {
            if (l >= r) return true;
            int lr = (r - l & 1 ? (l + r >> 1) + 1 : (l + r >> 1));
            int rl = (r - l & 1 ? lr : lr + 1);
            ull a = fa[lr] - fa[l] * p[lr - l];
            ull b = fb[rl] - fb[r + 1] * p[r + 1 - rl];
            return a == b;
        };
        auto expand = [&] (int l, int r) {
            while (l >= 0 && r < n && check(l, r))
                l--, r++;
            return (l + r - 1 >> 1) - l;
        };
        for (int i = 1; i < n; ++i) {
            int odd = expand(i - len / 2, i + len / 2) * 2 + 1;
            int even = expand(i - len / 2, i + len / 2 - 1) * 2;
            len = max({len, odd, even});
        }
        cout << len << '\n';
    }
    return 0;
}