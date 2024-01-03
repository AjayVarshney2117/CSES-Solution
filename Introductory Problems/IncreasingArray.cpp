/***************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1094
***************************************************************/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class IncreasingArray {
    vector<int> arr;

    static long long int MinMoves(vector<int> arr) {
        int n = arr.size();
        long long int moves = 0;

        for(int i=1 ; i<n ; ++i) if(arr[i-1] > arr[i]) {
            moves += 0LL + arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }

        return moves;
    }
public:
    IncreasingArray () {
        int n;
        cin >> n;

        arr = vector<int>(n);
        for(int &i : arr) cin >> i;
    }

    void solve() {
        cout << MinMoves(arr);
    }
};

int main() {
    IncreasingArray increaseArr;
    increaseArr.solve();
    
    return 0;
}
