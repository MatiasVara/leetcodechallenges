# From sorted linked list to BST
## Statement
Find the statement [here](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

## Solution
To build a balanced BST from a sorted linked list, we have to peek the middle point of the list and put it as a root node of the tree. In each iteration, the list is split into two lists: at left and at right of the middle point. The value of the middle point is put as root. We recursive repeat this procedure by passing as a parameter a pointer to the left and right childrens of the root node. We continue doing this until the linked list has no elements.
 
## Complexity
This solution is O(n*lg(n)).

## References
