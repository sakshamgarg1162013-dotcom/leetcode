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
private:
    ListNode* reverse(ListNode* curr){
        ListNode* pre = NULL;
        ListNode* nex = NULL;
        while(curr!=NULL){
            nex = curr ->next;
            curr->next = pre;
            pre = curr;
            curr = nex;
        }
        return pre;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(k==0)
        return head;
        
        if(head==NULL || head->next == NULL){
            return head;
        }

        ListNode* curr = reverse(head);
        head->next = curr;
        for(int i=1;i<k;i++){
            curr = curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = NULL;
        head = reverse(temp);

        return head; 
    }
};