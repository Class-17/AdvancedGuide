#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    array<Trie*, 10> child;
    int tail;
public:
    Trie() : tail(0) {child.fill(nullptr);};

    void insert(const string &s) {
        Trie *t = this;
        for (auto &ch : s) {
            if (!t->child[ch - '0'])
                t->child[ch - '0'] = new Trie;
            t = t->child[ch - '0'];
        }
        ++t->tail;
    }

    int search(const string &s) {
        Trie *t = this;
        for (auto &ch : s) {
            if (t->tail) return -1;
            if (!t->child[ch - '0']) return 0;
            t = t->child[ch - '0'];
        }
        return t->tail > 1 ? -1 : 1;
    }

    void del() {
        for (auto &x : child) if (x) x->del();
        delete this;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        bool valid = true;
        Trie *t = new Trie;
        vector<string> strs(n);
        for (auto &s : strs) cin >> s;
        for (auto &s : strs) t->insert(s);
        auto check = [&]() {
            for (auto &s : strs)
                if (t->search(s) == -1) return false;
            return true;
        };
        cout << (check() ? "YES" : "NO") << '\n';
        t->del();
    }
    return 0;
}