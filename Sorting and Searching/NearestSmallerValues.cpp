/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1645
**************************************************************************/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class NearestSmallerValues {
    vector<int> x;

    static vector<int> NSV(vector<int> &x) {
        const int n = x.size();

        vector<int> nsv(n);

        int stk[n], top = -1;
        for(int i=n-1 ; i>=0 ; --i) {
            while(top >= 0 && x[stk[top]] > x[i]) nsv[stk[top--]] = i+1;

            stk[++top] = i;
        }
        
        return nsv;
    }
public:
    NearestSmallerValues() {
        int n;
        cin >> n;
        x = vector<int>(n);
        for(int &i : x) cin >> i;
    }

    void solve() {
        vector<int> nsv = NSV(x);
        for(int i : nsv) cout << i << ' ';
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        NearestSmallerValues small;
        small.solve();
    }

    return 0;
}
