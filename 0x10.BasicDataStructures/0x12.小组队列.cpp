#include <bits/stdc++.h>
using namespace std;

constexpr int maxt = 1000;
constexpr int maxn = 1e6;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _ = 1, t;
    while (cin >> t and t) {
        cout << "Scenario #" << _++ << '\n';
        int mp[maxn];
        for (int i = 0; i < t; ++i) {
            int n; cin >> n;
            for (int j = 0; j < n; ++j) {
                int x; cin >> x;
                mp[x] = i;
            }
        }
        queue<int> q, qs[maxt];
        string op;
        while (cin >> op and op != "STOP") {
            if (op == "ENQUEUE") {
                int x; cin >> x;
                if (qs[mp[x]].empty()) q.push(mp[x]);
                qs[mp[x]].push(x);
            }
            else {
                cout << qs[q.front()].front() << '\n';
                qs[q.front()].pop();
                if (qs[q.front()].empty()) q.pop();
            }
        }
        cout << '\n';
    }
    return 0;
}