/**************************************************************************
Author : Ajay Varshney
GitHub : https://github.com/AjayVarshney2117/
Code written in C++

Question Link : https://cses.fi/problemset/task/1091
**************************************************************************/

#include <iostream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;

class ConcertTickets {
    vector<int> h, t;

    static vector<int> FindPrices(vector<int> &h, vector<int> &t) {
        map<int, int> h_map;
        for(int &i : h) ++h_map[i];

        vector<int> tickets;
        for(int &i : t) {
            map<int, int>::iterator ticket_it = h_map.upper_bound(i);

            if(ticket_it != h_map.begin()) {
                --ticket_it;
                tickets.push_back(ticket_it->first);
                
                
                --(ticket_it->second);
                if(!(ticket_it->second)) h_map.erase(ticket_it);
            }
            else tickets.push_back(-1);
        }

        return tickets;
    }
public:
    ConcertTickets() {
        int n, m;
        cin >> n >> m;

        h = vector<int>(n);
        for(int &i : h) cin >> i;

        t = vector<int>(m);
        for(int &i : t) cin >> i;
    }

    void solve() {
        vector<int> prices_of_tickets = FindPrices(h, t);
        for(int &i : prices_of_tickets) cout << i << endl;
    }
};

int main() {
    int t = 1;
    // cin >> t;

    while(t--) {
        ConcertTickets counter;
        counter.solve();
    }

    return 0;
}
