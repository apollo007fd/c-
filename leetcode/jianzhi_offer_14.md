把一段绳子尽可能地分成长度为2或3的小段，最后能得到的乘积最大。
```
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
```
f(n) = max( 2 * f(n-2), 3 * f(n-3))

max_mul存放初始值, 注意f(2) = 2, f(3) = 3

带缓存，时间复杂度o(n)或o(1), 空间复杂度o(n)
