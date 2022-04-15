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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* l1_1 = l1;
        ListNode* l2_1 = l2;
        
        while(l1_1 && l2_1){
            l1_1 = l1_1->next;
            l2_1 = l2_1->next;
        }
        
        ListNode* result;
        if(l1_1) result = l1;
        else result = l2;
        ListNode* totalSum = result;
        ListNode* bruh;
        int sum;
        while(l1 && l2){
            sum = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
            sum>9 ? carry=1 : carry=0;
            result->val = sum%10;
            if(result->next==NULL) bruh = result;
            result = result->next;
        }
        
        while(l1){
            sum = l1->val + carry;
            sum>9 ? carry=1 : carry=0;
            result->val = sum%10;
            if(result->next==NULL) bruh = result;
            result = result->next;
            l1 = l1->next;
        }
        
        while(l2){
            sum = l2->val + carry;
            sum>9 ? carry=1 : carry=0;
            result->val = sum%10;
            if(result->next==NULL) bruh = result;
            result = result->next;
            l2 = l2->next;
        }
        
        if(carry){
            ListNode* last = new ListNode(1);
            bruh->next = last;
        }
        
        return totalSum;
    }
};

/*
class Solution {
public:
      ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p= new ListNode();
        ListNode* head = p;
        int carry=0;
        
        while(l1 || l2 || carry)
        {
            // checking for which of the two nodes are exist 
            if(l1) carry+= l1->val , l1= l1->next;
            if(l2) carry+= l2->val, l2= l2->next;
            
            // now adding operation in node
            // I can add only single value in a node
            p->next= new ListNode(carry% 10);
            
            carry/=10;
            p=p->next;
        }
        return head->next;
    }
};
*/