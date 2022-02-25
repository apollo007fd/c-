#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1.0 / x;
        }
        long nn = (long)abs(n);  // to deal with the case: n = -2^31
        double standard = x;
        double ans = 1.0;
        while (nn) {
            if (nn & 1) {
               ans *= standard;
            }
            nn >>= 1;
            standard *= standard;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    cout << solution.myPow(3.0, 3) << endl; 
}