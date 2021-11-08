/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto* ans = new ListNode;
        auto* ans_next = ans;
        ans_next->val = (l1->val + l2->val) % 10;
        int overflow = (l1->val + l2->val) / 10;
        while (l1->next != nullptr && l2->next != nullptr){
            l1 = l1->next;
            l2 = l2->next;
            ans_next->next = new ListNode;
            ans_next = ans_next->next;
            ans_next->val = (l1->val + l2->val + overflow) % 10;
            overflow = (l1->val + l2->val + overflow) / 10;
        }
        while (l1->next != nullptr){
            l1 = l1->next;
            ans_next->next = new ListNode;
            ans_next = ans_next->next;
            ans_next->val = (l1->val + overflow) % 10;
            overflow = (l1->val + overflow) / 10;
        }
        while (l2->next != nullptr){
            l2 = l2->next;
            ans_next->next = new ListNode;
            ans_next = ans_next->next;
            ans_next->val = (l2->val + overflow) % 10;
            overflow = (l2->val + overflow) / 10;
        }
        if(overflow > 0){
            ans_next->next = new ListNode;
            ans_next = ans_next->next;
            ans_next->val = overflow;
        }
        return ans;
    }
};