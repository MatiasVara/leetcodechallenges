# Move zeros
## Statement
The statement is at https://leetcode.com/problems/move-zeroes/

## Solution
The idea of this solution is to keep a pointer to the first element of the resulting array and other pointer to the next element we are going to move to the begging of the array. Note that both pointers point to the same array. We use the second pointer to check if it is non-zero, and in that case, we move the value by using the first pointer. After the move, we increment both pointers. We finish by filling the end of the resulting array with zeros depending on the number of zeros we found.

## Complexity
O(n)

## References
