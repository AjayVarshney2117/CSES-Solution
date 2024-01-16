/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1074
**************************************************************************/

#include <iostream>
#include <climits>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::sort;

class StickLengths {
    int n, *p;

    static long long CountOperations(int *p, int n) {
        sort(p, p+n);

        long long sufSum = 0, preSum = 0;
        for(int i=0 ; i<n ; ++i) sufSum += p[i];

        long long minOperations = LLONG_MAX;
        for(int i=0 ; i<n ; ++i) {
            sufSum -= p[i];

            long long operations = (1LL * i * p[i] - preSum) + (sufSum - 1LL * (n - i-1) * p[i]);
            minOperations = min(minOperations, operations);

            preSum += p[i];
        }

        return minOperations;
    }
public:
    StickLengths() {
        cin >> n;

        p = new int[n];
        for(int i=0 ; i<n ; ++i) cin >> p[i];
    }

    void solve() {
        long long number_of_operations = CountOperations(p, n);
        cout << number_of_operations;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        StickLengths sticky;
        sticky.solve();
    }

    return 0;
}
