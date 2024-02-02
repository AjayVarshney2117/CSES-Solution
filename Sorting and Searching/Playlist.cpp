/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1141
**************************************************************************/

#include <iostream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::max;
using std::map;

class Playlist {
    vector<int> songs;

    int streaming(vector<int> &songs) {
        int n = songs.size();

        int maxLen = 0;

        map<int, int> freq;
        int i = 0, j = 0;
        while(j < n) {
            ++freq[songs[j]];

            if(freq[songs[j]] > 1) {
                maxLen = max(maxLen, j - i);

                while(i < j && freq[songs[j]] > 1) {
                    --freq[songs[i]];
                    ++i;
                }
            }

            ++j;
        }

        maxLen = max(maxLen, j - i);

        return maxLen;
    }
public:
    Playlist() {
        int n;
        cin >> n;

        songs = vector<int>(n);
        for(int &song : songs) cin >> song;
    }

    void solve() {
        int unique_steams = streaming(songs);
        cout << unique_steams;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;

    while(t--) {
        Playlist songs;
        songs.solve();
    }

    return 0;
}
