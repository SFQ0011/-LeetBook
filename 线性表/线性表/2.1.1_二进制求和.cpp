/*
1. 二进制求和
    给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。

示例 1：
    输入:a = "11", b = "1"
    输出："100"

示例 2：
    输入：a = "1010", b = "1011"
    输出："10101"

提示：
    1 <= a.length, b.length <= 104
    a 和 b 仅由字符 '0' 或 '1' 组成
    字符串如果不是 "0" ，就不含前导零

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/shu-ju-jie-gou-jiao-cheng-di-6-ban-zai-xian-bian-c/d73ma7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        // 获取输入字符串的长度
        size_t a_len = a.length();
        size_t b_len = b.length();

        size_t max_len = std::max(a_len, b_len);
        std::string result(max_len, '0');

        uint8_t carry = 0, a_bit = 0, b_bit = 0;

        for (size_t i = 0; i < max_len; ++i) {
            // 从后向前依次处理每一位
            a_bit = (i >= a_len) ? 0 : (a[a_len - 1 - i] - '0');
            b_bit = (i >= b_len) ? 0 : (b[b_len - 1 - i] - '0');

            if (a_bit + b_bit == 2) {
                result[max_len - 1 - i] = carry + '0';
                carry = 1;
            }
            else if (a_bit + b_bit == 1) {
                if (carry) {
                    result[max_len - 1 - i] = '0';
                }
                else {
                    result[max_len - 1 - i] = '1';
                }
            }
            else {
                result[max_len - 1 - i] = carry + '0';
                carry = 0;
            }
        }

        if (carry) {
            result.insert(result.begin(), '1');
        }

        return result;
    }
};

int main_2_1_1()
{
    Solution s;

    string a = "11", b = "1001";
    cout << s.addBinary(a, b) << "\n";

    return 0;
}

//   11
// 1001
// 1100


