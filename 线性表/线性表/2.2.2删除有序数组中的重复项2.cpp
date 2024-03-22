/*
2. 删除有序数组中的重复项 II
给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。

不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

 

说明：

为什么返回数值是整数，但输出的答案是数组呢？

请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
int len = removeDuplicates(nums);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
 

示例 1：

输入：nums = [1,1,1,2,2,3]
输出：5, nums = [1,1,2,2,3]
解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。 不需要考虑数组中超出新长度后面的元素。
示例 2：

输入：nums = [0,0,1,1,1,1,2,3,3]
输出：7, nums = [0,0,1,1,2,3,3]
解释：函数应返回新长度 length = 7, 并且原数组的前七个元素被修改为 0, 0, 1, 1, 2, 3, 3。不需要考虑数组中超出新长度后面的元素。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/shu-ju-jie-gou-jiao-cheng-di-6-ban-zai-xian-bian-c/d7g45i/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/



#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int removeDuplicates0(vector<int>& nums) {
        // 输入： [0,0,1,1,1,2,2,3,3,4]
        // 输出： 5, nums = [0,1,2,3,4]

        size_t n = nums.size();

        int count_same = 1;
        size_t p = 0, q = 1;
        for (p = 0, q = 1; q < n; q++) {
            if (nums[p] != nums[q]) {
                if (q - p > 1) {
                    nums[p + 1] = nums[q];
                }
                p++;
                count_same = 1;
            }
            else {
                count_same++;
                if (count_same <= 2) {
                    nums[p + 1] = nums[q];
                    p++;
                }
            }
        }

        return p + 1;
    }

    int removeDuplicates1(vector<int>& nums) {
        size_t n = nums.size();
        if (n <= 2) {
            return n;
        }

        size_t fast = 2, slow = 2;// 快慢指针
        // slow 代表 目前位置带返回的数组结果的尾指针，即当前检索的结果的有效数
        // fast 代表 当前检索到的数组下标

        for (; fast < n; fast++) {
            if (nums[fast] != nums[slow - 2])
                nums[slow++] = nums[fast];
        }

        return slow;
    }

};

int main2_2_2()
{
    Solution s;
    vector<int> nums{ 1,1,1,1,2,3,3};
    //vector<int> nums{ 0,0,1,1,1,2,2,3,3,4 };
    int n = s.removeDuplicates1(nums);
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

