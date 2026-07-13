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
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next;

            if(fast==slow){
                return true;
            }

            if(fast->next!=NULL){
                fast = fast->next;
                slow = slow->next;

            }
        }
        return false;
    }
};