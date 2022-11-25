class string_hash {
using ull = uint64_t;
static constexpr int P = 131;
private:
    int n;
    string s;
    vector<ull> fa, fb, p;
public:
    string_hash() {}
    
    string_hash(const string &s) : s(s), n(size(s)) {
        fa = fb = p = vector<ull>(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fa[i] = fa[i - 1] * P + s[i - 1] - 'a' + 1;
            fb[n - i] = fb[n - i + 1] * P + s[n - i] - 'a' + 1;
            p[i] = p[i - 1] * P;
        }
    }

    bool check_pali(const size_t &l, const size_t &r) {
        // for interval [l, r]
        if (l >= r) return true;
        int lr = (r - l & 1 ? (l + r >> 1) + 1 : (l + r >> 1));
        int rl = (r - l & 1 ? lr : lr + 1);
        ull a = fa[lr] - fa[l] * p[lr - l];
        ull b = fb[rl] - fb[r + 1] * p[r + 1 - rl];
        return a == b;
    }

    string longestPalindrome() {
        int l = 0, r = 0;
        auto expand = [&] (int l, int r) {
            while (l >= 0 && r < n && check_pali(l, r))
                l--, r++;
            return pair{l + 1, r - 1};
        };
        for (int i = 1; i < n; ++i) {
            int len = r - l + 1 >> 1;
            auto [l1, r1] = expand(i - len, i + len);
            auto [l2, r2] = expand(i - len, i + len - 1);
            if (r1 - l1 > r - l)
                tie(l, r) = pair{l1, r1};
            if (r2 - l2 > r - l)
                tie(l, r) = pair{l2, r2};
        }
        return s.substr(l, r - l + 1);
    }
};