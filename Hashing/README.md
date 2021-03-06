# HASHING TECHNIQUES

Hashing helps store key at certain locations on hash table. Function is one to one or many to one. 

When hashing is one to one, it is **Ideal Hashing**. Drawback of ideal hashing is a lot of space is required. [H(x)=x]
When hashing is many to one, chaining can occur and two keys can get mapped at same location leading to collision. [H(x)=x%10]

## How to solve collisions?

1. **Open Hashing**
    
    **Chaining** : We chain the keys which fall under the same index in hash table. The hash table is basically an array of linked lists. They keys must be kept in sorted order in linked list.

    Analysis of hashing function is done by loading factor:

    > Lambda = Number of keys/Size of hash table

    So number of keys = 100 and size of table is 10 => then loading factor is 10 i.e. we are assuming uniform distribution of keys.
    Time taken for searching a key involves computing hash using function which is O(1).
    Add to this, average time to look in chaining and we get time for average successful search :

    > t = 1+(lambda/2)

    Average Unsuccessful search:
    
    > t = 1+lambda

    If we don't select a proper hashing function, then the keys will fall in same bucket and our assumption of uniform distribution
    will fail.

2. **Closed Hashing**
    a. **Open Addressing** : We don't create chains but rather store the key at another place in the hash table in case of collisions.

    **Linear Probing:**

    > h(key) = (h(key)+f(i))%(hash_table_size) where f(i)=i,i=0,1,2,....

    So in linear probing, we try to store the key at its meant position and if it is already occupied, we try to fill the 
    next empty position in the table.
    
    ***Condition:*** Lambda or the loading factor has to be less than equals 0.5 so that number of elements cannot exceed half 
    the table size and we can place the keys close to their meant positions.

    ***Disadvantages:**()
    1. Clustering of keys with same hash value in consecutive array elements, which displaces some keys which are introduced later and see their positions occupied by other out-of-order keys.

    2. For searching some key, we may have to travel across many elements before we get to that key in table.
    
    3. If we delete a key, other keys after it in table may also be shifted left. Delete is a complex operation, we will have to insert all elements again. e.g.: removing 24 from index 4 means if 34 is at index 5, we will have to shift it
    to index 4 and so on. This is very difficult to implement so we just have to insert all over again.

    **Quadratic Probing:**

    To avoid the clustering in linear probing due to keys getting same hash value and getting placeed in consecutive locations, we can
    modify the probing function slightly:

    > h(key) = (h(key)+f(i))%(hash_table_size) where f(i)=i^2,i=0,1,2,....

    **Double hashing:**

    To avoid clustering in linear probing and distribute keys across hash table, we can also use double hashing technique:

    > h1(x) = x%10;

    > h2(x) = 7-(x%7);

    > h'(x) = (h1(x)+i*h2(x))%10; where i=0,1,2,...

    So h'(x) is the hashing method used. When a key is hashed, i=0 initially and it checks if the spot is occupied. If it is, then i=1
    and then again checks. This goes on till it finds an empty spot to place the key.

3. **Other Hashing techniques:**

    1. **Mod**

    > h(x) = (x%size)+1

    2. **Midsquare**

    > h(x) = take the middle digit of x^2

    For e.g.: 13^2 = 169 so we place 13 in 6th index.

    3. **Folding**

    Here we take first 2 digits each and then sum up all of them. e.g.: summing up 12,33 & 47 in 123347 and getting 92 so we take 
    it as index.

    We can decide on our own unique hashing technique on condition that it always gives same hash value for a key.