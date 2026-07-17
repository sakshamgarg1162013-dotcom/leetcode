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

        while(curr != NULL){
            nex = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nex;
        }

        return pre;
    }

    int length(ListNode* head){
        int len = 0;

        while(head != NULL){
            len++;
            head = head->next;
        }

        return len;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL || k == 0)
            return head;

        int len = length(head);
        k %= len;

        if(k == 0)
            return head;

        ListNode* curr = reverse(head);

        // Make circular
        head->next = curr;

        // Move to the kth node
        for(int i = 1; i < k; i++){
            curr = curr->next;
        }

        ListNode* temp = curr->next;
        curr->next = NULL;

        head = reverse(temp);

        return head;
    }
};