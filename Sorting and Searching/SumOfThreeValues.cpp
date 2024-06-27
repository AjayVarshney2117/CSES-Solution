/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1641
**************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;

struct ValIndPair {
    long val;
    int ind;

    bool operator< (const ValIndPair &other) {
        return val < other.val;
    }
};

class SumOfThreeValues {
    int target;
    vector<int> arr;

    static vector<int> findThoseThreeVals(vector<int> &arr, int target) {
        const int n = arr.size();

        vector<ValIndPair> pairs;
        for(int i=0 ; i<n ; ++i) pairs.push_back({arr[i], i+1});
        sort(pairs.begin(), pairs.end());

        for(int i=0 ; i<n ; ++i) {
            int l = i+1, h = n-1;
            long t = 0L + target - pairs[i].val;

            while(l < h) {
                long sum = 0L + pairs[l].val + pairs[h].val;
                if(sum == t) return {pairs[i].ind, pairs[l].ind, pairs[h].ind};
                else if(sum < t) ++l;
                else --h;
            }
        }

        return {};
    }
public:
    SumOfThreeValues() {
        int n;
        cin >> n >> target;
        arr = vector<int>(n);
        for(int &i : arr) cin >> i;
    }

    void solve() {
        vector<int> threeVals = findThoseThreeVals(arr, target);

        if(threeVals.size()) for(int i : threeVals) cout << i << ' ';
        else cout << "IMPOSSIBLE";
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        SumOfThreeValues find3Vals;
        find3Vals.solve();
    }

    return 0;
}
