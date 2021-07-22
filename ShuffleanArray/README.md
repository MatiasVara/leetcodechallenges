# Suffle an Array
## Statement
You can find the statement [here](https://leetcode.com/problems/shuffle-an-array/)

## Solution
This is just the brute-force solution. However, it seems that it passes the tests. This solution just chooses N positions randomly and returns the suffle array. To do this, when the suffle method is invoked, we select random numbers from [0..N-1] until all the positions in the array are selected. When a position is selected, it cannot be selected again. This works like a hat in which the elements are removed.

## Note
This was not my first approach. At the beginning, I tried something more fancy. I generated a look-up table with all the permutation of N position. This results with a table that has N! rows. During the suffle, I had just to select one of the rows randomly. The building of this look-up table took so much time that the solution did not pass the test. To generate the table, I used the Heap's Algorithm. The problem description helped me to cut the number of rows by only generating 9! due to the limited number of calls that the problem says.    

## Complexity
O(N) with N the len of the array.

## References
