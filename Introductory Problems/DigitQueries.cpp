/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/2431
**************************************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::string;
using std::to_string;

#define ulli long long int

ulli pow10[20];

void Power10() {
    pow10[0] = 1;

    for(ulli i=1 ; i<19 ; ++i) {
        pow10[i] = pow10[i-1] * 10;
    }
}

class DigitQueries {
    ulli k;

    static pair<ulli, ulli> indicesWhichHasNoMeaning(ulli index) {
        ulli digitsBefore = 0, numberOfDigit = 0;
        
        for(ulli i=1 ; i<=18 ; ++i) {
            ulli digitsSoFar = digitsBefore + (pow10[i] - pow10[i-1]) * i;

            if(digitsSoFar >= index) {
                numberOfDigit = i;
                break;
            }

            digitsBefore = digitsSoFar;
        }

        return { numberOfDigit, digitsBefore };
    }

    static char digitOnIndex(const ulli index, const ulli numberOfDigit, const ulli beforeIndex) {
        ulli l = pow10[numberOfDigit - 1], h = pow10[numberOfDigit] - 1;
        ulli bestVal = -1, startPosBest = -1;

        while(l <= h) {
            ulli mid = l + ((h - l) >> 1);
            ulli startPos = beforeIndex + 1 + (mid - pow10[numberOfDigit - 1]) * numberOfDigit;

            if(startPos <= index) {
                if(mid > bestVal) {
                    bestVal = mid;
                    startPosBest = startPos;
                }
                l = mid + 1;
            }
            else h = mid - 1;
        }

        string number = to_string(bestVal);
        char digit = number[index - startPosBest];

        return digit;
    }

    static char findThatDigit(ulli index) {
        auto [numberOfDigit, beforeIndex] = indicesWhichHasNoMeaning(index);
        char digit = digitOnIndex(index, numberOfDigit, beforeIndex);
        return digit;
    }
public:
    DigitQueries() {
        cin >> k;
    }

    void solve() {
        char digit = findThatDigit(k);
        cout << digit << endl;
    }
};

int main() {
    Power10();

    int q = 1;
    cin >> q;

    while(q--) {
        DigitQueries dq;
        dq.solve();
    }

    return 0;
}
