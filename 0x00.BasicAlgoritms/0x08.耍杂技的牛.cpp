#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int, int>> cows(n);
    for (auto &[w, s] : cows)
        cin >> w >> s;
    sort(begin(cows), end(cows), [](const auto &a, const auto &b) {
        return b.first - a.second > a.first - b.second;});
    int sum = 0, max_risk = INT_MIN;
    for (auto &[w, s] : cows) {
        max_risk = max(max_risk, sum - s);
        sum += w;
    }
    cout << max_risk << '\n';
    return 0;
}