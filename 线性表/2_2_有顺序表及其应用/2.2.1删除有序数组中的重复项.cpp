/*
1. 删除有序数组中的重复项
给你一个 非严格递增排列 的数组 nums ，
请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。

考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。
nums 的其余元素与 nums 的大小不重要。返回 k 。
判题标准:

系统会用下面的代码来测试你的题解:

int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
如果所有断言都通过，那么您的题解将被 通过。

 

示例 1：
输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。

示例 2：
输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。
 

提示：
1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums 已按 非严格递增 排列

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/shu-ju-jie-gou-jiao-cheng-di-6-ban-zai-xian-bian-c/d7kc9c/
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

        unordered_set<int> numSet;
        int n = nums.size();
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (numSet.find(nums[i]) == numSet.end()) { // 不重复
                nums[count++] = nums[i];
                numSet.insert(nums[i]);
            }
        }
        return count;
    }

    int removeDuplicates1(vector<int>& nums) { // 双指针
        size_t n = nums.size();
        size_t p = 0, q = 1;

        while (q < n) {
            if (nums[p] != nums[q]) {
                if (q - p > 1) {
                    nums[p + 1] = nums[q];
                }
                p++;
            }
            q++;
        }

        return p+1;
    }



};

int main2_2_1()
{
    Solution s;

    vector<int> nums{ 0,1,2,3,4,5 }; 
    //vector<int> nums{ 0,0,1,1,1,2,2,3,3,4 };
    int n = s.removeDuplicates1(nums);
    cout << n << "\n";
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

//   11
// 1001
// 1100


