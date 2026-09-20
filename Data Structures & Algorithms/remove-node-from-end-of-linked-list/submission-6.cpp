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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* p = head;
        while (p != nullptr) {
            count++;
            p = p->next;
        }

        int position = count - n;
        if (position == 0) {
            return head->next;
        }


        p = head;
        while (position > 1) {
            p = p->next;
            position--;
        }
        p->next = p->next->next;

        return head;
    }
};
