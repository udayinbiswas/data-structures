# LinkedList

## Why Linked List?
Once arrays are declared, they are of fixed size. The array size may be insufficient or more than required.

We can allocate nodes in the heap dynamically for a linked list.

## Why Not Linked List?
1. We cannot access elements directly, i.e. have to traverse the list. Operations like binary search are not suitable.
2. Storing extra space for the pointer for next node, which is not the case in array.

## Iterative vs Recursive traversal
Iterative traversal takes O(n) time but constant space.

Recursive traversal of Linked List with n nodes means n+1 activation records will be created till we reach the last node, so a recursive function will have n+1 stack size at the max and asymptomatically both time and space complexity should be O(n)