/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1662
**************************************************************************/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

class SubarrayDivisibility {
    vector<int> arr;

    long findSubarraySum(vector<int> &arr) {
        const int n = arr.size();
        
        vector<int> freq(n, 0);

        freq[0] = 1;
        long cnt = 0, sum_div = 0;
        for(long i : arr) {
            sum_div = ((sum_div + i) % n + n) % n;
            cnt += freq[sum_div];

            ++freq[sum_div];
        }

        return cnt;
    }
public:
    SubarrayDivisibility() {
        int n;
        cin >> n;
        arr = vector<int>(n);
        for(int &i : arr) cin >> i;
    }

    void solve() {
        long cntSub = findSubarraySum(arr);
        cout << cntSub;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        SubarrayDivisibility subarrdiv;
        subarrdiv.solve();
    }

    return 0;
}
