# Longest Increasing Subsequence
## Statement
The statement is [here](https://leetcode.com/problems/longest-increasing-subsequence/)

## Solution
I fixed this problem by using a recursive brute-force algorithm and then I improved it by using memorization. This results in a DP solution. The algorithm tries all the possible subsequences and keeps track of the longest one. For a starting given position, the longest subsequence is always the same, so I store in a hash the len of the longest starting for each position for using it later.
 
## Complexity
O(n^2)

## References
