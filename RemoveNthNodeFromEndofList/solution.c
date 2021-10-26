/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int count;
struct ListNode* rem;
struct ListNode* prev;

void dfs(struct ListNode * head, int n){
    if (head == NULL){
        return;
    }
    dfs(head->next, n);
    count++;
    if (count == n) {
        rem = head;
    } else if (count == n + 1){
        prev = head;
    }
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    count = 0;
    rem = NULL;
    prev = NULL;
    dfs(head, n);
    if (rem == head){
        head = head -> next;
    } else {
        prev->next = rem->next;
    }
    return head;
}
