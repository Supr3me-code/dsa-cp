class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        ListNode* lengthNode = head;
        int length = 1;
        while(lengthNode->next!=NULL){
            lengthNode = lengthNode->next;
            length++;
        }
        
        lengthNode->next = head;
        k = k%length;
        ListNode* rotate = head;
        for(int i=0;i<length-k-1;i++){
            rotate = rotate->next;
            
        }
        ListNode* last = rotate;
        rotate = last->next;
        last->next=NULL;
        
        return rotate;
    }
};