# 3Sum Closest
## Statement
You can find the statement [here](https://leetcode.com/problems/3sum-closest/).

## Solution
In this problem, the brute-force solution passes the tests. This is just a O(n^3) solution in which three for-loops are used to walk the array and find the closest sum. A better solution is to first sort the array and then use the two-pointers technique. I was not aware of this method so I have to read some links. The idea is to have three pointers: one that is fixed and two that move depending on the result of the sum. The fixed pointer starts at index 0 and is incremented until the N-3 index. The two-pointers technique is O(n) and it is done for each index so the loop ends up with O(n^2).

## Complexity
The complexity of this solution is O(n.lg(n)) + O(n^2).

## References
