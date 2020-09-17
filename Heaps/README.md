# Heaps

1. A heap is a complete binary tree i.e. if a tree is presented by an array, there should be no empty spaces in array. Hence, Height of a heap is always of order O(log n).

2. Max heap is tree where every node has GTE value than its descendants and opposite for min heap.

3. The use of a heap is not for searching purpose.

4. While inserting an element in heap, we insert in next free space to maintain complete binary tree. Then compare the element with its parent and exchange if its greater(for max heap). Do this till it reaches its apt position. All this can be done easily by an **array representation of heap tree**.

5. To insert n elements in a heap, it would take O(n log n) time.

6. From heap, we can only delete root element which is highest priority element (max/min). Then take the lastmost element in heap according to array,delete it from original position and place it in root. Why lastmost element? So that tree remains complete and there are no blank spaces in array representation.

7. Heap sort is basically deleting the max element at root from max heap and this element will go to the last position of the array. This we keep doing by deleting n elements until we find all elements sorted in ascending order eventually. Total time taken by heap sort is sum of creating the heap of O(n log n) and deleting elements 1 by 1 to make the array sorted of O(n log n). So O(2n log n)~O(n log n)

Post this we compare root with its children and replace it with the bigger child each time, repeat this procedure.

8. Priority queue is an abstract data structure which can be implemented by heap. Insert and deleting an element will both take O(log n) time.