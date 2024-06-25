/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1631
**************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class ReadingBooks {
    vector<int> t;

    static long long JustReadIt(vector<int> &t) {
        const int n = t.size();
        sort(t.begin(), t.end());

        long long largest = t[n-1];
        long long sum = 0;
        for(int i=0 ; i+1<n ; ++i) sum += t[i];

        return (largest <= sum) ? (largest + sum) : (largest << 1);
    }
public:
    ReadingBooks() {
        int n;
        cin >> n;
        t = vector<int>(n);
        for(int &i : t) cin >> i;
    }

    void solve() {
        long long minTimeToRead = JustReadIt(t);
        cout << minTimeToRead;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        ReadingBooks readingTime;
        readingTime.solve();
    }

    return 0;
}
