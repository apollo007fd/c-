#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<bool> flags(nums.size(), false);
        for(auto& i : nums) {
            if (flags[i] == true)
                return i;
            flags[i] = true;
        }
        return -1;
    }
};

int main() {
    vector<int> vecs {2, 3, 1, 0, 2, 5, 3};
    Solution solu;
    int ans = solu.findRepeatNumber(vecs);
    cout << ans << endl;
    return 0;
}