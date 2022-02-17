#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //用来做递归解法, 不写了
    //bool findNumberIn2DArrayHelper(const vector<vector<int>>& matrix, int i, int j, int target) {
    //    return false; 
    //}

    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int height = matrix.size();
        int width = matrix[0].size();
        int i = 0, j = width - 1;
        while (i < height && j >= 0) {
            if (matrix[i][j] > target) {
                --j;
            } else if (matrix[i][j] < target) {
                ++i;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> vec_2d
    {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    Solution solution;
    bool ans = solution.findNumberIn2DArray(vec_2d, 9);
    cout << ans << endl;
}
