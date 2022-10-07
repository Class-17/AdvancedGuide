#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int q; (cin >> q).get();
    vector<int> a, b, st;
    int pre_sum = 0;
    for (int i = 0; i < q; ++i) {
        char ch; cin >> ch;
        if (ch == 'I') {
            int x; (cin >> x).get();
            a.push_back(x);
            pre_sum += x;
            int ns = (st.empty() ? pre_sum : max(pre_sum, st.back()));
            st.push_back(ns);
        }
        else if (ch == 'D') {
            if (a.empty()) continue;
            pre_sum -= a.back();
            a.pop_back();
            st.pop_back();
        }
        else if (ch == 'L') {
            if (a.empty()) continue;
            pre_sum -= a.back();
            b.push_back(a.back());
            a.pop_back();
            st.pop_back();
        }
        else if (ch == 'R') {
            if (b.empty()) continue;
            a.push_back(b.back());
            pre_sum += b.back();
            int ns = (st.empty() ? pre_sum : max(pre_sum, st.back()));
            st.push_back(ns);
            b.pop_back();
        }
        else if (ch == 'Q') {
            int k; (cin >> k).get();
            cout << st[k - 1] << '\n';
        }
    }
    return 0;
}