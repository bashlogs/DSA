//Definition for singly-linked list.
struct ListNode {
     int val;
     struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode temp;
    temp.val = 0; temp.next = NULL;
    struct ListNode* head = &temp;
    int carry = 0, sum;
    while(l1 != NULL || l1 != NULL || carry != 0){
        sum = carry + ( l1 == 0 ? 0 : l1->val ) + ( l2 == 0 ? 0 : l2->val );
        carry = sum / 10;
        sum %= 10;
        head->next = malloc(sizeof(struct ListNode));
        head->next->val = sum;
        head->next->next = NULL;
        l1 = (l1 == 0 ? 0 : l1->next);
        l2 = (l2 == 0 ? 0 : l2->next);
        head = head->next;
    }
    return temp.next;
}
