// Given the head of a singly linked list, reverse the list, and return the
// reversed list.

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (head) {
            ListNode* prev = head;
            if (head->next) {
                ListNode* curr = head->next;
                if (head->next->next) {
                    ListNode* ahead = head->next->next;
                    while (ahead) {
                        curr->next = prev;
                        prev = curr;
                        curr = ahead;
                        ahead = ahead->next;
                    }
                    curr->next = prev;
                    head->next = NULL;
                    return curr;
                } else {
                    curr->next = prev;
                    prev->next = NULL;
                    return curr;
                }
            } else {
                return head;
            }
        } else {
            return NULL;
        }
    }
};

ListNode* reverseList(ListNode* head) {
    // step 1
    ListNode* prev_p = NULL;
    ListNode* current_p = head;
    ListNode* next_p;

    // step 2
    while (current_p) {
        next_p = current_p->next;
        current_p->next = prev_p;

        prev_p = current_p;
        current_p = next_p;
    }

    head = prev_p;  // step 3
    return head;
}

ListNode* reverseList(ListNode* head) {
    ListNode* newHead = NULL;
    while (head != NULL) {
        ListNode* next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}

ListNode* reverseList(ListNode*& head) {
    if (head == NULL || head->next == NULL) return head;

    ListNode* nnode = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return nnode;
}