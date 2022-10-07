#include <bits/stdc++.h>
using namespace std;

using node = tuple<int, int, int, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> arr(m, vector<int>(n));
        for (auto &seq : arr)
            for (auto &x : seq) cin >> x;
        for (auto &seq : arr)
            sort(begin(seq), end(seq));
        auto merge = [&](int a, int b) {
            priority_queue<node, vector<node>, greater<>> pq;
            pq.emplace(arr[a][0] + arr[b][0], 0, 0, 1);
            vector<int> seq;
            while (!pq.empty() and size(seq) < n) {
                auto [val, i, j, add] = pq.top(); pq.pop();
                seq.push_back(val);
                if (j + 1 < n)
                    pq.emplace(arr[a][i] + arr[b][j + 1], i, j + 1, 0);
                if (i + 1 < n and add)
                pq.emplace(arr[a][i + 1] + arr[b][j], i + 1, j, 1);
            }
            arr[b] = move(seq);
        };
        for (int i = 0; i + 1 < m; ++i)
            merge(i, i + 1);
        for (int i = 0; i < n; ++i)
            cout << arr.back()[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}