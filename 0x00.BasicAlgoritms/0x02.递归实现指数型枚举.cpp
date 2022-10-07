#include <bits/stdc++.h>
using namespace std;

vector<int> seq;

int n;

void dfs(int x) {
    if (x > n) {
        int len = size(seq);
        for (int i = 0; i < len; ++i)
            cout << seq[i] << (i + 1 < len ? ' ' : '\n');
        if (len == 0) cout << '\n';
        return;
    }
    dfs(x + 1);
    seq.push_back(x);
    dfs(x + 1);
    seq.pop_back();
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    dfs(1);
    return 0;
}