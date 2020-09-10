# HASHING TECHNIQUES

Hashing helps store key at certain locations on hash table. Function is one to one or many to one. 

When hashing is one to one, it is **Ideal Hashing**. Drawback of ideal hashing is a lot of space is required. [H(x)=x]
When hashing is many to one, chaining can occur and two keys can get mapped at same location leading to collision. [H(x)=x%10]

## How to solve collisions?

1. Open Hashing 
    a. Chaining : We chain the keys which fall under the same index in hash table. The hash table is basically an array of linked lists. They keys must be kept in sorted order in linked list.

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

2. Closed Hashing
    Open Addressing : We don't create chains but rather store the key at another place in the hash table in case of collisions.