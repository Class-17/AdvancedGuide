#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    array<Trie*, 26> child;
    int tail;
public:
    Trie() : tail(0) {child.fill(nullptr);};

    void insert(const string &s) {
        Trie *t = this;
        for (auto &ch : s) {
            if (!t->child[ch - 'a'])
                t->child[ch - 'a'] = new Trie();
            t = t->child[ch - 'a'];
        }
        ++t->tail;
    }

    int search(const string &s) {
        Trie *t = this;
        int sum = 0;
        for (auto &ch : s) {
            if (!t->child[ch - 'a']) return sum;
            t = t->child[ch - 'a'];
            sum += t->tail;
        }
        return sum;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    Trie *t = new Trie();
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        t->insert(s);
    }
    for (int i = 0; i < m; ++i) {
        string s; cin >> s;
        cout << t->search(s) << '\n';
    }
    return 0;
}