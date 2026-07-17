class Solution {
private:
    ListNode* reverse(ListNode* subhead, ListNode* fast) {
        ListNode* curr = subhead;
        ListNode* pre = fast;
        ListNode* nex = NULL;

        while (curr != fast) {
            nex = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nex;
        }

        return pre;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL || left == right)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = head;

        // Move fast to the node after the right-th node
        for (int i = 0; i < right; i++) {
            fast = fast->next;
        }

        // Move slow to the node before left
        for (int i = 1; i < left; i++) {
            slow = slow->next;
        }

        slow->next = reverse(slow->next, fast);

        return dummy->next;
    }
};  