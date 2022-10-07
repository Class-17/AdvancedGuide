#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5;

using pii = pair<int, int>;

int arr[maxn], l[maxn], r[maxn];

bitset<maxn + 1> st;

void remove(int p) {
    l[r[p]] = l[p];
    r[l[p]] = r[p];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int k = 1;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x * arr[k] < 0) arr[++k] = x;
        else                arr[k] += x;
    }
    n = k;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int cnt = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
        l[i] = i - 1;
        r[i] = i + 1;
        if (arr[i] > 0) {
            ++cnt;
            sum += arr[i];
        }
        pq.emplace(abs(arr[i]), i);
    }
    while (cnt > m) {
        while (!pq.empty() and st[pq.top().second]) pq.pop();
        auto [val, p] = pq.top(); pq.pop();
        if (l[p] != 0 and r[p] != n + 1 or arr[p] > 0) {
            sum -= val;
            --cnt;
            int lo = l[p], hi = r[p];
            st[lo] = st[hi] = 1;
            arr[p] += arr[lo] + arr[hi];
            pq.emplace(abs(arr[p]), p);
            remove(lo);
            remove(hi);
        }
    }
    cout << sum << '\n';
    return 0;
}