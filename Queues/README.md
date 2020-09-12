# QUEUES

Queue follows FIFO principle. Queue can be implemented by array or linked list.

### Queue using single pointer
1. We use only a rear pointer initialised to -1.
2. Insert will take O(1) time but delete will take O(n) time since we can't leave a blank space in array implementation and all elements have to be shifted to left.

### Queue using double pointer
1. We use a front and rear pointer initialised to -1.
2. Insert will take O(1) time and for delete, we can just move front pointer ahead so it takes O(1) time.
3. To reuse the spaces, we can make it a circular queue.