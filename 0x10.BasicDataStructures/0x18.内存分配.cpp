#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

struct node {
    int t, s, e;
    node(int t, int s, int e) : t(t), s(s), e(e) {};
    bool operator < (const node &x) const {
        return t > x.t;
    }
};

set<pii> space;
queue<pii> q;
priority_queue<node> pq;

bool en_queue(int t, int m, int p) {
    for (auto &[s, e] : space) {
        if (e - s < m) continue;
        int over = min(e, s + m);
        pq.emplace(t + p, s, over);
        space.erase({s, e});
        if (over < e)
            space.emplace(over, e);
        return true;
    }
    return false;
}

void process(int time) {
    while (!pq.empty() and time >= pq.top().t) {
        int curr_time = pq.top().t;
        while (!pq.empty() and pq.top().t == curr_time) {
            auto [_, s, e] = pq.top(); pq.pop();
            auto hi = space.upper_bound({s, e});
            if (hi != begin(space) and prev(hi)->second == s) {
                s = prev(hi)->first;
                space.erase(prev(hi));
            }
            if (hi != end(space) and hi->first == e) {
                e = hi->second;
                space.erase(hi);
            }
            space.emplace(s, e);
        }
        while (!q.empty()) {
            auto [m, p] = q.front();
            if (!en_queue(curr_time, m, p)) break;
            q.pop();
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    int t, m, p;
    int cnt = 0;
    space.emplace(0, n);
    while (cin >> t >> m >> p and (t + m + p)) {
        process(t);
        if (!en_queue(t, m, p)) {
            q.emplace(m, p);
            ++cnt;
        }
    }
    while (!pq.empty()) {
        t = pq.top().t;
        process(t);
    }
    cout << t << '\n';
    cout << cnt << '\n';
    return 0;
}