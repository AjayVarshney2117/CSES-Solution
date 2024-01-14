/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1619
**************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::max;

class RestaurantCustomers {
    vector<int> arrival, leave;

    static int countMaxPeople(vector<int> &arrival, vector<int> &leave) {
        int n = arrival.size();
        sort(arrival.begin(), arrival.end());
        sort(leave.begin(), leave.end());

        int people = 0, max_people = 0;
        int i = 0, j = 0;
        while(i < n && j < n) {
            if(arrival[i] <= leave[j]) ++people, ++i;
            else --people, ++j;

            max_people = max(max_people, people);
        }

        return max_people;
    }
public:
    RestaurantCustomers() {
        int n;
        cin >> n;

        arrival = vector<int>(n), leave = vector<int>(n);
        for(int i=0 ; i<n ; ++i) cin >> arrival[i] >> leave[i];
    }

    void solve() {
        int max_people_at_a_moment = countMaxPeople(arrival, leave);
        cout << max_people_at_a_moment;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        RestaurantCustomers counter;
        counter.solve();
    }

    return 0;
}
