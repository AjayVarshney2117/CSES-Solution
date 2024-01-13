/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1090
**************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;

class FerrisWheel {
    int x;
    vector<int> p;

    int CountGondolas(vector<int> &p , int x) {
        sort(p.begin(), p.end());

        int count = 0;

        int i = 0, j = p.size()-1;
        while(i < j) {
            ++count;

            if(0L + p[i] + p[j] <= x) ++i, --j;
            else --j;
        }

        count += (i == j);

        return count;
    }
public:
    FerrisWheel() {
        int n;
        cin >> n >> x;

        p = vector<int>(n);
        for(int &i : p) cin >> i;
    }

    void solve() {
        int no_of_gondolas = CountGondolas(p, x);
        cout << no_of_gondolas;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        // FUN FACT: Gondola is the lift which is attach to Ferris Wheel where the human is sitting.

        FerrisWheel gondola;
        gondola.solve();
    }

    return 0;
}
