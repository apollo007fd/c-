#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 1) return 0;  // input error
        if (n <= 3 ) return small_number_ans[n];
        if (max_mul.size() >= n+1) return max_mul[n];
        max_mul.resize(n+1);
        for (int i = 4; i<=n; ++i) {
            max_mul[i] = max(2 * max_mul[i-2], 3 * max_mul[i-3]);
        }
        return max_mul[n];
    }
private:
    vector<int> max_mul{0, 1, 2, 3};
    vector<int> small_number_ans{0, 0, 1, 2};
};

int main() {
    Solution solution;
    cout << solution.cuttingRope(10) << endl;
}