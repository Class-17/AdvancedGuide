#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1, n;
    while (cin >> n and n) {
        cout << "Test case #" << _++ << '\n';
        string s; cin >> s;
        vector<int> pi(n);
        for (int i = 1, j = 0; i < n; ++i) {
            while (j > 0 and s[i] != s[j])
                j = pi[j - 1];
            if (s[i] == s[j]) ++j;
            if (!j or (i + 1) % (i + 1 - j)) continue;
            cout << i + 1 << ' ' << (i + 1) / (i + 1 - j) << '\n';
        }
        cout << '\n';
    }
    return 0;
}