/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/2163
**************************************************************************/
/*
    This problem have a new Data Structure and really hard to implement and understand
*/

#include <iostream>
#include <vector>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

class JosephusProblemII {
    int n, k;

    static vector<int> PlayTheGame(int n, int k) {
        vector<int> order;
        
        ordered_set nums;
        for(int i=1 ; i<=n ; ++i) nums.insert(i);

        int pos = k % n;
        while(!nums.empty()) {
            int val = *nums.find_by_order(pos);
            nums.erase(val);

            order.push_back(val);

            if(!nums.empty()) pos = (pos + k) % nums.size();
        }

        return order;
    }
public:
    JosephusProblemII() {
        cin >> n >> k;
    }

    void solve() {
        vector<int> childrenOrder = PlayTheGame(n, k);
        for(int i : childrenOrder) cout << i << " ";
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        JosephusProblemII circle;
        circle.solve();
    }

    return 0;
}
