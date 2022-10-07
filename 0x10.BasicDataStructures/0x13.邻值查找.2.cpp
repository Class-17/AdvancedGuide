#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n), id(n);
    for (auto &x : arr) cin >> x;
    iota(begin(id), end(id), 0);
    sort(begin(id), end(id), [&](const auto &a, const auto &b) {
        return arr[a] < arr[b];});
    vector<list<int>::iterator> its(n);
    list<int> lt;
    for (auto &x : id)
        its[x] = lt.insert(end(lt), x);
    vector<pair<int, int>> res(n - 1);
    for (int i = n - 1; i > 0; --i) { 
        auto it = its[i];
        auto lo = (it != begin(lt) ? prev(it) : next(it));
        auto hi = (next(it) != end(lt) ? next(it) : prev(it));
        auto comp = [&](const pair<int, int> &a, const pair<int, int> &b) {
            int da = abs(arr[*it] - a.first);
            int db = abs(arr[*it] - b.first);
            return da <= db ? pair{da, a.second} : pair{db, b.second};
        };
        res[i - 1] = comp({arr[*lo], *lo}, {arr[*hi], *hi});
        lt.erase(it);
    }
    for (auto &[x, p] : res)
        cout << x << ' ' << p + 1 << '\n';
    return 0;
}