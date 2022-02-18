f(0) = 0

f(1) = 1

f(2) = 1

f(n) = f(n-1) + f(n-2)

1. 递归，超时
```
class Solution {
public:
    int fib(int n) {
        if (n <= 2) {
            return initial_seq[n];
        }
        return (fib(n-1) + fib(n-2)) % 1000000007;
    }
private:
    vector<int> initial_seq {0, 1, 1};
};
```
递归会重复大量计算, o(n^2), 超时



2. 递归加暂存中间变量
```
class Solution {
public:
    int fib(int n) {
        if (n <= 2) {
            return initial_seq[n];
        }
        if (n+1 > initial_seq.size()) initial_seq.resize(n+1);
        if (initial_seq[n] == 0) initial_seq[n] = (fib(n-1) + fib(n-2)) % 1000000007;
        return initial_seq[n];
    }
private:
    vector<int> initial_seq {0, 1, 1};
};
```
省去递归产生的重复计算, 效率高, o(n), o(n)



3. 最优解法
```
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
```
n从小到大计算，只需暂存少量结果，时间复杂度跟2一样(o(n))，空间复杂度更低(o(1))
