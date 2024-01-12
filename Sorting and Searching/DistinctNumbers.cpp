/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1621
**************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

class DistinctNumbers {
    vector<int> x;

    static int CountDistinctValues(vector<int> x) {
        int n = x.size();
        sort(x.begin(), x.end());

        int distinctValues = 0;

        int i = 0;
        while(i < n) {
            ++distinctValues;

            int curValue = x[i];
            while(i < n && x[i] == curValue) ++i;
        }

        return distinctValues;
    }
public:
    DistinctNumbers() {
        int n;
        cin >> n;

        x = vector<int>(n);
        for(int &i : x) cin >> i;
    }

    void solve() {
        int numberOfDistinctValues = CountDistinctValues(x);
        cout << numberOfDistinctValues;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        DistinctNumbers SabAlagAlag;
        SabAlagAlag.solve();
    }

    return 0;
}
