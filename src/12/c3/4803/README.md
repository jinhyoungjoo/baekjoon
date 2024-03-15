# 4803
## Tree

- [Problem Link](https://www.acmicpc.net/problem/4803)
- Solutions: [C++](./4803.cpp)

### Problem Description
Given an undirected graph, find the number of connected components that are trees inside the graph.

### Algorithm
- Iterate through every vertex in the graph.
- If the vertex is not visited, traverse through its adjacent vertices and initialize V=0 and E=0.
- For each vertex that gets visited, V += 1 and E += (number of adjacent vertices to the vertex).
- If V = E + 1, then it is a tree.

### Keywords
- Tree
- Graph Traversal
- BFS
