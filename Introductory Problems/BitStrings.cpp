/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1617
**************************************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class BitStrings {
    static const int MOD = 1e9+7;
    int n;

    static int bin_exp(int n, int x, const int mod) {
        if(x == 0) return 1;
        if(n <= 1) return n;

        int cal = bin_exp(n, (x >> 1), mod);
        int cal_sq = (1LL * cal * cal) % mod;

        return (1LL * ((x & 1) ? n : 1) * cal_sq) % mod;
    }
public:
    BitStrings() {
        cin >> n;
    }

    void solve() {
        int bit_strings = bin_exp(2, n, MOD);
        cout << bit_strings;
    }
};

int main() {
    BitStrings bits;
    bits.solve();

    return 0;
}
