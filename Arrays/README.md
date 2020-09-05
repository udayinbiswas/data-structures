# Arrays
An array is a physical data structures which allocates contiguous blocks of memory to hold elements of similar type.
### Declaring and Initializing an array
This will declare and initialize an array in the stack: 
> int a[5] = {1,2,3,4,5};

#### Static vs Dynamic Array
Static array's size is declared at compile time **e.g.:** *int A[5];* . 
In C++, dynamic array's size can also be declared at run time. This is not a feature of C language. **e.g.** *cin>>n; int A[n];* .

This will declare an array in the heap and return a pointer:
> int *p = new int[5];



