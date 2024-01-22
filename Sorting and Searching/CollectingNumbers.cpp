/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/2216
**************************************************************************/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class CollectingNumbers {
    vector<int> x;

    static int FindNumberOfRound(vector<int> &x) {
        int n = x.size();

        vector<int> x_ind(n+1);
        for(int i=0 ; i<n ; ++i) x_ind[x[i]] = i;

        int count = 1;
        for(int i=1 ; i<=n ; ++i) if(x_ind[i] < x_ind[i-1]) ++count;

        return count;
    }
public:
    CollectingNumbers() {
        int n;
        cin >> n;

        x = vector<int>(n);
        for(int &i : x) cin >> i;
    }

    void solve() {
        int numberOfRound = FindNumberOfRound(x);
        cout << numberOfRound;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        CollectingNumbers nums;
        nums.solve();
    }

    return 0;
}
