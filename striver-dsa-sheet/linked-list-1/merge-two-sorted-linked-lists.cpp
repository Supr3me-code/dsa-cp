// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        
        ListNode* ptr = list1;
        if(list1->val<=list2->val){
            list1 = list1->next;
        }else{
            ptr = list2;
            list2 = list2->next;
        }
        
        ListNode* x = ptr;
        
        while(list1 && list2){
            if(list1->val<=list2->val){
                x->next = list1;
                list1 = list1->next;
            }else{
                x->next = list2;
                list2 = list2->next;
            }
            x = x->next;
        }
        
        if(!list1){
            x->next = list2;
        }else{
            x->next = list1;
        }
        
        return ptr;
    }
};