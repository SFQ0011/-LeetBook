/*
4. 寻找两个正序数组的中位数
	给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
	算法的时间复杂度应该为 O(log (m+n)) 。

 

示例 1：
	输入：nums1 = [1,3], nums2 = [2]
	输出：2.00000
	解释：合并数组 = [1,2,3] ，中位数 2

示例 2：
	输入：nums1 = [1,2], nums2 = [3,4]
	输出：2.50000
	解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

 提示：
	nums1.length == m
	nums2.length == n
	0 <= m <= 1000
	0 <= n <= 1000
	1 <= m + n <= 2000
	-106 <= nums1[i], nums2[i] <= 106

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/shu-ju-jie-gou-jiao-cheng-di-6-ban-zai-xian-bian-c/d7s3fg/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	size_t l = nums1.size() + nums2.size();
	vector<int> nums(l, 0);

	std::merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums.begin());
	if ((l-1) % 2 == 0) {
		return (nums[(l - 1) / 2]);
	}
	else {
		return (nums[(l - 1) / 2] + nums[(l + 1) / 2]) / 2.0;
	}

}


int main()
{
	vector<int> nums1 = { 1, 2};
	vector<int> nums2 = { 3, 4};
	double result = findMedianSortedArrays(nums1, nums2);

	return 0;
}

