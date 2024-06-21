/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1620
**************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::max_element;

class FactoryMachines {
    int n;
    long long t;
    vector<int> k;

    static bool canMake(long long time, long long &t, vector<int> &k) {
        long long cnt = 0;
        for(int i : k) {
            cnt += (time / i);
            if(cnt >= t) break;
        }

        return cnt >= t;
    }

    static long long findMinTime(vector<int> &k, long long &t) {
        long long l = 0, h = 1e18;

        while(l <= h) {
            long long mid = l + ((h - l) >> 1);

            if(canMake(mid, t, k)) {
                if(!canMake(mid-1, t, k)) return mid;
                else h = mid-1;
            }
            else l = mid+1;
        }

        return l;
    }
public:
    FactoryMachines() {
        cin >> n >> t;
        this->k = vector<int>(n);
        for(int &i : k) cin >> i;
    }

    void solve() {
        long long minTime = findMinTime(k, t);
        cout << minTime;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        FactoryMachines daftPunk;
        daftPunk.solve();
    }

    return 0;
}
