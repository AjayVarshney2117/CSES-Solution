/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1622
**************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::swap;
using std::sort;

class CreatingStrings {
    string str;
    int n;

    vector<string> perms;

    void permuting(int ind) {
        if(ind + 1 == n) {
            perms.push_back(str);
            return;
        }

        int freq[26] = { 0 };
        for(int i=ind ; i<n ; ++i) {
            int index = str[i] - 'a';

            if(!freq[index]) {          // this line is equivalent to "freq[index] == 0"
                swap(str[ind], str[i]);
                permuting(ind+1);
                swap(str[ind], str[i]);
            }

            ++freq[index];
        }
    }
public:
    CreatingStrings() {
        cin >> str;
        this->n = str.size();
    }

    void solve() {
        permuting(0);
        sort(perms.begin(), perms.end());

        cout << perms.size() << endl;
        for(const string &perm : perms) cout << perm << endl;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        CreatingStrings cs;
        cs.solve();
    }

    return 0;
}
