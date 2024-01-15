/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1640
**************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::sort;

class SumOfTwoValues {
    int x;
    vector<int> a;

    static vector<int> FindThoseTwoValues(vector<int> &a, int x) {
        int n = a.size();

        vector<pair<int, int>> a_ind;
        for(int i=0 ; i<n ; ++i) a_ind.push_back({ a[i], i+1 });

        sort(a_ind.begin(), a_ind.end());

        int i = 0, j = n-1;
        while(i < j) {
            int sum = a_ind[i].first + a_ind[j].first;

            if(sum == x) return { a_ind[i].second, a_ind[j].second };
            else if(sum < x) ++i;
            else --j;
        }

        return {};
    }
public:
    SumOfTwoValues() {
        int n;
        cin >> n >> x;

        a = vector<int>(n);
        for(int &i : a) cin >> i;
    }

    void solve() {
        vector<int> xSum_two_values = FindThoseTwoValues(a, x);
        if(xSum_two_values.size()) cout << xSum_two_values[0] << " " << xSum_two_values[1];
        else cout << "IMPOSSIBLE";
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        SumOfTwoValues sum;
        sum.solve();
    }

    return 0;
}
