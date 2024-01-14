/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1629
**************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::sort;

class MovieFestival {
    vector<pair<int, int>> movies;

    static int CountOfMovies(vector<pair<int, int>> &movies) {
        int n = movies.size();
        sort(movies.begin(), movies.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.second < b.second;
        });

        int moviesWatched = 0;
        
        int i = 0, end = 0;
        while(i < n) {
            if(end <= movies[i].first) {
                ++moviesWatched;
                end = movies[i].second;
            }
            
            ++i;
        }

        return moviesWatched;
    }
public:
    MovieFestival() {
        int n;
        cin >> n;

        movies = vector<pair<int, int>>(n);
        for(pair<int, int> &i : movies) cin >> i.first >> i.second;
    }

    void solve() {
        int cntMovies = CountOfMovies(movies);
        cout << cntMovies;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        MovieFestival bingeWatcher;
        bingeWatcher.solve();
    }

    return 0;
}
