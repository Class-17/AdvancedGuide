#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    vector<int> st;
    int n = size(s), max_len = 0;
    for (int i = 0; i < n; ++i) {
        if (!st.empty() and (s[i] == ')' and s[st.back()]== '(' or
             s[i] == ']' and s[st.back()]== '[' or
             s[i] == '}' and s[st.back()]== '{'))
            st.pop_back();
        else
            st.push_back(i);
        max_len = max(max_len, st.empty() ? i + 1 : i - st.back());
    }
    cout << max_len << '\n';
    return 0;
}