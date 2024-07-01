/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1661
**************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::cout;
using std::vector;
using std::unordered_map;

class SubarraySumsII {
    vector<int> arr;
    long target;

    long findSubarraySum(vector<int> &arr, long target) {
        unordered_map<long, long> freq;

        freq[0] = 1;
        long cnt = 0, pre = 0;
        for(long i : arr) {
            pre += i;
            cnt += freq[pre - target];

            ++freq[pre];
        }

        return cnt;
    }
public:
    SubarraySumsII() {
        int n;
        cin >> n >> target;
        arr = vector<int>(n);
        for(int &i : arr) cin >> i;
    }

    void solve() {
        long cntSub = findSubarraySum(arr, target);
        cout << cntSub;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        SubarraySumsII subarr;
        subarr.solve();
    }

    return 0;
}
