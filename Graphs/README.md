# Graphs

1. Indegree is when number of edges coming into node and outdegree is opposite. 

2. The number of edges connected to a node is called degree of a node.

3. Strongly connected graph is a directed graph where one can reach any node from a given starting node. An undirected graph
is always connected. Non connected graph is where nodes are divided into multiple unconnected components. Directed acyclic graph is where you can't reach a node once you start from it.

## Ways of representing a graph

1. *Adjacency matrix* : v X v matrix where v is the number of vertices. If graph is weighted, we can mark the weight instead of 1 to represent the edge, it now becomes the cost adjacency matrix.

2. *Adjacency list* : v + 2e list where v is number of nodes and e is edges. To represent weighted graph, we need to put the weight of edge in the list along with neighbour vertices of a node.

3. *Compact list* : represent vertices first and then edges in a 1 dimensional list.

## Spanning tree

1. n vertices => n-1 edges connecting them i.e. minimum edges connecting them and we don't have a cycle in the graph. This yields a spanning **tree**. 

2. Graph should be connected and should not have a cycle.

3. We can make (|E| C |v-1| - cycles) spanning trees possible.

4. Minimum spanning tree is that spanning tree with minimum cost of edges.

## Prim Algorithm for MST

1. Take the minimum weight edge and the pair of vertices.

2. Now consider all the edges connected to these pair of vertices only and take the smallest edge, to expand the tree.

3. Repeat this by taking the minimum edge possible from the pool of explored vertices.

4. Time taken is |V-1| * E since for after each vertex addition, we can explore atmost E edges.

5. If we use heap data structure to find minimum edge among edges, time can be reduced to (|V-1|)*(log E)

## Kruskal Algorithm for MST

1. Take the minimum cost edge in each step but if the edge forms a cycle, then skip it.

2. Minimum time taken is |V-1| * E since for finding minimum edge, we need to go through all E edges each time. 

3. If we take min heap, then it will take log E time to find minimum edge. So time is (|V-1|)*(log E).

4. **Disjoint subset**: 2 sets such that their intersection is empty. It is used for detecting cycles. There are 2 operations that are performed: Union and Find. *Weighted union* is merging two subsets with parent as the parent of the subset which has more elements. The purpose of making set is to find whether 2 elements have the same parent and if they do, an edge joining them will form a cycle. *Find* operation will help find the parent of the set to which an element belongs.