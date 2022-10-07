#include <bits/stdc++.h>
using namespace std;

constexpr int lim = 32768;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    string s;
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        char c; int x;
        cin >> c >> x;
        s.push_back(c);
        arr.push_back(x);
    }
    s = s + s;
    for (int i = 0; i < n; ++i)
        arr.push_back(arr[i]);
    vector dpMin(n * 2 + 1, vector(n * 2 + 1, lim));
    vector dpMax(n * 2 + 1, vector(n * 2 + 1, -lim));
    for (int i = 0; i < n * 2; ++i)
        dpMin[i][i + 1] = dpMax[i][i + 1] = arr[i];
    for (int len = 2; len <= n * 2; ++len)
        for (int l = 0; l + len <= n * 2; ++l) {
            int r = l + len;
            for (int k = l + 1; k < r; ++k) {
                if (s[k] == 't') {
                    dpMin[l][r] = min(dpMin[l][r], dpMin[l][k] + dpMin[k][r]);
                    dpMax[l][r] = max(dpMax[l][r], dpMax[l][k] + dpMax[k][r]);
                }
                else {
                    const int lo[] = {dpMin[l][k], dpMax[l][k]};
                    const int hi[] = {dpMin[k][r], dpMax[k][r]};
                    for (int i = 0; i < 2; ++i) 
                        for (int j = 0; j < 2; ++j) {
                            dpMin[l][r] = min(dpMin[l][r], lo[i] * hi[j]);
                            dpMax[l][r] = max(dpMax[l][r], lo[i] * hi[j]);
                        }
                }
            }
        }
    vector<int> res(n);
    for (int i = 0; i < n; ++i)
        res[i] = dpMax[i][i + n];
    int score = *max_element(begin(res), end(res));
    vector<int> seq;
    for (int i = 0; i < n; ++i)
        if (res[i] == score) seq.push_back(i);
    int len = size(seq);
    cout << score << '\n';
    for (int i = 0; i < len; ++i)
        cout << seq[i] + 1 << (i + 1 < len ? ' ' : '\n');
    return 0;
}