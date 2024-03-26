/*
7. 两两交换链表中的节点
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

示例 1：
    输入：head = [1,2,3,4]
    输出：[2,1,4,3]
示例 2：
    输入：head = []
    输出：[]
示例 3：
    输入：head = [1]
    输出：[1]

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/shu-ju-jie-gou-jiao-cheng-di-6-ban-zai-xian-bian-c/dlhyqm/
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

ListNode* swapPairs(ListNode* head) {
    // 1->2->3->4->5->6->7
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* Dummy = new ListNode(0, head);
    ListNode* p1Prev = Dummy;
    ListNode* p1 = head, * p2 = head->next;
    ListNode* tail = nullptr;

    while (p2 != nullptr) {
        p1Prev->next = p2;
        tail = p2->next;
        p2->next = p1;
        p1->next = tail;

        if (tail == nullptr) break;

        p1Prev = p1;
        p1 = tail;
        p2 = p1->next;
    }

    head = Dummy->next; 
    delete Dummy;

    return head;
}

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* pTail = head;

    pTail->next = new ListNode(2);    pTail = pTail->next;
    pTail->next = new ListNode(3);    pTail = pTail->next;
    pTail->next = new ListNode(4);    pTail = pTail->next;
    //pTail->next = new ListNode(5);    pTail = pTail->next;
    //pTail->next = new ListNode(6);    pTail = pTail->next;
    //pTail->next = new ListNode(7);    pTail = pTail->next;
    //pTail->next = new ListNode(8);    pTail = pTail->next;
    //pTail->next = new ListNode(9);    pTail = pTail->next;

    //ListNode* head = new ListNode(2);
    //ListNode* pTail = head;

    //pTail->next = new ListNode(1);    pTail = pTail->next;

    ListNode* headNode = head;
    // print
    while (headNode) {
        cout << headNode->val << "->";
        headNode = headNode->next;
    }
    cout << "NULL\n";

    headNode = swapPairs(head);

    // print
    while (headNode) {
        cout << headNode->val << "->";
        headNode = headNode->next;
    }
    cout << "NULL\n";

    return 0;
}
