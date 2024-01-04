/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1070
**************************************************************************/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Permutations {
    int n;
public:
    Permutations() {
        cin >> n;
    }

    void solve() {
        if(n <= 3) {
            cout << ((n == 1) ? "1" : "NO SOLUTION");
            return;
        }

        for(int i=2 ; i<=n ; i+=2) cout << i << " ";
        for(int i=1 ; i<=n ; i+=2) cout << i << " ";
    }
};

int main() {
    Permutations perm;
    perm.solve();
    
    return 0;
}
