#include <bits/stdc++.h>
using namespace std;

string dfs(const string &s, int idx) {
    vector<string> strs;
    while (idx + 1 < size(s) and s[idx + 1] == '0') {
        strs.push_back(dfs(s, idx + 1));
        idx += size(strs.back());
    }
    sort(begin(strs), end(strs));
    string res;
    for (auto &str : strs)
        res += str;
    return '0' + res + '1';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        string a, b;
        cin >> a >> b;
        a = dfs('0' + a + '1', 0);
        b = dfs('0' + b + '1', 0);
        cout << (a == b ? "same" : "different") << '\n';
    }
    return 0;
}