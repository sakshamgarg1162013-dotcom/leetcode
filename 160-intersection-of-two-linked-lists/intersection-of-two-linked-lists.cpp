/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int length(ListNode* curr){
        int count = 0;
        while(curr!=NULL){
            curr = curr->next;
            count++;
        }
        return count;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        int len1 = length(l1);
        int len2 = length(l2);
        if(len2>=len1){
            for(int i=0;i<len2-len1;i++){
                l2 = l2->next;
            } 
        }
        else{
            for(int i=0;i<len1-len2;i++){
                l1 = l1->next;
            }
        }
        while(l1!=NULL && l2!=NULL){
            if(l1==l2){
                break;
            }
            l2 = l2->next;
            l1 = l1->next;
        }
        return l1;
    }
};