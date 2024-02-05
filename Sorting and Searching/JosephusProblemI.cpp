/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/2162
**************************************************************************/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class JosephusProblemI {
    int n;

    static vector<int> PlayTheGame(int n) {
        vector<int> child;
        for(int i=1 ; i<=n ; ++i) child.push_back(i);

        vector<int> order;
        while(child.size() > 1) {
            vector<int> survivors;
            for(int i=0 ; i<child.size() ; ++i) (i & 1 ? order : survivors).push_back(child[i]);
            /*
            -----> Above code can also be written as:
            -----> Don't fear with these codes "\''//"
            -----> Belive me that works too..."

            for(int i=0 ; i<child.size() ; ++i) {
                if(i & 2 == 1) order.push_back(child[i]);
                else survivors.push_back(child[i]);
            }
            */

            if((child.size() & 1) == 0) child = survivors;
            else {
                int starter = survivors.back();
                survivors.pop_back();

                child.clear();
                child.push_back(starter);
                for(int i : survivors) child.push_back(i);
            }
        }
        order.push_back(child[0]);
        
        return order;
    }
public:
    JosephusProblemI() {
        cin >> n;
    }

    void solve() {
        vector<int> childrenOrder = PlayTheGame(n);
        for(int i : childrenOrder) cout << i << " ";
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        JosephusProblemI circle;
        circle.solve();
    }

    return 0;
}
