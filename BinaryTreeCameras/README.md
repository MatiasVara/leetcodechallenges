# Binary Tree Cameras
## Statement
Find the statement [here](https://leetcode.com/problems/binary-tree-cameras/)

## Solution
To get the minimum number of cameras, we have to put them in the nodes that have a leaf as a child and then working backward to the root. We first walk the tree by using a depth first search (dfs) algorithm, i.e., from leaves to root. When we walk back, we handle three situations:
1. If the parent have a leaf, we have to put a camera on the parent
2. If any of my children have a camera, I am covered.
3. If both of my children are covered I need to be cover. In this case, the node acts as a leaf. This means the parent will put a camera.
We need to handle the special case in which root is a leaf which requires one camera.

## Complexity
This solution is O(n)

## References
See also https://dev.to/seanpgallivan/solution-binary-tree-cameras-1a5i
