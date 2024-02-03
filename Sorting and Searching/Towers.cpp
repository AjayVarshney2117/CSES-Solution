/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1073
**************************************************************************/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Towers {
    vector<int> k;

    static int findSuitableTower(int val, vector<int> &towers) {
        if(towers.size() == 0) return -1;

        int l = 0, h = towers.size()-1;
        while(l <= h) {
            int mid = l + ((h - l) >> 1);

            if(towers[mid] > val) {
                if(mid == 0) return 0;
                else if(towers[mid-1] <= val) return mid;
                else h = mid - 1;
            }
            else l = mid + 1;
        }

        return -1;
    }

    static int findThatCubeTowerNum(vector<int> &k) {
        vector<int> towers;
        for(int i : k) {
            int ind = findSuitableTower(i, towers);
            
            if(ind != -1) towers[ind] = i;
            else towers.push_back(i);
        }

        return towers.size();
    }
public:
    Towers() {
        int n;
        cin >> n;

        k = vector<int>(n);
        for(int &i : k) cin >> i;
    }

    void solve() {
        int numberOfCubesTower = findThatCubeTowerNum(k);
        cout << numberOfCubesTower;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        Towers block;
        block.solve();
    }

    return 0;
}
