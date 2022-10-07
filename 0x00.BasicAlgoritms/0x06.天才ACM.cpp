#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, m, t;

vector<int> arr, seq, temp;

void merge(int l, int mid, int r) {
    int p1 = l, p2 = mid;
    for (int i = l; i < r; ++i)
        if (p2 == r or p1 < mid and seq[p1] <= seq[p2])
            temp[i] = seq[p1++];
        else
            temp[i] = seq[p2++];
    for (int i = l; i < r; ++i)
        seq[i] = temp[i];
}

bool check(int l, int mid, int r) {
    for (int i = l; i < r; ++i)
        seq[i] = arr[i];
    sort(begin(seq) + mid, begin(seq) + r);
    merge(l, mid, r);
    ll i = l, j = r - 1, val = 0;
    while (i < j and i - l < m) {
        ll d = seq[i] - seq[j];
        val += d * d;
        ++i, --j;
    }
    if (val <= t)
        for (int i = l; i < r; ++i)
            arr[i] = seq[i];
    return val <= t;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        cin >> n >> m >> t;
        arr = seq = temp = vector<int>(n);
        for (auto &x : arr) cin >> x;
        int l = 0, cnt = 0;
        while (l < n) {
            ll r = l + 1, p = 1;
            while (p and r <= n)
                if (check(l, r, min(r + p, n)))
                    r += p, p *= 2;
                else 
                    p /= 2;
            l = r;
            ++cnt;
        }
        cout << cnt << '\n';
    }
    return 0;
}