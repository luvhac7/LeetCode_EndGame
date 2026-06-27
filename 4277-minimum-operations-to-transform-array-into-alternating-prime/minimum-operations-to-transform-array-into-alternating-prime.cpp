#include <vector>
using namespace std;

class Solution {
public:
    // Kept your exact prime function (fixed return type to bool)
    bool pr(int n) {
        if(n < 2) return false;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }

    // Kept your exact even function
    bool even(int n) {
        if(n % 2 == 0) return true;
        return false;
    }

    int minOperations(vector<int>& a) {
        int cnt = 0;
        for(int i = 0; i < a.size(); i++) {
            // Case 1: Even index but the number is NOT prime
            if(even(i) && !pr(a[i])) {
                int temp = a[i];
                // Keep adding 1 until it becomes prime
                while(!pr(temp)) {
                    temp++;
                    cnt++;
                }
            }
            
            // Case 2: Odd index but the number IS prime
            if(!even(i) && pr(a[i])) {
                if(a[i] == 2) {
                    cnt += 2; // 2 -> 3 (prime) -> 4 (non-prime)
                } else {
                    cnt += 1; // Any odd prime + 1 becomes an even non-prime
                }
            }
        }
        return cnt;
    }
};
