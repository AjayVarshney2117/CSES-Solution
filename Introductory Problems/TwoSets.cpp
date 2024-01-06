/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1092
**************************************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class TwoSets {
    int n;

    static void print_nums(int n) {
        int set1[n] = { 0 }, set2[n] = { 0 };
        int top1 = 0, top2 = 0;
        long long int sum1 = 0, sum2 = 0;

        int i = n;
        while(i) {
            if(sum1 < sum2) {
                set1[top1++] = i;
                sum1 += i + 0LL;
            }
            else {
                set2[top2++] = i;
                sum2 += i + 0LL;
            }

            i--;
        }

        cout << top1 << endl;
        for(int i=0 ; i<top1 ; ++i) cout << set1[i] << " ";
        cout << endl;

        cout << top2 << endl;
        for(int i=0 ; i<top2 ; ++i) cout << set2[i] << " ";
        cout << endl;
    }
public:
    TwoSets() {
        cin >> n;
    }

    void solve() {
        long long int sum_n_natural = ((1LL * n * (n + 1)) >> 1);

        if(sum_n_natural & 1) cout << "NO";
        else {
            cout << "YES" << endl;
            print_nums(n);
        }
    }
};

int main() {
    TwoSets sets;
    sets.solve();

    return 0;
}
