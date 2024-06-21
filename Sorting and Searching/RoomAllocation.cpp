/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1164
**************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::set;
using std::max;
using std::sort;

class RoomAllocation {
    int n;
    vector<int> arrival, departure;

    static int findRoomCount(vector<int> arrival, vector<int> departure) {
        const int n = arrival.size();
        sort(arrival.begin(), arrival.end());
        sort(departure.begin(), departure.end());

        int cnt = 0, maxCnt = 0;
        int i = 0, j = 0;
        while(i < n) {
            if(arrival[i] <= departure[j]) ++i, ++cnt;
            else ++j, --cnt;

            maxCnt = max(maxCnt, cnt);
        }

        return maxCnt;
    }

    static vector<int> findOrder(vector<int> &arr, vector<int> &dep, int roomCnt) {
        const int n = arr.size();

        set<int> rooms;
        for(int i=1 ; i<=roomCnt ; ++i) rooms.insert(i);

        vector<pair<int, int>> a(n), d(n);
        for(int i=0 ; i<n ; ++i) {
            a[i] = {arr[i], i};
            d[i] = {dep[i], i};
        }
        sort(a.begin(), a.end());
        sort(d.begin(), d.end());

        vector<int> allocateRoom(n, 0);
        int i = 0, j = 0;
        while(i < n) {
            if(a[i].first <= d[j].first) {
                set<int>::iterator it = rooms.lower_bound(0);
                allocateRoom[a[i++].second] = *it;
                rooms.erase(it);
            }
            else rooms.insert(allocateRoom[d[j++].second]);
        }

        return allocateRoom;
    }
public:
    RoomAllocation() {
        cin >> n;
        this->arrival = vector<int>(n);
        this->departure = vector<int>(n);
        for(int i=0 ; i<n ; ++i) cin >> arrival[i] >> departure[i];
    }

    void solve() {
        int howManyRoom = findRoomCount(arrival, departure);
        cout << howManyRoom << endl;
        vector<int> order = findOrder(arrival, departure, howManyRoom);
        for(int i : order) cout << i << ' ';
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        RoomAllocation ra;
        ra.solve();
    }

    return 0;
}
