template<class T>
class UnionFind {
private:
    vector<T> dsu;
public:
    UnionFind(int n = 0) : dsu(n, -1) {}

    T find(T x) {
        if (dsu[x] < 0) return x;
        return dsu[x] = find(dsu[x]);
    }

    bool same(T x, T y) {
        return find(x) == find(y);
    }

    bool unite(T x, T y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (dsu[x] > dsu[y]) swap(x, y);
        dsu[x] += dsu[y];
        dsu[y] = x;
        return true;
    }
};