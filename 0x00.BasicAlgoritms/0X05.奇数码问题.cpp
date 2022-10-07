#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> a, b;

ll merge(int l, int mid, int r) {
    ll p1 = l, p2 = mid, cnt = 0;
    for (int i = l; i < r; ++i)
        if (p2 == r || p1 < mid && a[p1] <= a[p2])
            b[i] = a[p1++];
        else {
            b[i] = a[p2++];
            if (b[i])
                cnt += mid - p1;
        }
    for (int i = l; i < r; ++i)
        a[i] = b[i];
    return cnt;
}

ll merge_sort(int l, int r) {
    if (r - l <= 1) return 0;
    ll cnt = 0, mid = l + (r - l) / 2;
    cnt += merge_sort(l, mid);
    cnt += merge_sort(mid, r);
    cnt += merge(l, mid, r);
    return cnt;
}

int main() {
    int n;
    while (cin >> n) {
        n *= n;
        a = b = vector<int>(n);
        for (auto &x : a) cin >> x;
        ll ca = merge_sort(0, n);
        for (auto &x : a) cin >> x;
        ll cb = merge_sort(0, n);
        cout << ((ca & 1) == (cb & 1) ? "TAK" : "NIE") << '\n';
    }
    return 0;
}