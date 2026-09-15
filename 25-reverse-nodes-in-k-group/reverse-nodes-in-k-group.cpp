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
   
    ListNode* reverseKGroup(ListNode* head, int k) {
         ListNode* ptr = head;
    for (int i = 0; i < k; i++) {
        if (!ptr)
            return head; // Return head if there are less than k nodes remaining
        ptr = ptr->next;
    }
    int count = k;
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* frwd = NULL;
    while (count && curr) {
        frwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = frwd;
        count--;
    }
    if (frwd)
        head->next = reverseKGroup(frwd, k); // Recursive call for the remaining linked list
    return prev; // Return the new head of the reversed group


        
        
    }
};