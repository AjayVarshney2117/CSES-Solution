/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/2183
**************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

class MissingCoinSum {
    vector<int> x;

    static long long int FindSmallestImpossible(vector<int> &coins) {
        int n = coins.size();
        sort(coins.begin(), coins.end());

        long long int sum = 1;
        int i = 0;
        while(i < n && coins[i] <= sum) sum += coins[i++];

        return sum;
    }
public:
    MissingCoinSum() {
        int n;
        cin >> n;

        x = vector<int>(n);
        for(int &i : x) cin >> i;
    }

    void solve() {
        long long int smallestImpossible = FindSmallestImpossible(x);
        cout << smallestImpossible;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        MissingCoinSum paisa_paisa;
        paisa_paisa.solve();
    }

    return 0;
}
