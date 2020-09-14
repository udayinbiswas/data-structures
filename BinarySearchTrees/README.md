# BINARY SEARCH TREES 

## POINTS ABOUT BST:

1. Inorder traversal of BST gives all the nodes in sorted order.

2. An inorder list can have Catalan number of trees, which will all be BSTs too in this case. 

3. To delete a node in a BST, find the inorder predecessor or indorder successor and replace node by it. If inorder successor/predecessor is a leaf, we don't need to shift any other elements. If it is not a leaf node, then multiple modifications have to be made. Number of modifications depends on the height i.e. deletion will be O(log n) just like for insertion.

4. **Important**: To construct a BST, we need only the preorder or postorder list. This is because we can always sort the preorder or postorder list to get the inorder list. Inorder list of a BST is always in sorted order.

### DRAWBACKS

1. The height of a BST can vary from log(n) to n depending on what order the nodes are inserted. e.g.: Inserting Keys:40,20,30,60,50,10,70 is log(n)-1 time whereas Inserting it in order: 10,20,30,40,50,60,70 is n-1 time. We cannot control the order of insertion and hence the height of BST. AVL trees can help with balancing trees.