# Partition Array
## Statement
You can find the statement [here](https://leetcode.com/problems/partition-array-into-disjoint-intervals/)

## Solution
The solution split the array into two disjoint intervals, i.e., left and right. Then, it looks for the max of the left array and the min of the right array. Finally, it returns when the max of left array is less or equal than the min of the right array. In each iteraction, the len of the left array increases in one element and the len of the right array decreases in one element. The min and max can be found in lineal time. 

## Complexity
The complexity of the solution is O(N), however, my first draft was ~ O(n^2). This latest solution passed the tests too.

## References
