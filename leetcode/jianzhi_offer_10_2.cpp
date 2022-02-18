#include <iostream>
#include <vector>
using namespace std;

//  青蛙跳台阶，一次可以跳1阶，也可以跳2阶, 问跳n阶有多少种跳法
class Solution {
public:
    int numWays(int n) {
        int a = 1, b = 1, sum = 0;
        while(n-- > 0) {
            sum = (a + b) % 1000000007;
            a = b;
            b = sum;
        }
        return a;
    }
};

int main() {
    Solution solu;
    cout << solu.numWays(4);
}