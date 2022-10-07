#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    vector<int> a, b;
    
    MinStack() {}
    
    void push(int x) {
        a.push_back(x);
        if (b.empty())
            b.push_back(x);
        else
            b.push_back(min(b.back(), x));
    }
    
    void pop() {
        a.pop_back();
        b.pop_back();
    }
    
    int top() {return a.back();}
    
    int getMin() {return b.back();}
};
 
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    return 0;
}