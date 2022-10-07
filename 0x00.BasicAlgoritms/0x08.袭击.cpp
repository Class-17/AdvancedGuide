#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 2e5;
constexpr double inf = 1e10;
constexpr int lim = 6;

struct point {
    double x, y;
    int type;
    bool operator < (const point &p) const {
        return x < p.x;
    }
} ps[maxn], temp[maxn];

double dist(const point &a, const point &b) {
    if (a.type == b.type) return inf;
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void merge(int l, int mid, int r) {
    int p1 = l, p2 = mid;
    for (int i = l; i < r; ++i)
        if (p2 == r or p1 < mid and ps[p1].y < ps[p2].y)
            temp[i] = ps[p1++];
        else
            temp[i] = ps[p2++];
    for (int i = l; i < r; ++i)
        ps[i] = temp[i];
}

double dfs(int l, int r) {
    if (r - l <= 1) return inf;
    int mid = l + (r - l) / 2;
    double mid_x = ps[mid].x;
    double res = min(dfs(l, mid), dfs(mid, r));
    merge(l, mid, r);
    int bound = 0;
    for (int i = l; i < r; ++i)
        if (abs(ps[i].x - mid_x) <= res)
            temp[bound++] = ps[i];
    for (int i = 0; i < bound; ++i)
        for (int j = i - 1; j >= 0 and i - j <= lim; --j)
            res = min(res, dist(temp[i], temp[j]));
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> ps[i].x >> ps[i].y;
            ps[i].type = 0;
        }
        for (int i = n; i < n * 2; ++i) {
            cin >> ps[i].x >> ps[i].y;
            ps[i].type = 1;
        }
        sort(ps, ps + n * 2);
        cout << fixed << setprecision(3) << dfs(0, n * 2) << '\n';
    }
    return 0;
}