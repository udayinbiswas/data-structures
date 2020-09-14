# BINARY SEARCH TREES 

## POINTS ABOUT BST:

1. Inorder traversal of BST gives all the nodes in sorted order.

2. An inorder list can have Catalan number of trees, which will all be BSTs too in this case. 

3. To delete a node in a BST, find the inorder predecessor or indorder successor and replace node by it. If inorder successor/predecessor is a leaf, we don't need to shift any other elements. If it is not a leaf node, then multiple modifications have to be made. Number of modifications depends on the height i.e. deletion will be O(log n) just like for insertion.