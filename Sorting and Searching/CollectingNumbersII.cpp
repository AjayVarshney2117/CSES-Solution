/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/2217
**************************************************************************/

#include <iostream>
#include <vector>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::set;
using std::swap;

class CollectingNumbersII {
    vector<int> values;
    vector<pair<int, int>> queries;

    vector<int> findQueriesAns(vector<int> &values, vector<pair<int, int>> queries) {
        int n = values.size() - 1;

        vector<int> position(n+1);
        for(int i=1 ; i<=n ; ++i) position[values[i]] = i;

        int rounds = 1;
        for(int i=1 ; i<n ; ++i) rounds += (position[i] > position[i+1]);

        vector<int> queriesAns;
        set<pair<int, int>> updatedPairs;
        for(auto &[l, r] : queries) {
            if(values[l] + 1 <= n) updatedPairs.insert({values[l], values[l]+1});
            if(values[l] - 1 >= 1) updatedPairs.insert({values[l]-1, values[l]});
            if(values[r] + 1 <= n) updatedPairs.insert({values[r], values[r]+1});
            if(values[r] - 1 >= 1) updatedPairs.insert({values[r]-1, values[r]});

            for(auto &[fir, sec] : updatedPairs) rounds -= (position[fir] > position[sec]);
            
            swap(values[l], values[r]);
            position[values[l]] = l;
            position[values[r]] = r;

            for(auto &[fir, sec] : updatedPairs) rounds += (position[fir] > position[sec]);

            queriesAns.push_back({rounds});
            updatedPairs.clear();
        }

        return queriesAns;
    }
public:
    CollectingNumbersII() {
        int n, m;
        cin >> n >> m;

        values = vector<int>(n+1);
        for(int i=1 ; i<=n ; ++i) cin >> values[i];

        queries = vector<pair<int, int>>(m);
        for(int i=0 ; i<m ; ++i) cin >> queries[i].first >> queries[i].second;
    }

    void solve() {
        vector<int> queriesRoundAns = findQueriesAns(values, queries);
        for(int ans : queriesRoundAns) cout << ans << endl;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        CollectingNumbersII nums;
        nums.solve();
    }

    return 0;
}
