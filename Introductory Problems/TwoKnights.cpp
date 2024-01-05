/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1072
**************************************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class TwoKnights {
    int n;

    static long long int calculateWays(const int n) {
        long long int totalWaysToPutOneKnight = n * n;
        
        long long int totalWaysToPutKnights = (totalWaysToPutOneKnight * (totalWaysToPutOneKnight - 1)) >> 1;
        long long int totalWaysToAttackOtherKnight = 4 * (n - 1) * (n - 2);

        long long int totalWaysToNotAttackOtherKnight = totalWaysToPutKnights - totalWaysToAttackOtherKnight;
        return totalWaysToNotAttackOtherKnight;
    }
public:
    TwoKnights(int n) {
        this->n = n;
    }

    void solve() {
        cout << calculateWays(n) << endl;
    }
};

int main() {
    int t;
    cin >> t;
    
    for(int i=1 ; i<=t ; ++i) {
        TwoKnights hehe(i);
        hehe.solve();
    }

    return 0;
}
