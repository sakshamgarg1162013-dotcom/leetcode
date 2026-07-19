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
    ListNode* partition(ListNode* head, int x) {

        ListNode* dummy = new ListNode();
        ListNode* smalltail = dummy;
        
        while(head != NULL && head->val < x){
            smalltail->next = head;
            smalltail = head;
            head = head->next;
            smalltail->next = NULL;
        }

        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL){

            if(curr->next->val < x){

                ListNode* nex = curr->next;

                curr->next = nex->next;

                smalltail->next = nex;
                smalltail = nex;
                smalltail->next = NULL;
            }
            else{
                curr = curr->next;
            }
        }

        smalltail->next = head;

        return dummy->next;
    }
};