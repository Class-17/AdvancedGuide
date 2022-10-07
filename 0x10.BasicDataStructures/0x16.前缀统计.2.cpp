#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e6;

int trie[maxn][26], cnt[maxn], tot;

void insert(const string &s, int p = 0) {
    for (auto &ch : s) {
        if (trie[p][ch - 'a'] == -1)
            trie[p][ch - 'a'] = ++tot;
        p = trie[p][ch - 'a'];
    }
    ++cnt[p];
}

int search(const string &s, int p = 0) {
    int sum = 0;
    for (auto &ch : s) {
        if (trie[p][ch - 'a'] == -1) return sum;
        p = trie[p][ch - 'a'];
        sum += cnt[p];
    }
    return sum;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    memset(trie, -1, sizeof trie);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        insert(s);
    }
    for (int i = 0; i < m; ++i) {
        string s; cin >> s;
        cout << search(s) << '\n';
    }
    return 0;
}