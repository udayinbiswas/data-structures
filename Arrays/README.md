# Arrays
An array is a physical data structures which allocates contiguous blocks of memory to hold similar elements. Array size cannot be modified once declared since we don't know if the next few byte memory blocks are free or not while expanding an array.

### Declaring and Initializing an array in stack
This will declare and initialize an array in the stack: 
> int a[5] = {1,2,3,4,5};

#### Static vs Dynamic Array
Static array's size is declared at compile time **e.g.:** *int A[5];* . 
In C++, dynamic array's size can also be declared at run time. This is not a feature of C language. **e.g.** *cin>>n; int A[n];* .

### Declaring and Initializing an array in heap
This will declare an array in the heap and can be accessed by a pointer:
> int *p = new int[5];

> p[0] = 1;

Similar implementation in C done by malloc function:
> int *p = (int*) malloc(5*sizeof(int));



