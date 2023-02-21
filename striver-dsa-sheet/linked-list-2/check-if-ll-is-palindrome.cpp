// Given the head of a singly linked list, return true if it is a palindrome.

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
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        int length = 0;
        ListNode* lengthNode = head;
        while (lengthNode) {
            lengthNode = lengthNode->next;
            length++;
        }
        for (int i = 0; i < length / 2; i++) {
            s.push(head->val);
            head = head->next;
        }
        if (length % 2 != 0) {
            head = head->next;
        }
        while (!s.empty() && head) {
            if (head->val != s.top()) return false;
            s.pop();
            head = head->next;
        }
        if (!s.empty() || head != NULL) {
            return false;
        }
        return true;
    }
};

bool isPalindrome(node* head) {
    vector<int> arr;
    while (head != NULL) {
        arr.push_back(head->num);
        head = head->next;
    }
    for (int i = 0; i < arr.size() / 2; i++)
        if (arr[i] != arr[arr.size() - i - 1]) return false;
    return true;
}