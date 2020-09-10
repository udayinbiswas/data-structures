# LinkedList

## Why Linked List?
Once arrays are declared, they are of fixed size. The array size may be insufficient or more than required.

We can allocate nodes in the heap dynamically for a linked list. Linked list is always created in the heap, there is 
no purpose to create it in stack and then return pointer. We can grow it as much we want in heap.

Insert operation in beginning is O(1) but any other place it is O(n). While in array, in end we can insert in O(1) but inserting anywhere else requires shifting of data so O(n). Shifting of data in array is a time consuming task and hence linked list is better in that sense. Same applies for delete method. So direction wise array is better if we insert/delete from end and linked list if we insert/delete from beginning.

## Why Not Linked List?
1. We cannot access elements directly, i.e. have to traverse the list. Operations like binary search are not suitable ( O(n log n) time ). 
2. Storing extra space for the pointer for next node, which is not the case in array. 

## Iterative vs Recursive traversal
Iterative traversal takes O(n) time but constant space.

Recursive traversal of Linked List with n nodes means n+1 activation records will be created till we reach the last node, so a recursive function will have n+1 stack size at the max and asymptomatically both time and space complexity should be O(n)

## Types of linked list

1. Singly linked list
2. Circular linked list :the last node points to the first node
3. Doubly linked list: we can ahead or back in the linked list with help of 2 points. e.g.: contact list or pages opening on same tab in a browser.
4. Circular doubly linked list : a combination of the two previous linked lists.