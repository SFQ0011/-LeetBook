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
 

class Solution1 {
private:
    vector<int> nums;
public:
    Solution1(ListNode* head) {

        while (head) {
            nums.emplace_back(head->val);
            head = head->next;
        }
    }

    int getRandom() {
        return nums[rand() % (nums.size())];
    }
};

/* 蓄水池抽样 */
 class Solution {
 private:
     ListNode* head;
 public:
     Solution(ListNode* _head) {
         head = _head;
     }
     int getRandom() {
         int ans = 0, idx = 0;
         auto t = head;
         while (t != NULL) {
             idx++;
             if (rand() % idx == 0) ans = t->val;
             t = t->next;
         }
         return ans;
     }
 };


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */


int main()
{
    ListNode* head = new ListNode(1);
    ListNode* pTail = head;
    
    pTail->next = new ListNode(2);    pTail = pTail->next;
    pTail->next = new ListNode(3);    pTail = pTail->next;
    pTail->next = new ListNode(4);    pTail = pTail->next;
    pTail->next = new ListNode(5);    pTail = pTail->next;



    Solution* obj = new Solution(head);
    int param_1 = obj->getRandom();
    int param_2 = obj->getRandom();
    int param_3 = obj->getRandom();
    int param_4 = obj->getRandom();
    return 0;

}

// 写博客、技术支持
