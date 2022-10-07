#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        int t, n;
        cin >> t >> n;
        cout << t << ' ' << (n + 1) / 2 << '\n';
        priority_queue<int> pqa;
        priority_queue<int, vector<int>, greater<>> pqb;
        auto insert = [&](int x) {
            if (pqa.empty() || x < pqa.top()) pqa.push(x);
            else                              pqb.push(x);
            while (size(pqa) > size(pqb) + 1) {
                pqb.push(pqa.top());
                pqa.pop();
            }
            while (size(pqa) < size(pqb)) {
                pqa.push(pqb.top());
                pqb.pop();
            }
            return pqa.top();
        };
        int pf = 1;
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x;
            int med = insert(x);
            if (i & 1) 
                cout << med << ((pf++) % 10 ? ' ' : '\n');
        }
        if ((pf - 1) % 10) cout << '\n';
    }
    return 0;
}