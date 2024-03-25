/*
你可以选择使用单链表或者双链表，设计并实现自己的链表。
单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针 / 引用。
如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

实现 MyLinkedList 类：

MyLinkedList() 初始化 MyLinkedList 对象。
int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 - 1 。
void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。

作者：LeetCode
链接：https ://leetcode.cn/leetbook/read/shu-ju-jie-gou-jiao-cheng-di-6-ban-zai-xian-bian-c/d74ujv/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>

#include <vector>
#include <string>

#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() :val(0), next(nullptr) {}
    ListNode(int v) :val(v), next(nullptr) {}
    ListNode(int v, ListNode* n) :val(v), next(n) {}
};


class MyLinkedList {
private:
    int count = 0;// 节点数量
    ListNode* head = nullptr;   // 单链表的头节点
public:
    MyLinkedList() {
        head = new ListNode();
    }

    ~MyLinkedList() {
        // 释放内存
        ListNode* pDel = head;
        while (pDel) {
            head = head->next;
            delete pDel;
            pDel = head;
        }
    }

    int getcount() { return count; }

    int get(int index) {
        //assert((index < count) && (index > 0));
        if (index < 0 || index >= count) return -1;
        

        ListNode* p = head->next;

        while (index>0) {
            p = p->next;
            --index;
        }
        return p->val;
    }

    void addAtHead(int val) {
        ListNode* item = new ListNode(val);

        ListNode* it = head->next;
        head->next = item;
        item->next = it;

        count++;
    }

    void addAtTail(int val) {
        ListNode* tail = head;

        while (tail->next != nullptr)
            tail = tail->next;

        tail->next = new ListNode(val);
        count++;
    }

    void addAtIndex(int index, int val) {
        //assert((index < count) && (index > 0));
        if ((index > count) || (index < 0)) return;

        ListNode* pLeft = head;
        ListNode* pRight = nullptr;
        while (index > 0) {
            pLeft = pLeft->next;
            --index;
        }
        pRight = pLeft->next;
        pLeft->next = new ListNode(val);
        pLeft->next->next = pRight;
        count++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= count) return;

        ListNode* pLeft = head;
        ListNode* pDel = nullptr;

        while (index > 0) {
            pLeft = pLeft->next;
            --index;
        }

        if (pLeft != nullptr) {
            pDel = pLeft->next;
            pLeft->next = pDel->next;
        }

        delete pDel;
        count--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */


int main_1()
{
    MyLinkedList myList;
    myList.addAtHead(7);        //7
    myList.addAtHead(2);        //2->7
    myList.addAtHead(1);        //1->2->7
    myList.addAtIndex(3,0);     //1->2->7->0
    //myList.deleteAtIndex(2);    //1->2->0
    //myList.addAtHead(6);        //6->1->2->0
    //myList.addAtTail(4);        //6->1->2->0->4
    //myList.get(4);
    //myList.addAtHead(4);
    //myList.addAtIndex(5,0);
    //myList.addAtHead(6);

    for (int i = 0; i < myList.getcount(); i++) {
        cout << myList.get(i) << " -> ";
    }
    cout << "-> NULL \n";

    return 0;

}

// 写博客、技术支持
