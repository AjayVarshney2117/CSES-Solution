/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/2205
**************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::reverse;
using std::vector;

void operator += (vector<string> &self, const vector<string> &other) {
    for(const string &i : other) self.push_back(i);
}

class GrayCode {
    int n;

    static vector<string> appendZeros(vector<string> &grays) {
        vector<string> zeros = grays;
        for(string &bits : zeros) bits = '0' + bits;

        return zeros;
    }

    static vector<string> appendOnes(vector<string> &grays) {
        vector<string> ones = grays;
        reverse(ones.begin(), ones.end());
        for(string &bits : ones) bits = '1' + bits;

        return ones;
    }

    static vector<string> makeGrayCode(int n) {
        vector<string> grays = {"0", "1"};

        for(int i=2 ; i<=n ; ++i) {
            vector<string> zeros = appendZeros(grays);
            vector<string> ones = appendOnes(grays);

            grays = zeros;
            grays += ones;
        }

        return grays;
    }
public:
    GrayCode() {
        cin >> n;
    }

    void solve() {
        vector<string> grayCode = makeGrayCode(n);

        for(string code : grayCode) cout << code << endl;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        GrayCode codeCodeCode;
        codeCodeCode.solve();
    }

    return 0;
}
