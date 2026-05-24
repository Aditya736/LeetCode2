class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode smallDummy(0);
        ListNode bigDummy(0);

        ListNode* small = &smallDummy;
        ListNode* big = &bigDummy;

        while(head) {

            if(head->val < x) {
                small->next = head;
                small = small->next;
            }
            else {
                big->next = head;
                big = big->next;
            }

            head = head->next;
        }

        // important
        big->next = NULL;

        // connect both lists
        small->next = bigDummy.next;

        return smallDummy.next;
    }
};