// 旋转数组的最小数
#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0, high = numbers.size() - 1, mid;
        while( low < high) {
            mid = low + (high - low) / 2;
            if (numbers[mid] > numbers[low]) {
                if (numbers[high] <= numbers[low]) {
                    low = mid+1;
                } else if (numbers[high] >= numbers[mid]) {
                    high = low;
                }
            }
            else if (numbers[mid] < numbers[low])
                high = mid;
            else {
                if (numbers[low] < numbers[high])
                    high = low;
                else
                    ++low;
                
            }
        }
        return numbers[low];
    }
};

int main() {
    vector<int> numbers {1, 3, 3};
    Solution solution;
    cout << solution.minArray(numbers) << endl;
}