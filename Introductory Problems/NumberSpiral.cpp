/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1071
**************************************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class NumberSpiral {
    long long int row, col;

    static long long int spiral(long long int x, long long int y) {
        if(x > y) {
            if(x & 1) return x * x - y + 1;
            return (x - 1) * (x - 1) + y;
        }
        else {
            if(y & 1) return (y - 1) * (y - 1) + x;
            return y * y - x + 1;
        }
    }
public:
    NumberSpiral() {
        cin >> col >> row;
    }

    void solve() {
        long long int val = spiral(row, col);
        
        cout << val << endl;
    }
};

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        NumberSpiral ns;
        ns.solve();
    }

    return 0;
}
