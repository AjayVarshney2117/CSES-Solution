/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1660
**************************************************************************/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class SubarraySumsI {
    int target;
    vector<int> arr;

    static long findCnt(vector<int> &arr, const int target) {
        const int n = arr.size();

        int l = 0, h = -1;
        long cnt = 0;
        long sum = 0;
        while(h < n) {
            if(sum <= target) {
                if(sum == target) ++cnt;

                ++h;
                sum += ((h < n) ? arr[h] : 0);
            }
            else sum -= arr[l++];
        }

        return cnt;
    }
public:
    SubarraySumsI() {
        int n;
        cin >> n >> target;
        arr = vector<int>(n);
        for(int &i : arr) cin >> i;
    }

    void solve() {
        long cntSubArraySum = findCnt(arr, target);
        cout << cntSubArraySum;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        SubarraySumsI subarr;
        subarr.solve();
    }

    return 0;
}
