#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::max;

class Repetitions {
    string dna;
public:
    Repetitions () {
        cin >> dna;
    }

    void solve() {
        int n = dna.size();

        int max_len = 0;

        int i = 0;
        while(i < n) {
            char c = dna[i];
            int len = 0;
            while(i<n && dna[i] == c) ++i, ++len;

            max_len = max(max_len, len);
        }

        cout << max_len;
    }
};

int main() {
    Repetitions just_beat_it;
    just_beat_it.solve();
    
    return 0;
}
