/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode * head = NULL;
struct TreeNode * tail = NULL;

void PreOrderTrans(struct TreeNode* root){
    struct TreeNode * left;
    struct TreeNode * right;
    
    if (root == NULL){
        return;
    }
    
    left = root->left;
    right = root->right;
    
    root->left = NULL;
    root->right = NULL;
    
    if (head == NULL){
        head = root;
    }
    if (tail == NULL){
        tail = root;
    } else {
        // enqueue at the end
        tail->right = root;
        tail = root;
    }
    PreOrderTrans(left);
    PreOrderTrans(right);
}

void flatten(struct TreeNode* root){
    head = NULL;
    tail = NULL;
    PreOrderTrans(root);
}