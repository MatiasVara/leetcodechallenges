# Binary Tree Level Order Traversal
## Statement
Find the statement [here](https://leetcode.com/problems/binary-tree-level-order-traversal/)

## Solution
This solution uses two stacks: *oldstack* and *newstack*. *oldstack* contains the nodes that are in the current level of the tree and *newstack* contains the nodes that are in the next level of the tree. *oldstack* is initialized with the root node. *newstack* is build by peeking elements from the beginning of the *oldstack* and pushing first the left child and then the right child into *newstack*. When an element is taken from *oldstack*, you have to put its value in a array. Finally, you have to exchange *newstack* and *oldstack*. The loop exits when *oldstack* is empty.

## Note
This problem requires to have an stack quite large to store all the possible values of a level. If we know that the high of the tree is less then N, then the stacks should be less than 2^N. Also, in the returning array, the number of columns is equal to the high of the tree. To previously alloc the memory, I calculated the high of the tree. This could also be fixed by using a linked list and then allocating all as a whole. This is not going to change the complexity.

## Complexity
This solution is O(n)

## References
