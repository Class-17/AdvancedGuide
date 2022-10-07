#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    partial_sum(begin(arr), end(arr), begin(arr));
    deque<pair<int, int>> q{{0, 0}};
    int max_val = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        while (!q.empty() and q.front().second < i - m)
            q.pop_front();
        auto pre_min = q.empty() ? 0 : q.front().first;
        max_val = max(max_val, arr[i] - pre_min);
        while (!q.empty() and q.back().first > arr[i])
            q.pop_back();
        q.emplace_back(arr[i], i);
    }
    cout << max_val << '\n';
    return 0;
}