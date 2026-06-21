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
            p = p->next;
            count++;
        }

        int nth = count - n;
        // std::cout << nth << std::endl;
        if (nth == 0) {
            head = head->next;
            return head;
        }
        p = head;
        count = 1;
        while (count < nth) {
            p = p->next;
            count++;
        }

        p->next = p->next->next;
        return head;

    }
};
