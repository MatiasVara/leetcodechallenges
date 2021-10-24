/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getH(struct TreeNode* root){
    if (root == NULL){
        return 0;
    }
    return (1 + getH(root->right));
}

int leafs;

void countLeaf(struct TreeNode * root, int level, int end){
    if (root == NULL){
        return;
    }
    if (level == end){
        leafs++;
    }
    countLeaf(root->right, level + 1, end);
    countLeaf(root->left, level + 1, end);
}

int countNodes(struct TreeNode* root){
    int h;
    int nrnodescompl;
    if (root==NULL){
        return 0;
    }
    if ((root->right==NULL) && (root->left==NULL)){
       return 1; 
    }
    h = getH(root) - 1;
    nrnodescompl = (1 - pow(2, h + 1)) / (-1);
    leafs = 0;
    // count the leaf at level h + 1. Note that when it is perfectly completed, this
    // counter returns 0.
    countLeaf(root, 0, h + 1);
    return leafs + nrnodescompl;
}