template<class T>
class FenwickTree {
private:
    int n;
    vector<T> sum;
    int lowbit(int x) {return x & -x;}
public:
    FenwickTree(int n = 0) : n(n), sum(n + 1) {}
 
    void add(int x, T d) {
        for (; x <= n; x += lowbit(x))
            sum[x] += d;
    }

    T ask(int x) {
        T res = 0;
        for (; x; x -= lowbit(x))
            res += sum[x];
        return res;
    }
};