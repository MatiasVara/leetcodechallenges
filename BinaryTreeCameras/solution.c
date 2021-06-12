/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int count = 0;

// 0 is NEED_COVER
// 1 is CAMERA
// 2 is COVERED
// 
int dfs(struct TreeNode * root){
    
    if (root == NULL){
        return 2;
    }
    
    // this is a leaf
    if ((root->right == NULL) && (root->left == NULL)){
        return 0;
    }
    
    int left = dfs(root->left);
    int right = dfs(root->right);
    
    // I am parent of a leaf
    // put a camera
    if ((left == 0) || (right == 0)){
        count += 1;
        return 1;
    }
    
    // one of my siblins has a camera
    // so I am covered
    if ((left == 1) || (right == 1)) {
        return 2;
    }
    
    // both of my sibligs are covered
    // I need to be covered
    return 0;
}

int minCameraCover(struct TreeNode* root){
    count = 0;
    if (dfs(root) == 0){
        count += 1;
    }
    return count;
}
