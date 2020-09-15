# Heaps

1. A heap is a complete binary tree i.e. if a tree is presented by an array, there should be no empty spaces in array. Hence, Height of a heap is always of order O(log n).

2. Max heap is tree where every node has GTE value than its descendants and opposite for min heap.

3. The use of a heap is not for searching purpose.

4. While inserting an element in heap, we insert in next free space to maintain complete binary tree. Then compare the element with its parent and exchange if its greater(for max heap). Do this till it reaches its apt position. All this can be done easily by an **array representation of heap tree**.

5. To insert n elements in a heap, it would take O(n log n) time.

