# Sort Chars by frequency
## Statement
See the statement at https://leetcode.com/problems/sort-characters-by-frequency/.

## Solution A
The idea is to use one hash table to count the frequency of each letter. Then, the hash table need to be sorted. It is possible to do this by using the qsort() function. The returned string is made by walking through the sorted hash table and outputing each letter depending on the frequency. 

## Solution B
The idea is to use two hash tables: 
1. to count the frequency of each letter
2. to count the number of letter per frequency. In this case, the frequency is the key of the hash table. This hash table has to handle colissions,.e.g, by using a simple linked list.

## Complexity
The first soultion is O(n + n.lg(n)). The second solution is O(n).

## References
