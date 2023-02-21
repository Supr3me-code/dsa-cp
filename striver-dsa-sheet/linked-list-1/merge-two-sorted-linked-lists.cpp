// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing
// together the nodes of the first two lists.

// Return the head of the merged linked list.

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }

        ListNode* ptr = list1;
        if (list1->val <= list2->val) {
            list1 = list1->next;
        } else {
            ptr = list2;
            list2 = list2->next;
        }

        ListNode* x = ptr;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                x->next = list1;
                list1 = list1->next;
            } else {
                x->next = list2;
                list2 = list2->next;
            }
            x = x->next;
        }

        if (!list1) {
            x->next = list2;
        } else {
            x->next = list1;
        }

        return ptr;
    }
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // when list1 is empty then
    // our output will be same as list2
    if (l1 == NULL) return l2;

    // when list2 is empty then our output
    // will be same as list1
    if (l2 == NULL) return l1;

    // pointing l1 and l2 to smallest and greatest one
    if (l1->val > l2->val) std::swap(l1, l2);

    // act as head of resultant merged list
    ListNode* res = l1;

    while (l1 != NULL && l2 != NULL) {
        ListNode* temp = NULL;

        while (l1 != NULL && l1->val <= l2->val) {
            temp = l1;  // storing last sorted node
            l1 = l1->next;
        }

        // link previous sorted node with
        // next larger node in list2
        temp->next = l2;
        std::swap(l1, l2);
    }

    return res;
}