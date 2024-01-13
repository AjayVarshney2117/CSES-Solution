/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1084
**************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::sort;

class Apartments {
    int k;
    vector<int> a, b;

    static int HowManyApartmentsCanBeOccupied(int k, vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        map<long long int, int> b_map;
        for(long long int i : b) ++b_map[i];

        int occupiedApartmentCount = 0;
        for(int &i : a) {
            long long int low = 0LL + i - k, high = 0LL + i + k;
            map<long long int, int>::iterator apart_it = b_map.lower_bound(low);

            if(apart_it != b_map.end() && apart_it->first <= high) {
                --(apart_it->second);
                if(apart_it->second == 0) b_map.erase(apart_it);

                ++occupiedApartmentCount;
            }
        }

        return occupiedApartmentCount;
    }
public:
    Apartments() {
        int n, m;
        cin >> n >> m >> this->k;
        
        this->a = vector<int>(n);
        for(int &i : a) cin >> i;

        this->b = vector<int>(m);
        for(int &i : b) cin >> i;
    }

    void solve() {
        int no_of_occupied_apartments = HowManyApartmentsCanBeOccupied(k, a, b);
        cout << no_of_occupied_apartments;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        Apartments floors;
        floors.solve();
    }

    return 0;
}
