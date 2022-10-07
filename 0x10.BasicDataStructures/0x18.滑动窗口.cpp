#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    deque<int> lo, hi;
    vector<int> a, b;
    for (int i = 0, j = 0; i + k <= n; ++i) {
        while (j < n and j - i < k) {
            while (!lo.empty() and arr[j] < lo.back())
                lo.pop_back();
            while (!hi.empty() and arr[j] > hi.back())
                hi.pop_back();
            lo.push_back(arr[j]);
            hi.push_back(arr[j]);
            ++j;
        }
        a.push_back(lo.front());
        b.push_back(hi.front());
        if (lo.front() == arr[i]) lo.pop_front();
        if (hi.front() == arr[i]) hi.pop_front();
    }
    int m = n - k + 1;
    for (int i = 0; i < m; ++i)
        cout << a[i] << (i + 1 < m ? ' ' : '\n');
    for (int i = 0; i < m; ++i)
        cout << b[i] << (i + 1 < m ? ' ' : '\n');
    return 0;
}