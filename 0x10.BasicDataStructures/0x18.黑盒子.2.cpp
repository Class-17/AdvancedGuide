#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    tree<pair<int, int>, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> tree;
    for (int i = 0, j = 0; i < n and j < m; ++i) {
        tree.insert({a[i], i});
        while (i + 1 == b[j]) {
            auto [val, _] = *tree.find_by_order(j);
            cout << val << '\n';
            ++j;
        }
    }
    return 0;
}