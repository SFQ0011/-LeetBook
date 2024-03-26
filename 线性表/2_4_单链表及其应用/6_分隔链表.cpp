/*
6. 分隔链表
    给你一个链表的头节点 head 和一个特定值 x ，
    请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
    你应当 保留 两个分区中每个节点的初始相对位置。

示例 1：
    输入：head = [1,4,3,2,5,2], x = 3
    输出：[1,2,2,4,3,5]
示例 2：
    输入：head = [2,1], x = 2
    输出：[1,2]

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/shu-ju-jie-gou-jiao-cheng-di-6-ban-zai-xian-bian-c/d7fj63/
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

ListNode* partition1(ListNode* head, int x) {

    if (head == nullptr || head->next == nullptr)  return head;

    // 获取与 x 相等的节点的前一个节点
    ListNode* Dummy = new ListNode(-1, head);
    ListNode* Prev1 = Dummy;
    ListNode* Item = head;

    while (Item->val < x) {
        Prev1 = Item;
        Item = Item->next;

        if (Item == nullptr) break;
    }

    if (Item == nullptr || Item->next == nullptr) 
        return head;
    
    ListNode* Node = Item->next;
    ListNode* Prev2 = Item;
    while (Node) {
        if (Node->val < x) {
            Prev1->next = Node;
            Prev2->next = Node->next;
            Node->next = Item;

            Prev1 = Prev1->next;
            Node = Prev2->next;
        }
        else {
            Prev2 = Node;
            Node = Node->next;
        }
    }

    ListNode* H = Dummy->next;
    delete Dummy;

    return H;
}

ListNode* partition(ListNode* head, int x) {
    ListNode* small = new ListNode(0);
    ListNode* smallHead = small;
    ListNode* large = new ListNode(0);
    ListNode* largeHead = large;

    while (head != nullptr) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        }
        else {
            large->next = head;
            large = large->next;
        }
        head = head->next;
    }

    large->next = nullptr;
    small->next = largeHead->next;
    delete largeHead;

    head = small->next;
    delete smallHead;
    return head;
}

int main6()
{
    ListNode* head = new ListNode(1);
    ListNode* pTail = head;

    pTail->next = new ListNode(4);    pTail = pTail->next;
    pTail->next = new ListNode(1);    pTail = pTail->next;
    pTail->next = new ListNode(3);    pTail = pTail->next;
    pTail->next = new ListNode(2);    pTail = pTail->next;
    pTail->next = new ListNode(5);    pTail = pTail->next;
    pTail->next = new ListNode(1);    pTail = pTail->next;
    pTail->next = new ListNode(4);    pTail = pTail->next;
    pTail->next = new ListNode(2);    pTail = pTail->next;

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

    headNode = partition(head, 3);

    // print
    while (headNode) {
        cout << headNode->val << "->";
        headNode = headNode->next;
    }
    cout << "NULL\n";

    return 0;
}
