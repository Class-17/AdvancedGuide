#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;

vector<int> arr;

int lowbit(int x) {return x & -x;}

void add(vector<int> &sum, int idx, int val) {
    for (; idx <= n; idx += lowbit(idx))
        sum[idx] += val;
}

int ask(vector<int> &sum, int idx) {
    int res = 0;
    for (; idx > 0; idx -= lowbit(idx))
        res += sum[idx];
    return res;
}

ll countA() {
    vector<int> left(n), right(n);
    vector<int> a(n + 1), b(n + 1);
    for (int i = 0; i < n; ++i) {
        left[i] = ask(a, n) - ask(a, arr[i]);
        add(a, arr[i], 1);
    }
    for (int i = n - 1; i >= 0; --i) {
        right[i] = ask(b, n) - ask(b, arr[i]);
        add(b, arr[i], 1);
    }
    ll cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += 1LL * left[i] * right[i];
    return cnt;
}

ll countB() {
    vector<int> left(n), right(n);
    vector<int> a(n + 1), b(n + 1);
    for (int i = 0; i < n; ++i) {
        left[i] = ask(a, arr[i] - 1);
        add(a, arr[i], 1);
    }
    for (int i = n - 1; i >= 0; --i) {
        right[i] = ask(b, arr[i] - 1);
        add(b, arr[i], 1);
    }
    ll cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += 1LL * left[i] * right[i];
    return cnt;
}


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    arr = vector<int>(n);
    for (auto &x : arr) cin >> x;
    cout << countA() << ' ' << countB() << '\n';
    return 0;
}