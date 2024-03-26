/*
1. 移除链表元素
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

示例 1：
	输入：head = [1,2,6,3,4,5,6], val = 6
	输出：[1,2,3,4,5]
示例 2：
	输入：head = [], val = 1
	输出：[]
示例 3：
	输入：head = [7,7,7,7], val = 7
	输出：[]
提示：
	列表中的节点数目在范围 [0, 104] 内
	1 <= Node.val <= 50
	0 <= val <= 50
*/

#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//
// ListNode   :
//              1 -> NULL
//              /     / 
//            left  Node
// 
//      1 -> 6 -> 3 -> 4 -> NULL
//      /   / 
//  left  Node
//      1 -> 3 -> 4 -> NULL
//      /   / 
//  left  Node
// 
// 
//      7 -> 7 -> 7 -> NULL
//      /   / 
//  left  Node



ListNode* removeElements(ListNode* head, int val) {
    ListNode* pNodeLeft = head;
    ListNode* pNode = nullptr;
    
    if (head == nullptr) return head;
    pNode = pNodeLeft->next;
    if ((pNode == nullptr) && (pNodeLeft->val == val)) {
        delete pNodeLeft;
        return nullptr;
    }

    ListNode* pNodeEq = nullptr;

    while (pNode)
    {
        if (pNode->val == val) {
            pNodeEq = pNode;
            if (pNodeEq == head) {
                head = head->next;
            }

            pNodeLeft->next = pNode->next;
            pNode = pNode->next;
            delete pNodeEq;
        }
        else {
            pNodeLeft = pNode;
            pNode = pNode->next;
        }
    }

    if (head->val == val) {
        pNodeEq = head;
        head = head->next;
        delete pNodeEq;
    }


    return head;
}

int main1()
{
    //ListNode* head = new ListNode(1); head->next = nullptr;
    //ListNode* pTail = head;

    //pTail->next = new ListNode(2);    pTail = pTail->next;
    //pTail->next = new ListNode(6);    pTail = pTail->next;
    //pTail->next = new ListNode(3);    pTail = pTail->next;
    //pTail->next = new ListNode(4);    pTail = pTail->next;
    //pTail->next = new ListNode(5);    pTail = pTail->next;
    //pTail->next = new ListNode(6);    pTail = pTail->next;

    ListNode* head = new ListNode(7); head->next = nullptr;
    ListNode* pTail = head;

    pTail->next = new ListNode(7);    pTail = pTail->next;
    pTail->next = new ListNode(7);    pTail = pTail->next;
    pTail->next = new ListNode(7);    pTail = pTail->next;

    ListNode* headNode = removeElements(head, 7);

    // print
    while (headNode) {
        cout << headNode->val << "->";
        headNode = headNode->next;
    }
    cout << "NULL\n";

    return 0;
}
