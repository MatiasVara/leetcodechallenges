# Min Stack
## Statement
See at https://leetcode.com/problems/min-stack/

## Solution
The idea is to use an stack and a simple linked list. The stack is implemented by using an array and keeps track of the push()/pop() operations. The simple linked list is used to keep track of the minumun values. During push(), if the value is less or equal than the head of the list, we enqueue it at the head of the linked list. During pop(), if the value corresponds with the head of the list, we remove that value from the head. Note that during pop(), either the value was never in the linked list or it is the current head. In that case, the next minimum from the linked list would be at the head.
  
## Complexity
All the operations are O(1).

## References
