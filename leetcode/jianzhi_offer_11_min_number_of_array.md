分析：
二分查找，转轴取middle, 转轴元素跟首or尾元素比大小？

1. 转轴跟首元素比大小，考虑到有如下情况：

1.1 转轴大于首元素, 又有两种情况:

 1.1.1 尾元素大于等于转轴（数组没有旋转） 首元素就是最小

 1.1.2 首元素大于或等于尾元素 (数组有旋转) 以转轴后一个元素为首元素，进入下一次循环

1.2 转轴小于首元素: 以转轴为尾元素进入下一次循环

1.3 转轴等于首元素, 有两种情况：

 1.3.1 首元素小于尾元素(没有旋转)，首元素就是最小

 1.3.2 首元素大于等于尾元素(有旋转)，首元素后移一位, 进入下一次循环

```
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
```

2. 转轴跟尾元素比大小，考虑到有如下情况：

2.1 转轴大于尾元素, 以转轴后一个为首元素，进入下一次循环

2.2 转轴小于尾元素，以转轴为尾元素，进入下一次循环

2.3 转轴等于尾元素，以尾元素前一个为新的尾元素，进入下一次循环

```
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int low = 0, high = numbers.size() - 1, mid;
        while( low < high) {
            mid = low + (high - low) / 2;
            if (numbers[mid] > numbers[high])
                low = mid + 1; 
            else if (numbers[mid] < numbers[high])
                high = mid;
            else
                --high;
        }
        return numbers[low];
    }
};
```

总结：

第2种方法较简单
