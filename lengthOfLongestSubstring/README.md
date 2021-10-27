# Length Of Longest Substring
## Statement
The statement is at https://leetcode.com/problems/longest-substring-without-repeating-characters/

## Solution
The idea is to use two pointers and a hash. One pointer, e.g., end, is used to add elements into the hash, and the other pointer, e.g., start, is used to remove elements. We keep track of the longest substring between start and end that has unique characters. We use the hash to check if a char at end is already in the hash. If not, we add it into the hash and we increment end. We exit the loop when it is the end of the string or the last char is already in the hash. In that case, we remove start from the hash and we increment it.
 
## Complexity
O(n)

## References
