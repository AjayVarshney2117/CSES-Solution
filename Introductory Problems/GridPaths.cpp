/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1625
**************************************************************************/

#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

const int GRID_SIZE = 9;
const int PATH_LEN = 48;

int const directions_x[4] = {-1, 0, 1, 0};
int const directions_y[4] = {0, 1, 0, -1};

class Grid {
public:
    int pattern[48];
    bool visited[9][9];

    static bool OnEndPoint(int i, int j) {
        return i == 7 && j == 1;
    }

    bool HaveImpossibilties(int i, int j) {
        if(visited[i][j-1] && visited[i][j+1] && !visited[i-1][j] && !visited[i+1][j]) return true;
        if(!visited[i][j-1] && !visited[i][j+1] && visited[i-1][j] && visited[i+1][j]) return true;

        return false;
    }

    Grid(string &path_pattern) {
        for(int i=0 ; i<PATH_LEN ; ++i) {
            if(path_pattern[i] == 'U') pattern[i] = 0;
            else if(path_pattern[i] == 'R') pattern[i] = 1;
            else if(path_pattern[i] == 'D') pattern[i] = 2;
            else if(path_pattern[i] == 'L') pattern[i] = 3;
            else pattern[i] = 4;
        }

        for(int i=0 ; i<GRID_SIZE ; ++i) {
            visited[0][i] = true;
            visited[8][i] = true;
            visited[i][0] = true;
            visited[i][8] = true;
        }

        for(int i=1 ; i<=7 ; ++i) for(int j=1 ; j<=7 ; ++j) visited[i][j] = false;
    }

    int MoveInTheGrid(int i, int j, int path_ind = 0) {
        if(OnEndPoint(i, j)) return path_ind == PATH_LEN;
        if(HaveImpossibilties(i, j)) return 0;
        if(path_ind == PATH_LEN) return 0;

        int ways = 0;
        visited[i][j] = true;

        if(pattern[path_ind] < 4) {
            int next_i = i + directions_x[pattern[path_ind]];
            int next_j = j + directions_y[pattern[path_ind]];

            if(!visited[next_i][next_j]) ways += MoveInTheGrid(next_i, next_j, path_ind+1);
        }
        else if(j > 2 && visited[i][j-2] && (visited[i-1][j-1] || visited[i+1][j-1]) && !visited[i][j-1])
            ways += MoveInTheGrid(i, j-1, path_ind+1);
        else if(j < 6 && visited[i][j+2] && (visited[i-1][j+1] || visited[i+1][j+1]) && !visited[i][j+1])
            ways += MoveInTheGrid(i, j+1, path_ind+1);
        else if(i > 2 && visited[i-2][j] && visited[i-1][j-1] && !visited[i-1][j])
            ways += MoveInTheGrid(i-1, j, path_ind+1);
        else for(int k=0 ; k<4 ; ++k) {
            int next_i = i + directions_x[k];
            int next_j = j + directions_y[k];

            if(!visited[next_i][next_j]) ways += MoveInTheGrid(next_i, next_j, path_ind+1);
        }

        visited[i][j] = false;

        return ways;
    }
};

class GridPaths {
    string path_pattern;

    int findNumberOfWays() {
        Grid grid(path_pattern);
        return grid.MoveInTheGrid(1, 1);
    }
public:
    GridPaths() {
        cin >> path_pattern;
    }

    void solve() {
        int number_of_ways = findNumberOfWays();
        cout << number_of_ways;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        GridPaths maze;
        maze.solve();
    }

    return 0;
}

/******************************************************************************************************************************************************************
**  SIDE NOTE For Viewers:
**  In c++, you can skip line 71 to 76, but not in Java and python as they are slower languages than C++, i tried it with out those line in C++ 
**  and that was executing and accepting as well.
**  Also, it is a very tough problems and you have think about multiple prunings for that.
**  If we go with actual simple solution which is dfs without the pruning it will take about 10 min to run every possibility as O(4^48) is the worst case scnario.
**  After pruning it is runnable in 1 sec.
******************************************************************************************************************************************************************/
