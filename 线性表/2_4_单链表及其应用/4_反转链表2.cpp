/*
4. 反转链表 II
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 

示例 1：
    输入：head = [1,2,3,4,5], left = 2, right = 4
    输出：[1,4,3,2,5]
示例 2：
    输入：head = [5], left = 1, right = 1
    输出：[5]
    提示：

链表中节点数目为 n
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
 

进阶： 你可以使用一趟扫描完成反转吗？

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/shu-ju-jie-gou-jiao-cheng-di-6-ban-zai-xian-bian-c/d7jezd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    int count = right - left;
    if (count <= 0) return head;

    ListNode* Prev  = nullptr;
    ListNode* Cur   = nullptr;
    ListNode* Next  = head;

    while (left--) {
        Prev = Cur;
        Cur = Next;
        Next = Next->next;
    }

    ListNode* LastNode = Prev;
    ListNode* TailNode = Cur;

    
    while (count--) {
        Prev = Cur;
        Cur = Next;
        Next = Next->next;

        Cur->next = Prev;
    }
    if (LastNode) {
        LastNode->next = Cur;
    }
    else {
        head = Cur;
    }
    if (TailNode)
        TailNode->next = Next;

    return head;
}

int main4()
{
    ListNode* head = new ListNode(1); head->next = nullptr;
    ListNode* pTail = head;

    pTail->next = new ListNode(2);    pTail = pTail->next;
    pTail->next = new ListNode(3);    pTail = pTail->next;
    pTail->next = new ListNode(4);    pTail = pTail->next;
    pTail->next = new ListNode(5);    pTail = pTail->next;
    pTail->next = new ListNode(6);    pTail = pTail->next;

    ListNode* headNode = reverseBetween(head , 1, 4);

    // print
    while (headNode) {
        cout << headNode->val << "->";
        headNode = headNode->next;
    }
    cout << "NULL\n";

    return 0;
}
