/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1642
**************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct ValIndPair {
    long val;
    int ind;

    bool operator< (const ValIndPair &other) {
        return val < other.val;
    }
};

class SumOfFourValues {
    int target;
    vector<int> arr;

    static vector<int> findThoseFourInd(vector<int> &arr, long target) {
        const int n = arr.size();

        vector<ValIndPair> pairs;
        for(int i=0 ; i<n ; ++i) pairs.push_back({arr[i], i+1});
        sort(pairs.begin(), pairs.end());

        for(int i=0 ; i<n ; ++i) for(int j=i+1 ; j<n ; ++j) {
            long t = target - pairs[i].val - pairs[j].val;
            int l = j+1, h = n-1;

            while(l < h) {
                long sum = pairs[l].val + pairs[h].val;

                if(sum == t) return {pairs[i].ind, pairs[j].ind, pairs[l].ind, pairs[h].ind};
                else if(sum < t) ++l;
                else --h;
            }
        }

        return {};
    }
public:
    SumOfFourValues() {
        int n;
        cin >> n >> target;
        arr = vector<int>(n);
        for(int &i : arr) cin >> i;
    }

    void solve() {
        vector<int> fourInd = findThoseFourInd(arr, target);

        if(fourInd.size()) for(int i : fourInd) cout << i << ' ';
        else cout << "IMPOSSIBLE";
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        SumOfFourValues find4Vals;
        find4Vals.solve();
    }

    return 0;
}
