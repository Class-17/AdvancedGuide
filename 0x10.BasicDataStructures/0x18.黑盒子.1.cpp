#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<>> hi; 
    auto insert = [&](int x) {
        if (hi.empty() or x > hi.top()) hi.push(x);
        else                            lo.push(x);
    };
    auto adjust = [&](int level) {
        while (size(lo) < level) {
            lo.push(hi.top());
            hi.pop();
        }
        while (size(lo) > level) {
            hi.push(lo.top());
            lo.pop();
        }
    };
    for (int i = 0, j = 0; i < n and j < m; ++i) {
        insert(a[i]);
        while (i + 1 == b[j]) {
            adjust(j);
            cout << hi.top() << '\n';
            ++j;
        }
    }
    return 0;
}