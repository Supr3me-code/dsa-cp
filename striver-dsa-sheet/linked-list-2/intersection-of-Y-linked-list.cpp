// Given the heads of two singly linked-lists headA and headB, return the node
// at which the two lists intersect. If the two linked lists have no
// intersection at all, return null.

// For example, the following two linked lists begin to intersect at node c1:

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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lengthA = 0;
        int lengthB = 0;

        ListNode* lengthNodeA = headA;
        ListNode* lengthNodeB = headB;

        while (lengthNodeA) {
            lengthA++;
            lengthNodeA = lengthNodeA->next;
        }
        while (lengthNodeB) {
            lengthB++;
            lengthNodeB = lengthNodeB->next;
        }

        int diff = abs(lengthB - lengthA);
        if (lengthA < lengthB) {
            while (diff--) {
                headB = headB->next;
            }
        } else if (lengthB < lengthA) {
            while (diff--) {
                headA = headA->next;
            }
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};

node* intersectionPresent(node* head1, node* head2) {
    while (head2 != NULL) {
        node* temp = head1;
        while (temp != NULL) {
            // if both nodes are same
            if (temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    // intersection is not present between the lists return null
    return NULL;
}

node* intersectionPresent(node* head1, node* head2) {
    unordered_set<node*> st;
    while (head1 != NULL) {
        st.insert(head1);
        head1 = head1->next;
    }
    while (head2 != NULL) {
        if (st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;
}

int getDifference(node* head1, node* head2) {
    int len1 = 0, len2 = 0;
    while (head1 != NULL || head2 != NULL) {
        if (head1 != NULL) {
            ++len1;
            head1 = head1->next;
        }
        if (head2 != NULL) {
            ++len2;
            head2 = head2->next;
        }
    }
    return len1 - len2;  // if difference is neg-> length of list2 > length of
                         // list1 else vice-versa
}

node* intersectionPresent(node* head1, node* head2) {
    int diff = getDifference(head1, head2);
    if (diff < 0)
        while (diff++ != 0) head2 = head2->next;
    else
        while (diff-- != 0) head1 = head1->next;
    while (head1 != NULL) {
        if (head1 == head2) return head1;
        head2 = head2->next;
        head1 = head1->next;
    }
    return head1;
}

node* intersectionPresent(node* head1, node* head2) {
    node* d1 = head1;
    node* d2 = head2;

    while (d1 != d2) {
        d1 = d1 == NULL ? head2 : d1->next;
        d2 = d2 == NULL ? head1 : d2->next;
    }

    return d1;
}