/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1163
**************************************************************************/

#include <iostream>
#include <vector>
#include <set>

#include<bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::multiset;

class TrafficLights {
    int x;
    vector<int> p;

    static vector<int> FindTrafficQueriesAns(int x, vector<int> &position) {
        set<int> trafficLights;
        trafficLights.insert(0);
        trafficLights.insert(x);

        multiset<int> distances;
        distances.insert(x);

        vector<int> queryAns;
        for(int p : position) {
            set<int>::iterator next = trafficLights.lower_bound(p);
            set<int>::iterator prev = next; --prev;

            distances.erase(distances.find(*next - *prev));
            distances.insert(p - *prev);
            distances.insert(*next - p);

            // multiset<int>::iterator last = distances.end();
            // --last;
            // queryAns.push_back(*last);
            // ---------> Above Lines also works in place of below line
            queryAns.push_back(*(--distances.end()));

            trafficLights.insert(p);
        }

        return queryAns;
    }
public:
    TrafficLights() {
        int n;
        cin >> x >> n;

        p = vector<int>(n);
        for(int &i : p) cin >> i;
    }

    void solve() {
        vector<int> trafficQueriesAns = FindTrafficQueriesAns(x, p);
        for(int queryAns : trafficQueriesAns) cout << queryAns << ' ';
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        TrafficLights street;
        street.solve();
    }

    return 0;
}
