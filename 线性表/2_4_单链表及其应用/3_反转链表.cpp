/*
3. 反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
示例 1：
    输入：head = [1,2,3,4,5]
    输出：[5,4,3,2,1]
    
示例 2：
    输入：head = [1,2]
    输出：[2,1]
示例 3：
    输入：head = []
    输出：[]

提示：
    链表中节点的数目范围是 [0, 5000]
    -5000 <= Node.val <= 5000

进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
作者：LeetCode
链接：https://leetcode.cn/leetbook/read/shu-ju-jie-gou-jiao-cheng-di-6-ban-zai-xian-bian-c/d7bpss/
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

ListNode* reverseList1(ListNode* head) {
    ListNode* headNew   = nullptr;
    ListNode* Item  = nullptr, *ItemNew = nullptr;

    if (head) {
        headNew = new ListNode(head->val);
    }
    else {
        return head;
    }

    while (head->next) {
        Item = head->next;
        ItemNew = new ListNode(Item->val, headNew);
        headNew = ItemNew;

        head = head->next;
    }

    return headNew;
}

ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* headRemind = head->next;    // 剩余链表的头
    ListNode* headNew = head;       // 新的链表头
    ListNode* headLast = headNew;
    headNew->next = nullptr;

    while (headRemind) {
        headNew = headRemind;
        headRemind = headRemind->next;
        headNew->next = headLast;
        headLast = headNew;
    }

    return headNew;
}


int main3()
{
    ListNode* head = new ListNode(1); head->next = nullptr;
    ListNode* pTail = head;

    pTail->next = new ListNode(2);    pTail = pTail->next;
    pTail->next = new ListNode(6);    pTail = pTail->next;
    pTail->next = new ListNode(3);    pTail = pTail->next;
    pTail->next = new ListNode(4);    pTail = pTail->next;
    pTail->next = new ListNode(5);    pTail = pTail->next;
    pTail->next = new ListNode(6);    pTail = pTail->next;

    ListNode* headNode = reverseList(head);

    // print
    while (headNode) {
        cout << headNode->val << "->";
        headNode = headNode->next;
    }
    cout << "NULL\n";

    return 0;
}
