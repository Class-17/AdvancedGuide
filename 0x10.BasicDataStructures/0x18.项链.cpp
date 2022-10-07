#include <bits/stdc++.h>
using namespace std;

string f(const string &s) {
    int n = size(s);
    int i = 0, j = 1;
    while (i < n and j < n) {
        int k = 0;
        while (k < n and s[(i + k) % n] == s[(j + k) % n]) ++k;
        if (k == n) break;
        if (s[(i + k) % n] > s[(j + k) % n]) i += k + 1;
        else                                 j += k + 1;
        if (i == j) ++i;
    }
    int p = min(i, j);
    string ret;
    for (int i = 0; i < n; ++i)
        ret.push_back(s[(i + p) % n]);
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    tie(a, b) = pair{f(a), f(b)};
    cout << (a == b ? "Yes\n" + a : "No") << '\n';
    return 0;
}