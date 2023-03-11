// Given the head of a singly linked list, return the middle node of the linked
// list.

// If there are two middle nodes, return the second middle node.

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
    ListNode* middleNode(ListNode* head) {
        if (!head) {
            return head;
        }

        int length = 0;
        ListNode* lengthNode = head;

        while (lengthNode) {
            lengthNode = lengthNode->next;
            length++;
        }

        int resultNode = length / 2;

        ListNode* result = head;

        while (resultNode--) {
            result = result->next;
        }

        return result;
    }
};

ListNode* middleNode(ListNode* head) {
    int n = 0;
    ListNode* temp = head;
    while (temp) {
        n++;
        temp = temp->next;
    }

    temp = head;

    for (int i = 0; i < n / 2; i++) {
        temp = temp->next;
    }

    return temp;
}

ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) slow = slow->next, fast = fast->next->next;
    return slow;
}