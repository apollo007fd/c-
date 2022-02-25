1. c++ uint32_t header file: stdint.h
```
#include <stdint.h>
```

2. 解法1: 定义一个uint32_t的变量flag，初值设为1, 用flag循环左移跟输入值做位与

3. 解法2: 对于一个uint32_t的非零变量n, 把n的二进制表示的最右边的非零的那一位变成0的快捷做法：n & (n-1)

比如: n = 10, 二进制表示为n = 0...1010, n-1 = 0...1001, n&(n-1) = 0...1000
```
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int n_bit = 0;
        while(n)
        {   
            n_bit += 1;
            n = n & (n-1);
        }   
        return n_bit;
kkkk   }   
};
```