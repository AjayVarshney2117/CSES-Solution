/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/2165
**************************************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class TowerOfHanoi {
    int n;

    void simulateTOH(int n, char src = '1', char aux = '2', char des = '3') {
        if(n == 1) {
            cout << src << ' ' << des << endl;
            return;
        }

        simulateTOH(n-1, src, des, aux);
        cout << src << ' ' << des << endl;
        simulateTOH(n-1, aux, src, des);
    }
public:
    TowerOfHanoi() {
        cin >> n;
    }

    void solve() {
        int number_of_steps = (1 << n) - 1;

        cout << number_of_steps << endl;
        simulateTOH(n);
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        TowerOfHanoi toh;
        toh.solve();
    }

    return 0;
}
