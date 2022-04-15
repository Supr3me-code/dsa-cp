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
        
        if(!head){
            return head;
        }
        
        int length = 0;
        ListNode* lengthNode = head;
        
        while(lengthNode){
            lengthNode = lengthNode->next;
            length++;
        }
        
        int resultNode = length/2;
        
        ListNode* result = head;
        
        while(resultNode--){
            result = result->next;
        }
        
        return result;
        
    }
};