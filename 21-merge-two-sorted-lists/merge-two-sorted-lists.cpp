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
    ListNode* solve(ListNode* first,ListNode* second){
        ListNode* curr1 = first;
        ListNode* nex = first->next;
        ListNode* curr2 = second;
        if(first->next == NULL){
            first->next = second;
            return first;
        }
        while(nex!=NULL && curr2!=NULL){
            
            if((curr2->val >= curr1->val)&& (curr2->val <= nex->val)){
            ListNode* temp = curr2->next;

            curr1->next = curr2;
            curr2->next = nex;

            curr1 = curr2;
            curr2 = temp;

            }
            else{
                curr1 = nex;
                nex = nex->next;
                if(nex==NULL){
                    curr1->next = curr2;
                }
            }
        }
        return first;
    }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
        return list2;
        if(list2==NULL)
        return list1;

        ListNode* ans = new ListNode();

        if(list1->val < list2->val){
            return solve(list1,list2);
        }
        else{
            return solve(list2,list1);
        }
        
    }
};