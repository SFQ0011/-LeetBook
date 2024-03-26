/*
* 5. 奇偶链表
    给定单链表的头节点 head ，将所有索引为奇数的节点和索引为偶数的节点分别组合在一起，
    然后返回重新排序的列表。第一个节点的索引被认为是 奇数 ， 第二个节点的索引为 偶数 ，以此类推。
    请注意，偶数组和奇数组内部的相对顺序应该与输入时保持一致。
    
    你必须在 O(1) 的额外空间复杂度和 O(n) 的时间复杂度下解决这个问题。

示例 1:
    输入: head = [1,2,3,4,5]
    输出: [1,3,5,2,4]
示例 2:
    输入: head = [2,1,3,5,6,4,7]
    输出: [2,3,6,7,1,5,4]
作者：LeetCode
链接：https://leetcode.cn/leetbook/read/shu-ju-jie-gou-jiao-cheng-di-6-ban-zai-xian-bian-c/d7fxgh/
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

ListNode* oddEvenList(ListNode* head) {
    // 输入： 1->2->3->4->5->6
    // 输出： 1->3->5->2->4->6

    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return head;

    ListNode/** OddList = head,*/ * OddListTail = head;
    ListNode* EvenList = head->next, *EvenListTail = EvenList;
    //ListNode* Remind = EvenList->next;

    while (EvenListTail->next) {
        OddListTail->next = EvenListTail->next;         OddListTail = OddListTail->next;
        EvenListTail->next = EvenListTail->next->next;  EvenListTail = EvenListTail->next;

        if (EvenListTail == nullptr) break;
        //Remind = EvenListTail->next;
    }
    OddListTail->next = EvenList;

    return head;
}


int main5()
{
    ListNode* head = new ListNode(1); head->next = nullptr;
    ListNode* pTail = head;

    pTail->next = new ListNode(2);    pTail = pTail->next;
    pTail->next = new ListNode(3);    pTail = pTail->next;
    pTail->next = new ListNode(4);    pTail = pTail->next;
    pTail->next = new ListNode(5);    pTail = pTail->next;
    pTail->next = new ListNode(6);    pTail = pTail->next;

    ListNode* headNode = oddEvenList(head);

    // print
    while (headNode) {
        cout << headNode->val << "->";
        headNode = headNode->next;
    }
    cout << "NULL\n";

    return 0;
}
