# QUEUES

Queue follows FIFO principle. Queue can be implemented by array or linked list.

## Array implementation

### Queue using single pointer
1. We use only a rear pointer initialised to -1.
2. Insert will take O(1) time but delete will take O(n) time since we can't leave a blank space in array implementation and all elements have to be shifted to left.

### Queue using double pointer
1. We use a front and rear pointer initialised to -1.
2. Insert will take O(1) time and for delete, we can just move front pointer ahead so it takes O(1) time.
3. To reuse the spaces, we can make it a **circular queue**.

## Linked List implementation

We have a front pointer to first node and rear pointer to rear node so that enqueue is a constant time operation. Advantage is there is no fixed size but it can get full when heap is full. When heap is full and we try to declare a new node there, it should return a **null pointer** condition.

## Queue using 2 stacks

Maintain 2 queues where we shift the elements to other stack when we want to delete after inserting. We keep on inserting in first stack and keep on deleting in second stack. When we run out of elements to delete in second stack, we transfer the elements of first stack to second stack and then delete.

## Types of Queues

### Dequeue

In dequeue, we can use both the front and rear pointer to insert and delete. It stands for double ended queue.

### Priority Queue

Elements are dequeue according to priority order from this special type of queue. It is not FIFO.

There are 2 ways of implementing priority queue:

1. Insert in same order and Delete max priority by searching it. While deleting, Search - O(n) and Shifting - O(n) so time taken is 
O(2n) ~ O(n). Insert is O(1).

2. Insert in increasing order of priority and delete last element of array. While inserting, Shifting - O(n) so time taken is O(n). Delete is O(1). 

