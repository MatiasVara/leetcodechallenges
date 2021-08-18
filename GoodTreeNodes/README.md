# GoodTreeNodes
## Statement
See statement at https://leetcode.com/problems/count-good-nodes-in-binary-tree/

## Solution
The solution walks the tree by checking first the root node and then the childs. It keeps track of the biggest number in the path from root. If root's value is bigger that the biggest value in the current path, the counter is incremented and the root value is the new biggest value of the path.

## Complexity
O(n)

## References
