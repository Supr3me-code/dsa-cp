// Given the head of a linked list, rotate the list to the right by k places.

class Solution {
   public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        ListNode* lengthNode = head;
        int length = 1;
        while (lengthNode->next != NULL) {
            lengthNode = lengthNode->next;
            length++;
        }

        lengthNode->next = head;
        k = k % length;
        ListNode* rotate = head;
        for (int i = 0; i < length - k - 1; i++) {
            rotate = rotate->next;
        }
        ListNode* last = rotate;
        rotate = last->next;
        last->next = NULL;

        return rotate;
    }
};

node* rotateRight(node* head, int k) {
    if (head == NULL || head->next == NULL) return head;
    for (int i = 0; i < k; i++) {
        node* temp = head;
        while (temp->next->next != NULL) temp = temp->next;
        node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}