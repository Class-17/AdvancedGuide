#include <bits/stdc++.h>
using namespace std;

vector<int> div(vector<int> sum, int num) {    
    int n = size(sum), f = 0;
    for (int i = n - 1; i >= 0; --i) {
        int val = sum[i] + f * 10;
        sum[i] = val / num;
        f = val % num;
    }
    while (size(sum) > 1 && !sum.back())
        sum.pop_back();
    return sum;
}

void multi(vector<int> &sum, int num) {
    int f = 0, n = size(sum);
    vector<int> res(n);
    for (int i = 0; i < n; ++i)
        res[i] = sum[i] * num;
    for (int i = 0; i < n; ++i) {
        int val = res[i] + f;
        sum[i] = val % 10;
        f = val / 10;
    }    
    while (f) {        
        sum.push_back(f % 10);
        f /= 10;
    }
}

bool comp(vector<int> &a, vector<int> &b) {
    int n = size(a), m = size(b);
    if (n != m) return n < m;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] < b[i])      return true;
        else if (a[i] > b[i]) return false;
    }    
    return true;
}

int main() {    
    cin.tie(nullptr)->sync_with_stdio(false);    
    int n; cin >> n;    
    vector<pair<int, int>> arr(n + 1);    
    for (auto &[l, r] : arr)        
    cin >> l >> r;    
    sort(begin(arr) + 1, end(arr), [](const auto &a, const auto &b) {
        return a.first * a.second < b.first * b.second;});
    vector<int> sum, res;    
    while (arr[0].first) {
        sum.push_back(arr[0].first % 10);
        arr[0].first /= 10;
    }
    for (int i = 1; i <= n; ++i) {
        auto curr = div(sum, arr[i].second);
        if (comp(res, curr))
            res = curr;
        multi(sum, arr[i].first);
    }    
    int len = size(res);
    for (int i = len - 1; i >= 0; --i)
       cout << res[i];
    cout << '\n';
    return 0;
}