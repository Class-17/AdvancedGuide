#include <bits/stdc++.h>
using namespace std;

constexpr int n = 13;

int char_to_num(const char &ch) {
    if (ch == 'A') return 0;
    if (ch == '0') return 9;
    if (ch == 'J') return 10;
    if (ch == 'Q') return 11;
    if (ch == 'K') return 12;
    return ch - '1';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<vector<int>> cards(n);
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        for (auto &ch : s) {
            if (ch == ' ') continue;;
            cards[i].push_back(char_to_num(ch));
        }
    }
    array<int, n> cnt{0};
    int hp = 4, p = n - 1;
    while (hp) {
        if (cards[p].empty()) break;
        auto card = cards[p].back();
        cards[p].pop_back();
        if (card == n - 1) {
            --hp; p = n - 1; continue;
        }
        ++cnt[card];
        p = card;
    }
    int res = 0;
    for (auto &x : cnt)
        res += (x == 4);
    cout << res << '\n';
    return 0;
}