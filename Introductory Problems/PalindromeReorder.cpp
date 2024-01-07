/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1755
**************************************************************************/

#include <iostream>
#include <algorithm>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::reverse;

class PalindromeReorder {
    string str;

    static unordered_map<char, int> GetFreq(const string &str) {
        unordered_map<char, int> freq;
        for(const char &c : str) ++freq[c];

        return freq;
    }

    static bool CheckPalindrome(unordered_map<char, int> &freq) {
        int oddCount = 0;
        for(const auto &[ch, fr] : freq) if(fr & 1) ++oddCount;

        return (oddCount <= 1);
    }

    static string MakePalindrome(unordered_map<char, int> &freq) {
        string pal1 = "", pal2 = "";

        char thatOddChar = 0;
        for(const auto &[ch, fr] : freq) {
            if(fr & 1) thatOddChar = ch;

            pal1 += string((fr >> 1), ch);
            pal2 += string((fr >> 1), ch);
        }

        if(thatOddChar) pal1.push_back(thatOddChar);

        reverse(pal2.begin(), pal2.end());
        pal1 += pal2;
        return pal1;
    }
public:
    PalindromeReorder() {
        cin >> str;
    }

    void solve() {
        unordered_map<char, int> freq = GetFreq(str);
        bool canBePalindrome = CheckPalindrome(freq);

        if(canBePalindrome) {
            string str = MakePalindrome(freq);
            cout << str;
        }
        else cout << "NO SOLUTION";
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        PalindromeReorder orderOrder;
        orderOrder.solve();
    }

    return 0;
}
