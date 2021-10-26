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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
  struct ListNode * last = head;
  struct ListNode * start = head;
  while ((last != NULL) && (n > 0)){
    last = last->next;
    n--;
  }
  if (last == NULL){
    head = head->next;
    return head;
  }
  while (last->next != NULL){
    start = start->next;
    last = last->next;
  }
  start->next = start->next->next;
  return head;
}

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
