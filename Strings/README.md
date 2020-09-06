# Strings

## 1. Character Set/ASCII codes
Computer System works on binary system, but don't work on characters. For every character, we assign a numeric code. 
These codes are standard codes called ASCII(American National Standards Institue assigned). In other languages, codes
are defined and are ISO codes called Unicodes. 

**ASCII codes:**

*For uppercase alphabets:* A - 65, B - 66, ..., Z-90

*For lowercase alphabets:* a - 97, b - 98, ..., z- 122

*For numerical symbols:* 0 - 48, 1 - 49, ... , 9 - 57

Special characters also have ASCII codes like (,),$ etc.

For enter, ASCII code is 10 and for space it is 13 and for escape 27.

ASCII codes start from 0-127. To represent these, we need 7 bits. In RAM, 1 byte is allocated so it takes 1 byte of unit memory. In memory, character is not stored but rather its code. for e.g.:65 for A.

Unicodes takes 2 bytes and represented in hexadecimal form (4*4 bits) **e.g.** c03a

## 2. Character Array

In C language,
>char c = 'a';

>printf("%c",c); // prints a

>printf("%d",c); // prints 65

### Declaring and Initializing an array in stack

>char S[] = {'a','b','c','d','e'};

>char S[5] = {'a','b','c','d','e'};

>char S[] = {65,66,67,68,69,70};

A string is a set of characters.
>char name[10] = {'j','o','h','n'}

Character array is of length 10 but string is of length 4. There is a string delimiter at end of string characters '\0'

>char name[10] = {'j','o','h','n','\0'}

This array of characters is a string now. For storing a string of length n, we take n+1 spaces in array.

>char name[] = {'j','o','h','n','\0'}

Below,C compiler will add the delimiter on its own:

> char name[] = "John"



### Declaring and Initializing an array in stack
This creates string in **heap**:

> char *name = "John";

### Printing in C
> printf("%s",name);

C compiler can print this character array representing string (i.e.end with '\0') but not any other array type.


