# TREES #

## POINTS ABOUT TREES:##
1. N nodes in a tree => N-1 edges . There are no cycles in a tree or double edge between any two nodes.

2. Leaf/External nodes have degree 0 => 0 children.

3. Level starts from 1 onwards at root. Height at root is 0.

4. A collections of trees is a forest.

5. A tree of degree 2 i.e. every node can have atmost 2 children is a **Binary Tree**

6. Number of binary trees that can be constructed from n nodes is Catalan number formula. T(n) = Sum up T(i)*T(n-i-1) where
i = 0 to n-1.

7. Minimum nodees in a tree of height h is if the tree is skewed: h+1

8. Max number of nodes in a tree of height h is : 1+2+2^2+....+2^h. This is a GP series.

> a + a*(r^2) + ... + a*(r^h) = a (r^(h+1)-1)/(r-1)

So we get number of nodes as 2^(h+1)-1. For height = 3, we get 15 nodes. 