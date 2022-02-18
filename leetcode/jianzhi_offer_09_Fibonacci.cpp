#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1, sum = 0;
        while(n-- > 0) {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return a;
    }
};

int main() {
    Solution solution;
    int n = 3;
    cout << solution.fib(n) << endl; 
}