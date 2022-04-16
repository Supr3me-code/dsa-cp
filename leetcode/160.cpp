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