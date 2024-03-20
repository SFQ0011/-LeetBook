// https://leetcode.cn/leetbook/read/shu-ju-jie-gou-jiao-cheng-di-6-ban-zai-xian-bian-c/d73ma7/
////////////////////////////////////////////////////////////////
/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。
 

示例 1：

输入：x = 123
输出：321
示例 2：

输入：x = -123
输出：-321
示例 3：

输入：x = 120
输出：21
示例 4：

输入：x = 0
输出：0

*/


//////////////////////////////////////////////////////////////
/*
2. 加一
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。

 

示例 1：

输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。
示例 2：

输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。
示例 3：

输入：digits = [0]
输出：[1]

输入：digits = [1,9]
输出：[2,0]

提示：

1 <= digits.length <= 100
0 <= digits[i] <= 9
*/

/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]
 

提示：

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
 

进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？

*/

/*
4. 所有奇数长度子数组的和
给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。

子数组 定义为原数组中的一个连续子序列。

请你返回 arr 中 所有奇数长度子数组的和 。

 

示例 1：

输入：arr = [1,4,2,5,3]
输出：58
解释：所有奇数长度子数组和它们的和为：
[1] = 1
[4] = 4
[2] = 2
[5] = 5
[3] = 3
[1,4,2] = 7
[4,2,5] = 11
[2,5,3] = 10
[1,4,2,5,3] = 15
我们将所有值求和得到 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
示例 2：

输入：arr = [1,2]
输出：3
解释：总共只有 2 个长度为奇数的子数组，[1] 和 [2]。它们的和为 3 。
示例 3：

输入：arr = [10,11,12]
输出：66
 

提示：

1 <= arr.length <= 100
1 <= arr[i] <= 1000
*/




#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int32_t reverse(int32_t x) {
        //int32_t iRet = 0;
        //char flag = 1;

        //if ((x > pow(2, 31) - 1) || (x <= pow(-2, 31)))  return 0;

        //if (x < 0) {
        //    flag = -1;
        //    x = -x;
        //}

        //while (x) {
        //    if (iRet > (pow(2,31) - 1) / 10) {
        //        return 0;
        //    }

        //    iRet = iRet * 10;

        //    iRet += (x % 10);
        //    x = x / 10;
        //}
        //return iRet * flag;

        int32_t iRet = 0;
        char flag = 1;

        if ((x >= 0x7fffffff) || (x <= (int32_t)0x80000000))  return 0;

        if (x < 0) {
            flag = -1;
            x = -x;
        }

        while (x) {
            if (iRet > 0x7fffffff / 10) {
                return 0;
            }

            iRet = iRet * 10;

            iRet += (x % 10);
            x = x / 10;
        }
        return iRet * flag;
    }

    vector<int> plusOne(vector<int>& digits) {
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            if (*it == 9) {
                *it = 0;
                if (digits[0] % 10 == 0) {
                    digits.insert(digits.begin(), 1);
                    break;
                }
            }
            else {
                ++(*it);
                break;
            }
        }

        return digits;
    }

    vector<int> twoSum(vector<int>& nums, int target) {

        /*
            输入：nums = [3,2,7,11,15], target = 9
            输出：[1,2]
            解释：因为 nums[1] + nums[2] == 9 ，返回 [1, 2] 。

        */

        unordered_map<int, int> mHash{ {nums[0], 0} };
        for (int i = 1; i < nums.size(); i++) {
            auto it = mHash.find(target - nums[i]);
            if (it != mHash.end()) {
                return { it->second, i };
            }
            mHash[nums[i]] = i;
        }

        return {};
    }

    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        // [1, 4, 2, 5, 3]
        // 1
        // 1,4,2
        // 1,4,2,5,3
        //
        // 4
        // 4,2,5
        //
        // 2
        // 2,5,3
        // 
        // 5
        //
        //3

        for (int i = 0; i < n; i++) {
            int len = 1;
            
            while (len + i <= n) {
                // 计算 i 到 i+ len 的和
                for (int j = i; j < i + len; ++j) {
                    sum += arr[j];
                }

                len += 2;
            }
        }

        return sum;
    }

    int sumOddLengthSubarrays11(vector<int>& arr) {

        int n = arr.size();
        int sum = 0;

        // 前缀和法
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i-1];   // 预先保存 第 0 项到 第 i 项的和
        }

        for (int i = 0; i < n; i++) {
            int len = 1;

            while (len + i <= n) {
                // 计算 i 到 i+ len 的和
                sum += (prefixSum[i + len] - prefixSum[i]);

                len += 2;
            }
        }

        return sum;
    }
};


int main()
{
    Solution s;
    //int32_t a = 0x80000000, b = 123, c = 2147483647;

    //cout << s.reverse(a) << '\n' << s.reverse(b) << "\n" << s.reverse(c) << "\n";

    //vector<int> arr{ 1,2,3,5,4,5};

    //for (auto it : s.plusOne(arr)) {
    //    cout << it << " ";
    //}
    //cout << endl;

    vector<int> arr{ 1, 4, 2, 5, 3 };

    //for (auto it : s.twoSum(arr, 7)) {
    //    cout << it << " ";
    //}
    //cout << endl;

    cout << s.sumOddLengthSubarrays11(arr) << endl;

    return 0;
}
