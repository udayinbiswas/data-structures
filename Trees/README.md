# TREES 

## POINTS ABOUT TREES:
1. N nodes in a tree => N-1 edges . There are no cycles in a tree or double edge between any two nodes.

2. Leaf/External nodes have degree 0 => 0 children.

3. Level starts from 1 onwards at root. Height at root is 0.

4. A collections of trees is a forest.

5. A tree of degree 2 i.e. every node can have atmost 2 children is a **Binary Tree**

6. Number of binary trees that can be constructed from n nodes is Catalan number formula. T(n) = Sum up T(i)*T(n-i-1) where
i = 0 to n-1.

## BINARY TREE

### HEIGHT VS NODES IN BINARY TREE:

1. Minimum nodees in a tree of height h is if the tree is skewed: h+1

2. Max number of nodes in a tree of height h is : 1+2+2^2+....+2^h. This is a GP series.

> a + a*(r^2) + ... + a*(r^h) = a (r^(h+1)-1)/(r-1)

So we get number of nodes as **n = 2^(h+1)-1**. For height = 3, we get 15 nodes. 

3. Maximum height given n nodes is : n-1

4. Minimum height given n nodes is obtained by just using (3) formula. **h = log(n+1)-1**

### INTERNAL VS EXTERNAL NODES IN BINARY TREE:

> degree(0) nodes = degree(2) nodes + 1

## STRICT BINARY TREES

In a strict binary tree, a node can have only 0 or 2 children.

1. Minimum number of nodes given height h is : 2h+1 since we need to extend only one branch of the tree till height h so all levels will have 2 nodes except for level 0 where we have 1 single root.

2. Max number of nodes is same as binary tree that is **nodes = 2^(h+1)-1**

### INTERNAL VS EXTERNAL NODES IN BINARY TREE:

> degree(0) nodes = degree(2) nodes + 1

This basically means external nodes = internal nodes+1

## STRICT N-ARY TREES

An n-ary tree can have atmost n children. A strict n-ary tree similarly can have either 0 or n children.

#### HEIGHT VS NODES IN STRICT N-ARY TREE:

1. Minimum number of nodes in strict n-ary tree is **nodes=n*h+1** and maximum is **nodes = (n^(h+1)-1)/(m-1)**

### INTERNAL VS EXTERNAL NODES IN STRICT N-ARY TREE:

> e = (n-1)*i+1

## REPRESENTATION OF BINARY TREES:

1. *Array representation* :  An element at index i will have left child at 2*i and right child at 2*i+1.

2. *Linked List representation*