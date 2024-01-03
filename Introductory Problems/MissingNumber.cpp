/***************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1083
***************************************************************/

#include <iostream>
 
using std::cin;
using std::cout;
using std::endl;
 
class MissingNumber {
    long long int n;
    long long int rem_num;
public:
    MissingNumber () {
        cin >> n;
 
        rem_num = (n * (n+1)) >> 1;
        while(--n) {
            int t;
            cin >> t;
            rem_num -= t;
        }
    }
 
    void solve() {
        cout << rem_num;
    }
};
 
int main() {
    MissingNumber missyou;
    missyou.solve();
    
    return 0;
}
