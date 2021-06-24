/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct ListNode* findMidPoint(struct ListNode* head, struct ListNode* end){
    struct ListNode * fast = head;
    struct ListNode * slow = head;
    while ((fast->next != NULL) && (fast->next->next != NULL) && (fast->next != end) && (fast->next->next != end)){
        slow = slow->next;
        fast= fast->next->next;
    }
    return slow;
}

void addSubNode(struct TreeNode ** root, struct ListNode * head, struct ListNode * end){
    struct ListNode * mid;
    struct TreeNode * rt;
    if ((head == NULL) || (head == end)) {
        return;
    }
    rt = malloc(sizeof(struct TreeNode));
    mid = findMidPoint(head, end);
    rt->val = mid->val;
    rt->right = NULL;
    rt->left = NULL;
    addSubNode(&rt->right, mid->next, end);
    addSubNode(&rt->left, head, mid);
    *root = rt;
}
struct TreeNode* sortedListToBST(struct ListNode* head){
    struct TreeNode * root;
    
    if (head==NULL) {
        return NULL;
    }
    
    addSubNode(&root, head, NULL);
   
    return root;
    
}
