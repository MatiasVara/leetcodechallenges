# Flatten Binary Tree to Linked List
## Statement
Given the root of a binary tree, flatten the tree into a linked list:
* The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
* The "linked list" should be in the same order as a pre-order traversal of the binary tree.

## Solution
In this solution, it walks the tree by following the pre-order transversal. The root node is enqueued at the end of the linked list. 
 
## Complexity
O(n)

## References
