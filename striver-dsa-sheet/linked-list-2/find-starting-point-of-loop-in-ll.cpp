// Given the head of a linked list, return the node where the cycle begins. If
// there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can
// be reached again by continuously following the next pointer. Internally, pos
// is used to denote the index of the node that tail's next pointer is connected
// to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as
// a parameter.

// Do not modify the linked list.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
   public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast) {
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }

        return NULL;
    }
};

node* detectCycle(node* head) {
    if (head == NULL || head->next == NULL) return NULL;

    node* fast = head;
    node* slow = head;
    node* entry = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            while (slow != entry) {
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }
    return NULL;
}