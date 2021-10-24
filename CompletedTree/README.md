# Completed Tree
## Statement
See the statement at https://leetcode.com/problems/count-complete-tree-nodes/

## Solution
The idea of this solution is to count the high from the right side. Then, I count the nodes in the level Hr+1. The result is (-1+2^(hr+1)) + nodeasathr+1. When the tree is full, the second term becomes zero and the solution ends up counting the whole tree by using the formula above.
## Complexity
The complexity seems to be O(log(2)^2) but I am not sure.

## References
