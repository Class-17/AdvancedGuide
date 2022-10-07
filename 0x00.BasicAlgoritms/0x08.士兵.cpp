#include <bits/stdc++.h>
using namespace std;

int count(vector<int> &arr) {
    sort(begin(arr), end(arr));
    int med = arr[size(arr) / 2], cnt = 0;
    for (auto &x : arr) cnt += abs(x - med);
    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    sort(begin(x), end(x));
    for (int i = 0; i < n; ++i)
        x[i] -= i;
    cout << count(x) + count(y) << '\n';
    return 0;
}