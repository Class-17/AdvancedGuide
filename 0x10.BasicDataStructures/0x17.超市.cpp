#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    while (cin >> n) {
        vector<pair<int, int>> arr(n);
        for (auto &[d, p] : arr)
            cin >> p >> d;
        sort(begin(arr), end(arr));
        priority_queue<int, vector<int>, greater<>> pq;
        for (auto &[d, p] : arr) {
            pq.push(p);
            if (size(pq) > d) pq.pop();
        }
        int sum = 0;
        while (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        cout << sum << '\n';
    }
    return 0;
}