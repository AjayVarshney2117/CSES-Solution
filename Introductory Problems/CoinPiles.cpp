/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1754
**************************************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;

class CoinPiles {
    int a, b;

    static bool isEmpty(long long int a, long long int b) {
        if(max(a, b) > (min(a, b) << 1)) return false;
        return ((a + b) % 3 == 0);
    }
public:
    CoinPiles() {
        cin >> a >> b;
    }

    void solve() {
        bool tellMePlease = isEmpty(a, b);
        cout << (tellMePlease ? "YES" : "NO") << endl;
    }
};

int main() {
    int t = 0;
    cin >> t;

    while(t--) {
        CoinPiles piles;
        piles.solve();
    }

    return 0;
}
