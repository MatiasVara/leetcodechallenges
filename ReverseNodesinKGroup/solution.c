/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Invert the list between start -> end
// 1->2->3->4
// start = 1, end=4
// Output: 3->2->1->4
// It returns the new head
struct ListNode * invert(struct ListNode * start, struct ListNode * end){
    struct ListNode * i_next = start->next;
    struct ListNode * i_prev = start;
    while (i_next != end){
        struct ListNode * tmp = i_next->next;
        i_next->next = i_prev;
        i_prev = i_next; 
        i_next = tmp;    
    }
    start->next = NULL;
    return i_prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode * tmp = head;
    struct ListNode * start = tmp;
    struct ListNode * new_head;
    struct ListNode * prev_start = NULL;
    struct ListNode * new_head2;
    int j;
    if (k==1){
        return head;
    }
    while(1){
        struct ListNode * last = tmp; 
        // get k elements from the list
        for (j=0; j<k;j++){
            tmp = tmp->next;
            if (tmp == NULL){
                break;
            }
        }
        // if we got less than k, 
        // just add the remainder elements
        //  and return
        if ((tmp == NULL) && (j < k-1)){
            prev_start->next= last;
            return new_head;
        // if we have exactly k elements and no more
        // invert, set and return
        } else if (tmp == NULL){
            new_head2 = invert(start, NULL);
            if (prev_start == NULL){
                return new_head2;
            }
            prev_start->next = new_head2;
            return new_head;
        }
        // execute this only once
        if (start == head){
            new_head = invert(start, tmp);   
            prev_start = start;
        // invert and add at the end
        //
        } else {
            new_head2 = invert(start, tmp); 
            prev_start->next = new_head2;
            prev_start = start;
        }
        start = tmp;
    }
}
