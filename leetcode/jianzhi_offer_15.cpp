#include <iostream>
#include <stdint.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t flag = 1;
        int cnt = 0;
        for (int i = 0; i < 31; ++i) {
            if (n & flag)
                ++cnt;
            flag <<= 1;
        }
        if (n & flag) ++cnt;
        return cnt;
   }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.hammingWeight(127) << endl;
    return 0;
}
