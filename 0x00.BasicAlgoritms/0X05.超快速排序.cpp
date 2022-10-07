#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> arr, temp;

ll merge(int l, int mid, int r) {
    ll cnt = 0, p1 = l, p2 = mid;
    for (int i = l; i < r; ++i)
        if (p2 == r || p1 < mid && arr[p1] <= arr[p2])
            temp[i] = arr[p1++];
        else {
            temp[i] = arr[p2++];
            cnt += mid - p1;
        }
    for (int i = l; i < r; ++i)
        arr[i] = temp[i];
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
    while (cin >> n && n) {
        arr = temp = vector<int>(n);
        for (auto &x : arr) cin >> x;
        cout << merge_sort(0, n) << '\n';
    }
    return 0;
}