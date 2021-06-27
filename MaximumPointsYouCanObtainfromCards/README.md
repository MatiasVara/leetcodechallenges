# Maximum Points You Can Obtain from Cards
## Statement
There are several cards arranged in a row, and each card has an associated number of points The points are given in the integer array cardPoints. In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards. Your score is the sum of the points of the cards you have taken. Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

## Solution
We use a window of (N-k) elements for k=0..K. For each k, we calculate the sum of all the elements and then we calculate the (TotalSum - sum), which is the sum of the elements that are not in the window. We keep track of the maximum value of (TotalSum-sum) and we return to maximum value. We use the prefix sum method to speed up the sum of the elements of the array. 
 
## Complexity
The complexity of this solution is O(n) + O(k) in time and O(n) in space.

## References
