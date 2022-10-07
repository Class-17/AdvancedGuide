#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1;
    string s;
    while (cin >> s and s != "END") {
        cout << "Case " << _++ << ": ";
        auto transe = [](const string &s) {
            string ss;
            for (auto &ch : s) {
                ss.push_back('#');
                ss.push_back(ch);
            }
            ss.push_back('#');
            return ss;
        };
        s = transe(s);
        int n = size(s);
        vector<int> d(n);
        for (int i = 0, l = 0, r = -1; i < n; ++i) {
            d[i] = (i > r ? 1 : min(d[l + r - i], r - i + 1));
            while (0 <= i - d[i] and i + d[i] < n and s[i - d[i]] == s[i + d[i]])
                ++d[i];
            if (i + d[i] - 1 > r) {
                l = i - d[i] + 1;
                r = i + d[i] - 1;
            }
        }
        cout << *max_element(begin(d), end(d)) - 1 << '\n';
    }
    return 0;
}