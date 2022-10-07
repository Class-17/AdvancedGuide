#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    vector<pair<double, double>> arr(n);
    for (auto &[x, y]: arr)
        cin >> x >> y;
    auto count = [&]() {
        for (auto &[x, y] : arr) {
            if (d < y) return -1;
            auto c = sqrt(d * d - y * y);
            tie(x, y) = pair{x - c, x + c};
        }
        sort(begin(arr), end(arr));
        int cnt = 0;
        double bound = arr.front().first - 1;
        for (auto &[l ,r] : arr) {
            if (l > bound) {
                bound = r;
                ++cnt;
            }
            else
                bound = min(bound, r);
        }
        return cnt;
    };
    cout << count() << '\n';
    return 0;
}