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
            nex = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nex;
        }
        return pre;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* revhead =  reverse(head);
        ListNode* curr = revhead;
        if(n==1){
            revhead = revhead->next;
            delete curr;
        }
        else{
            for(int i=1;i<n-1;i++){
                curr = curr->next;
            }
            ListNode*  temp = curr->next;
            curr->next = temp->next;
            temp->next;
            delete temp;
        }
        
        revhead = reverse(revhead);
        return revhead;
    }
};