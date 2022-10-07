#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

bool compare(int a, int b) {
    return g[a - 1][b - 1];
}

class Solution {
public:
    vector<int> specialSort(int n) {
        vector<int> seq = {1};
        for (int i = 2; i <= n; ++i) {
            int l = 0, r = size(seq);
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (compare(seq[mid], i)) l = mid + 1;
                else                      r = mid;
            }
            seq.insert(begin(seq) + l, i);
        }
        return seq;
    }
};

int read() {
    string s;
    getline(cin, s);
    s = s.substr(1, size(s) - 2);
    int len = size(s);
    for (int i = 0; i < len; ++i) {
        if (!isdigit(s[i])) continue;
        vector<int> curr;
        int j = i;
        while (j < len && s[j] != ']') {
            while (j < len && isdigit(s[j])) ++j;
            curr.push_back(stoi(s.substr(i, j - i)));
            if (s[j] == ']') break;
            j += 2;
            i = j;
        }
        g.push_back(curr);
    }
    return size(g);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n = read();
    auto res = Solution().specialSort(n);
    cout << '[';
    for (int i = 0; i < n; ++i)
        cout << res[i] << (i + 1 < n ? ", " : "]\n");
    return 0;
}