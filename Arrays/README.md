# Arrays
An array is a physical data structures which allocates contiguous blocks of memory to hold similar elements. Array size cannot be modified once declared since we don't know if the next few byte memory blocks are free or not while expanding an array.

### Declaring and Initializing an array in stack
This will declare and initialize an array in the stack: 
> int a[5] = {1,2,3,4,5};

### Declaring and Initializing an array in heap
This will declare an array in the heap and can be accessed by a pointer:
> int \*p = new int[5];

> p[0] = 1;

Similar implementation in C done by malloc function:
> int \*p = (int\*) malloc(5\*sizeof(int));

#### Static vs Dynamic Array
Static array's size is declared at compile time **e.g.:** *int A[5];* . 
In C++, dynamic array's size can also be declared at run time. This is not a feature of C language. **e.g.** *cin>>n; int \*A = new int[n];* .

## Array ADT
Array representation is available in most languages but operations are not present. We can define our own operations to make it an abstract data type.

## Representation of data in array
1. Array Space
2. Size or Capacity
3. Length (Number of elements)

## Methods (Integer Type)
1. void Display()
2. void Append(int x)
3. void Insert(int index,int x)
4. int Delete(int index)
5. int LinearSearch(int key)
6. int BinarySearch(int key)
7. int Get(int index)
8. void Set(int index,int x)
9. int Max()
10. int Min()
11. int Sum()
12. float Avg()
13. void Reverse()
14. void InsertSort(int x)
15. bool isSorted()
16. Array* Merge(Array *arr2)
17. Array* Union(Array *arr2)
18. Array* Diff(Array *arr2)
19. Array* Inter(Array *arr2)


