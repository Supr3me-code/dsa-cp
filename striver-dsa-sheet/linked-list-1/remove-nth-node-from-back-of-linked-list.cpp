// Given the head of a linked list, remove the nth node from the end of the list and return its head.

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* lengthNode = head;
        int length = 0;
        while(lengthNode){
            lengthNode = lengthNode->next;
            length++;
        }
        
        if(length==n){
            head = head->next;
            return head;
        }
        
        if(length==1){
            return NULL;
        }
        
        int x = length - n - 1;
        ListNode* jump = head;
        while(x--){
            jump = jump->next;
        }
        jump->next = jump->next->next;
        
        return head;
    }
};