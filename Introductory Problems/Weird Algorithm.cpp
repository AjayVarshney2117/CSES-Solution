#include <iostream>
#include <vector>
 
using std::cin;
using std::cout;
using std::endl;
using std::vector;
 
class WeirdAlgorithm {
    int n;
    
    static void runAlgo(long long int n) {
        while(n != 1) {
            cout << n << " ";
            
            if(n & 1) n = 3*n + 1;
            else n = (n >> 1);
        }
    }
public:
    WeirdAlgorithm () {
        int n;
        cin >> n;
        
        this->n = n;
    }
 
    void solve() {
        runAlgo(n);
        cout << 1;
    }
};
 
int main() {
    WeirdAlgorithm wa;
    wa.solve();
    
    return 0;
}
