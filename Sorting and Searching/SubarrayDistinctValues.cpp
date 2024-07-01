/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/2428
**************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>

using std::cin;
using std::cout;
using std::vector;
using std::unordered_map;

class SubarrayDistinctValues {
    int k;
    vector<int> arr;

    long findSubarraySum(vector<int> &arr, int k) {
        const int n = arr.size();

        unordered_map<int, int> freq;
        int distinct = 0;
        long cnt = 0;
        for(int i=0, j=0 ; i<n ; ++i) {
            ++freq[arr[i]];
            if(freq[arr[i]] == 1) ++distinct;

            while(j<i && distinct > k) {
                --freq[arr[j]];
                if(freq[arr[j]] == 0) --distinct;
                ++j;
            }

            cnt += (i - j + 1);
        }

        return cnt;
    }
public:
    SubarrayDistinctValues() {
        int n;
        cin >> n >> k;
        arr = vector<int>(n);
        for(int &i : arr) cin >> i;
    }

    void solve() {
        long cntSub = findSubarraySum(arr, k);
        cout << cntSub;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        SubarrayDistinctValues subarrdis;
        subarrdis.solve();
    }

    return 0;
}
