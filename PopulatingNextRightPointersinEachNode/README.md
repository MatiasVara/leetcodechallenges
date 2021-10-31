# Populating Next Right Pointers in EachNode
## Statement
The statement is at https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

## Solution
The idea is to use two stacks to traverse the tree. One of the stack is always empty. We use the other stack to keep the nodes from the previous level. We store the child nodes in the second stack. When we finish with the elements in the previous level, we swap stacks. The stack is accesed as a queue list. The next field of the first element must point to NULL and so on. By doing so, we create a linked list from left to right.

## Complexity
O(n)

## References
