进阶解法: 全排列
```
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
```
固定最高位，对下一位进行递归，一次层层递归，递归深度为n;

nums保存一个排列的n位字母，res保存所有的排列

注意用std::function定义内部的递归函数，需要引用捕获该std::function；
