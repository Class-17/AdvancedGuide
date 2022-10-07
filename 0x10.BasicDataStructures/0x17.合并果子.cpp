#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        pq.push(x);
    }
    int cost = 0;
    while (size(pq) > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        cost += a + b;
        pq.push(a + b);
    }
    cout << cost << '\n';
    return 0;
}