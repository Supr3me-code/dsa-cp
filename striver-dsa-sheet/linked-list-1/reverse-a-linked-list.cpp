class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head){
            ListNode* prev = head;
            if(head->next){
                ListNode* curr = head->next;
                if(head->next->next){
                    ListNode* ahead = head->next->next;
                    while(ahead){
                        curr->next = prev;
                        prev = curr;
                        curr = ahead;
                        ahead = ahead->next;
                    }
                    curr->next = prev;
                    head->next = NULL;
                    return curr;
                }else{
                    curr->next = prev;
                    prev->next = NULL;
                    return curr;
                }
            }else{
                return head;
            }
        }else{
            return NULL;
        }
    }
};