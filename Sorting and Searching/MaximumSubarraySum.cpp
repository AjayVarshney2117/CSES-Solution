/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1643
**************************************************************************/

#include <iostream>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::max;

class MaximumSubarraySum {
    int n, *a;

    static long long int FindMaxSum(int *a, int n) {
        long long int sum = 0, max_sum = LLONG_MIN;

        for(int i=0 ; i<n ; ++i) {
            if(sum + a[i] >= a[i]) sum += a[i];
            else sum = a[i];

            max_sum = max(max_sum, sum);
        }

        return max_sum;
    }
public:
    MaximumSubarraySum() {
        cin >> n;

        a = new int[n];
        for(int i=0 ; i<n ; ++i) cin >> a[i];
    }

    void solve() {
        long long int max_sum = FindMaxSum(a, n);
        cout << max_sum;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        MaximumSubarraySum sum;
        sum.solve();
    }

    return 0;
}
