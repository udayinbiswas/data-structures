# Arrays
An array is a physical data structures which allocates contiguous blocks of memory to hold elements of similar type.
### Declaring and Initializing an array
> int a[5] = {1,2,3,4,5};

This will declare and initialise an array in the stack. 

Static array's size is declared at compile time **eg:** *int A[5];* . 

In C++, dynamic array's size can also be declared at run time. This is not a feature of C language. **e.g.** *cin>>n; int A[n];* .

> int *p = new int[5];

This will declare an array in the heap and return a pointer.

