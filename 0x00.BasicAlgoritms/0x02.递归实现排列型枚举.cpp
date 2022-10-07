#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> comb(n);
    iota(begin(comb), end(comb), 1);
    do {
        for (int i = 0; i < n; ++i)
            cout << comb[i] << (i + 1 < n ? ' ' : '\n');
    } while (next_permutation(begin(comb), end(comb)));
    return 0;
}