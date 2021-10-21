# NextGreaterElement
## Statement
See the statement at https://leetcode.com/problems/next-greater-element-i/.

## Solution
There are at least two solutions for this problem. The first is to add all the elements of nums2 in a map, and then, walk nums1 from the positions that are stored in the map. This solution is not better than the O(n^2) brute force solution. The second solution proposes to use a stack. I got this solution from the discussion section. The idea is to calculate the next greater element for all the elements in nums2 and store them in a map. Then, you have to walk nums1 and, by using the map, get the next greater element for each element and store them in the returned array.

## Complexity
I think the complexity of the second solution is O(n).

## References
