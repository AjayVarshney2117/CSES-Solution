/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1624
**************************************************************************/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

const int CHESSBOARD_SIZE = 8;

class ChessboardAndQueens {
    vector<string> chessboard;

    vector<int> row_Q_cnt, col_Q_cnt, dia_Q_cnt, antiDia_Q_cnt;

    bool canPut(int row, int col) {
        return (chessboard[row][col] == '.')
            && (!row_Q_cnt[row])
            && (!col_Q_cnt[col])
            && (!dia_Q_cnt[CHESSBOARD_SIZE + row - col])
            && (!antiDia_Q_cnt[row + col]);
    }

    int findHowMany(int row = 0) {
        if(row == CHESSBOARD_SIZE) return 1;

        int possibilities = 0;
        for(int col=0 ; col<CHESSBOARD_SIZE ; ++col) if(canPut(row, col)) {
            chessboard[row][col] = 'Q';
            ++row_Q_cnt[row];
            ++col_Q_cnt[col];
            ++dia_Q_cnt[CHESSBOARD_SIZE + row - col];
            ++antiDia_Q_cnt[row + col];

            possibilities += findHowMany(row+1);

            --antiDia_Q_cnt[row + col];
            --dia_Q_cnt[CHESSBOARD_SIZE + row - col];
            --col_Q_cnt[col];
            --row_Q_cnt[row];
            chessboard[row][col] = '.';
        }

        return possibilities;
    }
public:
    ChessboardAndQueens() {
        chessboard = vector<string>(CHESSBOARD_SIZE);
        for(string &row : chessboard) cin >> row;

        row_Q_cnt = vector<int>(CHESSBOARD_SIZE, 0);
        col_Q_cnt = vector<int>(CHESSBOARD_SIZE, 0);
        dia_Q_cnt = vector<int>((CHESSBOARD_SIZE << 1), 0);
        antiDia_Q_cnt = vector<int>((CHESSBOARD_SIZE << 1), 0);
    }

    void solve() {
        int totalWays = findHowMany();
        cout << totalWays;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        ChessboardAndQueens wifu;
        wifu.solve();
    }

    return 0;
}
