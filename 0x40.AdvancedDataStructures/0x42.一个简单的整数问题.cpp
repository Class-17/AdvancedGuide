#include <bits/stdc++.h>
using namespace std;

int n, m;

vector<int> arr;

vector<int> sum;

int lowbit(int x) {return x & -x;};

void add(int idx, int val) {
    for (; idx <= n; idx += lowbit(idx))
        sum[idx] += val;
}

int ask(int idx) {
    int res = 0;
    for (; idx > 0; idx -= lowbit(idx))
        res += sum[idx];
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    arr = vector<int>(n + 1);
    sum = vector<int>(n + 2);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    for (int i = 0; i < m; ++i) {
        string q; cin >> q;
        if (q == "Q") {
            int x; cin >> x;
            cout << arr[x] + ask(x) << '\n';
        }
        else {
            int l, r, d;
            cin >> l >> r >> d;
            add(l, d);
            add(r + 1, -d);
        }
    }
    return 0;
}