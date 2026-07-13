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
    ListNode* findmid(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next !=NULL){
            fast = fast->next;
            if(fast->next!=NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        ListNode* mid = findmid(head);
        ListNode* revhead = reverse(mid->next);
        mid->next = NULL;
        while(temp!=NULL && revhead!=NULL){
            if(temp->val!=revhead->val){
                return false;
            }
            temp = temp->next;
            revhead = revhead->next;
        }
        return true;
    }
};