/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1618
**************************************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class TrailingZeros {
    int n;

    static int ICanTellYouTHEZeros(int n) {
        // Let me calculate it
        int zeros_count = 0;

        while(n) {
            zeros_count += n / 5;
            n /= 5;
        }

        return zeros_count;
    }
public:
    TrailingZeros() {
        cin >> n;
    }

    void solve() {
        int tellMeHowMany = ICanTellYouTHEZeros(n);
        cout << tellMeHowMany;
    }
};

int main() {
    TrailingZeros tellMeHowManyZeros;
    tellMeHowManyZeros.solve();

    return 0;
}
