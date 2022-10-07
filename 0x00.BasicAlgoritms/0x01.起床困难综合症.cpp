#include <bits/stdc++.h>
using namespace std;

vector<pair<string, int>> doors;

int count(int bit) {
    for (auto &[op, t] : doors) {
        if (op == "AND")     bit &= t;
        else if (op == "OR") bit |= t;
        else                 bit ^= t;
    }
    return bit;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    doors = vector<pair<string, int>>(n);
    for (auto &[op, t] : doors)
        cin >> op >> t;
    int x = 0;
    for (int i = 30; i >= 0; --i) {
        int zero = count(0) >> i & 1;
        int one = count(1 << i) >> i & 1;
        if ((x | 1 << i) <= m && one > zero)
            x |= 1 << i;
    }
    cout << count(x) << '\n';
    return 0;
}