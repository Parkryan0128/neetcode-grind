struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyCircularQueue {
public:
    int size;
    int count;
    ListNode* dummy_head;
    ListNode* dummy_tail;

    MyCircularQueue(int k) {
        size = k;
        count = 0;
        dummy_head = new ListNode(0);
        dummy_tail = new ListNode(0);
        dummy_head->next = dummy_tail;
        dummy_tail->next = dummy_head;
    }
    
    bool enQueue(int value) {
        if (size == count) {
            return false;
        }

        ListNode* p = dummy_head;
        while (p->next != dummy_tail) {
            p = p->next;
        }
        ListNode* n = new ListNode(value);
        p->next = n;
        n->next = dummy_tail;
        count++;
        return true;
    }
    
    bool deQueue() {
        if (dummy_head->next != dummy_tail) {
            ListNode* temp = dummy_head->next;
            dummy_head->next = temp->next;
            delete temp;
            count--;
            return true;
        }
        return false;
    }
    
    int Front() {
        if (dummy_head->next != dummy_tail) {
            return dummy_head->next->val;
        }
        return -1;
    }
    
    int Rear() {
        if (dummy_head->next == dummy_tail) {
            return -1;
        }
        ListNode* p = dummy_head;
        while (p->next != dummy_tail) {
            p = p->next;
        }
        return p->val;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */