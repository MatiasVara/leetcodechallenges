# JumpGameII
## Statement
Given an array of non-negative integers nums, you are initially positioned at the first index of the array. Each element in the array represents your maximum jump length at that position. Your goal is to reach the last index in the minimum number of jumps. You can assume that you can always reach the last index.

## Solution
We calculate all the possibles paths from the first index to the last index for a given configuration. For each position, we keep track of the minimal number of jumps for toward the last index. We return the minimal number of jumps. This solution is optimized by using a hash table that stores the minimal path for each position to the last index. Positions range from 0 to 1000.

## Complexity

## References
