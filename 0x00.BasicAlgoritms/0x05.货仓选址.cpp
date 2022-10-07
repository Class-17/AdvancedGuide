#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    sort(begin(arr), end(arr));
    int pos = arr[n / 2];
    long long dist = 0;
    for (auto &x : arr)
        dist += abs(x - pos);
    cout << dist << '\n';
    return 0;
}