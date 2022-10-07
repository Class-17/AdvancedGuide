#include <bits/stdc++.h>
using namespace std;

int cToD(const char &ch) {
    if (islower(ch)) return ch - 'a' + 36;
    if (isupper(ch)) return ch - 'A' + 10;
    return ch - '0';
}

char dToC(const int &digit) {
    if (digit >= 36) return digit - 36 + 'a';
    if (digit >= 10) return digit - 10 + 'A';
    return digit + '0';
}

int div(vector<int> &sum, int num) {    
    int rem = 0, n = size(sum);
    for (int i = n - 1; i >= 0; --i) {
        int x = rem * 10 + sum[i];
        sum[i] = x / num;
        rem = x % num;
    }
    while (size(sum) > 1 && !sum.back())
        sum.pop_back();
    return rem;
}

void multi(vector<int> &sum, int num) {
    int rem = 0;
    for (auto &x : sum) {
        int val = x * num + rem;
        x = val % 10;
        rem = val / 10;
    }
    while (rem) {
        sum.push_back(rem % 10);
        rem /= 10;
    }
}

void add(vector<int> &sum, int num) {
    int rem = num;
    for (auto &x : sum) {
        int val = x + rem;
        x = val % 10;
        rem = val / 10;
    }
    while (rem) {
        sum.push_back(rem % 10);
        rem /= 10;
    }
}

string convert(int in, int out, string &s) {
    vector num{0};
    for (auto &ch : s) {
        multi(num, in);
        add(num, cToD(ch));
    }
    string res;
    while (true) {
        if (size(num) == 1 and num[0] == 0) break;
        int rem = div(num, out);
        res.push_back(dToC(rem));
    }
    if (res.empty()) res.push_back('0');
    reverse(begin(res), end(res));
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        int in, out;
        string num;
        cin >> in >> out >> num;
        cout << in << ' ' << num << '\n';
        num = convert(in, out, num);
        cout << out << ' ' << num << '\n';
        cout << '\n';
    }
    return 0;
}