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

        ListNode* temp = head;
        int count = 0;
        while(temp != NULL && count < k){
            temp = temp->next;
            count++;
        }

        if(count < k)
            return head;

        ListNode* curr = head;
        ListNode* pre = NULL;
        ListNode* nex = NULL;
        count = 0;

        while(curr != NULL && count < k){
            nex = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nex;
            count++;
        }

        head->next = reverseKGroup(nex, k);

        return pre;
    }
};