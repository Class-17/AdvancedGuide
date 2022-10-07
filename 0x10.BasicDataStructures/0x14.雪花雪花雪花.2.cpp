#include <bits/stdc++.h>
using namespace std;

constexpr int P = 99991;
constexpr int len = 6;

using snow = array<int, len>;

vector<snow> mp[P];

int count(snow &s) {
    int sum = 0, produc = 1;
    for (auto &x : s) {
        sum = (sum + x) % P;
        produc = produc * 1LL * x % P;
    }
    return (sum + produc) % P;
};

snow convert(snow &s) {
    int i = 0, j = 1;
    while (i < len and j < len) {
        int k = 0;
        while (k < len and s[(i + k) % len] == s[(j + k) % len])
            ++k;
        if (k == len) break;
        if (s[(i + k) % len] > s[(j + k) % len]) {
            i = i + k + 1;
            if (i == j) ++i;
        }
        else {
            j = j + k + 1;
            if (i == j) ++j;
        }
    }
    int p = min(i, j);
    snow ret;
    for (int i = 0; i < len; ++i)
        ret[i] = s[(i + p) % len];
    return ret;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<snow> arr(n);
    for (auto &a : arr) {
        for (auto &x : a) cin >> x;
        auto b = a;
        reverse(begin(b), end(b));
        a = min(convert(a), convert(b));
    }
    auto check = [&]() {
        for (auto &a : arr) {
            int val = count(a);
            for (auto &b : mp[val])
                if (a == b) return true;
            mp[val].push_back(a);
        }
        return false;
    };
    if (check())
        cout << "Twin snowflakes found." << '\n';
    else
        cout << "No two snowflakes are alike." << '\n';
    return 0;
}