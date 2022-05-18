// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        int lengthB = 0;
        
        ListNode* lengthNodeA = headA;
        ListNode* lengthNodeB = headB;
        
        while(lengthNodeA){
            lengthA++;
            lengthNodeA = lengthNodeA->next;
        }
        while(lengthNodeB){
            lengthB++;
            lengthNodeB = lengthNodeB->next;
        }
        
        int diff = abs(lengthB - lengthA);
        if(lengthA<lengthB){
            while(diff--){
                headB = headB->next;
            }
        }else if(lengthB<lengthA){
            while(diff--){
                headA = headA->next;
            }
        }
        
        while(headA!=headB){
            headA = headA->next;
            headB = headB->next;
        }
        
        return headA;
    }
};