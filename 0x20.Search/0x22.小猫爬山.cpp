#include <bits/stdc++.h>
using namespace std;

vector<int> arr, cab;

int n, w, min_cost;

void dfs(int cnt, int idx) {
    if (cnt >= min_cost) return;
    if (idx == n) {
        min_cost = min(min_cost, cnt);
        return; 
    }
    for (int i = 0; i < cnt; ++i) {
        if (cab[i] + arr[idx] > w) continue;
        cab[i] += arr[idx];
        dfs(cnt, idx + 1);
        cab[i] -= arr[idx];
    }
    cab[cnt] = arr[idx];
    dfs(cnt + 1, idx + 1);
    cab[cnt] = 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> w;
    arr = cab = vector<int>(n);
    for (auto &x : arr) cin >> x;
    sort(rbegin(arr), rend(arr));
    min_cost = n;
    dfs(0, 0);
    cout << min_cost << '\n';
    return 0;
}