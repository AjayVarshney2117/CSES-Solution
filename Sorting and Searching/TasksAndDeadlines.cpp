/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1630
**************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

class TasksAndDeadlines {
    vector<int> durations, deadlines;

    static long long MaximumReward(vector<int> &durations, vector<int> &deadlines) {
        const int n = durations.size();

        vector<pair<int, int>> pairs(n);
        for(int i=0 ; i<n ; ++i) pairs[i] = {durations[i], deadlines[i]};
        sort(pairs.begin(), pairs.end(), cmp);

        long long f = 0, reward = 0;
        for(auto &[dur, dead] : pairs) {
            f = f + dur;
            reward += (0LL + dead - f);
        }

        return reward;
    }
public:
    TasksAndDeadlines() {
        int n;
        cin >> n;
        durations = vector<int>(n);
        deadlines = vector<int>(n);
        for(int i=0 ; i<n ; ++i) cin >> durations[i] >> deadlines[i];
    }

    void solve() {
        long long maxReward = MaximumReward(durations, deadlines);
        cout << maxReward;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        TasksAndDeadlines kitnaMila;
        kitnaMila.solve();
    }

    return 0;
}
