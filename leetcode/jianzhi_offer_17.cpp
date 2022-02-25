#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    /* 简单解法：假设所有数都在int范围内
    vector<int> printNumbers(int n) {
        if (n <= 0) return {};
        int max_num = 1;
        while(n--) {
            max_num *= 10;
        }
        max_num -= 1;
        vector<int> ans(max_num, 0);
        for (int i = 1; i <= max_num; ++i) {
            ans[i-1] = i;
        }
        return ans;
    }*/
    
    // 进阶解法: 全排列
    vector<int> printNumbers(int n) {
        vector<char> nums(n, '0');
        vector<int> res;
        std::function<void(int)> fun;
        fun = [&fun, &nums, &res, n] (int x) {
            if (x == n) {
                string str(nums.begin(), nums.end());
                int n = stoi(str);
                if (n) res.push_back(n);
                return;
            }
            for(int i=0; i<10; ++i) {
                nums[x] = i + '0';
                fun(x+1);
            }
        };
        fun(0);
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> ans = solution.printNumbers(2);
    for (auto i : ans) {
        cout << i << " ";
        if (i % 30 == 0) cout << endl; }
}