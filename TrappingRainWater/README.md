# Trapping Rain Water
## Statement
You can find the statement at https://leetcode.com/problems/trapping-rain-water/

## Solution
This is a sort of brute-force solution. The solution walks the array from left to right. For a given index **i**, it finds the index **j** such a height[i]<= height[j], and then, it calculates the trapped water in the range [i, j]. To take into account the case `[4, 2, 3]`, the solution also keeps track of the higher index, which is lowest than the current height[j].   

## Complexity
The complexity of this solution is O(n^2).

## References
