# 11724
## Find the number of connected components.

- [Problem Link](https://www.acmicpc.net/problem/11724)
- Solutions: [C++](./11724.cpp)

### Problem Description
Given a undirected graph, find the number of connected components.

### Algorithm
- For every vertex, apply the following steps.
    - It the vertex is not visited, apply graph traversal and keep track of visited nodes.
    - If the vertex is visited, do not apply graph traversal.

### Keywords
- Graph
- Graph Traversal
- BFS
- DFS
