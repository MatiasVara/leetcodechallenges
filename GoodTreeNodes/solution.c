/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int goodNodesCount;

void goodNodesRecur(struct TreeNode * root, int max){
    int tmp = max;
    if (root == NULL){
        return;
    }
    if (root->val >= tmp){
        goodNodesCount += 1;
        tmp = root->val;
    }
    goodNodesRecur(root->left, tmp);
    goodNodesRecur(root->right, tmp);
}

int goodNodes(struct TreeNode* root){
    goodNodesCount = 0;
    goodNodesRecur(root, INT_MIN);
    return goodNodesCount;
}