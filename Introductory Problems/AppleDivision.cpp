/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1623
**************************************************************************/

#include <iostream>
#include <climits>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::min;

class AppleDivision {
    vector<int> p;
    int n;
    
    long long int total_sum = 0;

    void findThatMinDiff(int ind, long long int sum, long long int &min_diff) {
        if(ind == n) {
            min_diff = min(min_diff, llabs(total_sum - (sum << 1)));
            return;
        }

        // take
        findThatMinDiff(ind+1, p[ind] + sum, min_diff);
        // not take
        findThatMinDiff(ind+1, sum, min_diff);
    }
public:
    AppleDivision() {
        cin >> n;

        p = vector<int>(n);
        for(int &i : p) {
            cin >> i;
            total_sum += i;
        }
    }

    void solve() {
        long long int min_diff = LLONG_MAX;
        findThatMinDiff(0, 0, min_diff);

        cout << min_diff;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        AppleDivision badApple;
        badApple.solve();
    }

    return 0;
}
