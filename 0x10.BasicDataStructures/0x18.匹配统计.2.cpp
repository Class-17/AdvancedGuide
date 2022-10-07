#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    string a, b;
    cin >> a >> b;
    a = b + '#' + a;
    vector<int> pi(n + m + 1), cnt(m + 2);
    for (int i = 1; i <= m + n; ++i) {
        int j = pi[i - 1];
        while (j > 0 and a[i] != a[j])
            j = pi[j - 1];
        if (a[i] == a[j]) ++j;
        pi[i] = j;
    }
    for (int i = 0; i < n; ++i)
        ++cnt[pi[m + 1 + i]];
    for (int i = m; i > 0; --i)
        cnt[pi[i - 1]] += cnt[i];
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        cout << cnt[x] - cnt[x + 1] << '\n';
    }
    return 0;
}