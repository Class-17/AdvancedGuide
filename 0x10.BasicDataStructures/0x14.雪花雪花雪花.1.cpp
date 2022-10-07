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

bool comp(snow &a, snow &b) {
    for (int i = 0; i < len; ++i) {
        if (a == b) return true;
        int front = a[0];
        for (int j = 0; j + 1 < len; ++j)
            a[j] = a[j + 1];
        a.back() = front;
    }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<snow> snows(n);
    for (auto &s : snows)
        for (auto &x : s) cin >> x;
    auto check = [&]() {
        for (auto &a : snows) {
            int val = count(a);
            for (auto &b : mp[val]) {
                if (comp(a, b)) return true;
                reverse(begin(a), end(a));
                if (comp(a, b)) return true;
            }
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