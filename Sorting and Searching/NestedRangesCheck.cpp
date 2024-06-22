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
using std::endl;
using std::vector;
using std::pair;
using std::min;
using std::max;

struct Ranges {
    int start, end;
    int index;

    bool operator< (const Ranges &other) const {
        if(start == other.start) return end > other.end;
        return start < other.start;
    }
};

class NestedRangesCheck {
    int n;
    vector<Ranges> ranges;

    pair<vector<int>, vector<int>> findNestedRanges(vector<Ranges> &ranges) {
        const int n = ranges.size();
        sort(ranges.begin(), ranges.end());

        vector<int> are_in(n, 0), am_in(n, 0);

        int minEnd = 2e9;
        for(int i=n-1 ; i>=0 ; --i) {
            if(ranges[i].end >= minEnd) are_in[ranges[i].index] = 1;
            minEnd = min(minEnd, ranges[i].end);
        }

        int maxEnd = 0;
        for(int i=0 ; i<n ; ++i) {
            if(ranges[i].end <= maxEnd) am_in[ranges[i].index] = 1;
            maxEnd = max(maxEnd, ranges[i].end);
        }

        return {are_in, am_in};
    }
public:
    NestedRangesCheck() {
        cin >> this->n;
        this->ranges = vector<Ranges>(n);
        for(int i=0 ; i<n ; ++i) {
            cin >> ranges[i].start >> ranges[i].end;
            ranges[i].index = i;
        }
    }

    void solve() {
        auto [are_in, am_in] = findNestedRanges(ranges);

        for(int i : are_in) cout << i << ' ';
        cout << endl;
        for(int i : am_in) cout << i << ' ';
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        NestedRangesCheck somethingHappening;
        somethingHappening.solve();
    }

    return 0;
}
