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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        int count = 1;
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        dummy->next = head;

        while (count < left) {
            p = p->next;
            count++;
        }

        // std::cout << p->val << std::endl;
        ListNode* left_node = p;
        ListNode* swap_node = p->next;
        p->next = nullptr;
        
        ListNode* q = swap_node;

        while (count < right) {
            q = q->next;
            count++;
        }

        ListNode* right_node = q->next;
        q->next = nullptr;

        ListNode* prev = nullptr;
        while (swap_node != nullptr) {
            ListNode* temp = swap_node->next;
            swap_node->next = prev;
            prev = swap_node;
            swap_node = temp;
        }

        left_node->next = prev;
        while (prev->next != nullptr) {
            prev = prev->next;
        }
        prev->next = right_node;


        return dummy->next;
    }
};