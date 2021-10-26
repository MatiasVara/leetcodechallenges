# Remove the nth node from end of list
## Statement
See the statement at https://leetcode.com/problems/remove-nth-node-from-end-of-list/

## Solution
The idea is to use recursion to go to the end of the list, and then, move backward until we find the node (n) and the (n+1). By relying on these two nodes, it is possibe to remove the n node.

## Complexity
O(n)

## References
