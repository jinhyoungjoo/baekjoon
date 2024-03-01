# 1202
## Jewelry Thief

- [Problem Link](https://www.acmicpc.net/problem/1202)
- Solutions: [C++](./1202.cpp)

### Problem Description
Given N jewels each with its weight and value, find the maximum value able to store in K bags.

### Algorithm
- Sort the bags by the available weight in increasing order.
- For each bag, select the maximum value possible given the available weight of each bag. This is done using a priority queue.

### Keywords
- Greedy Algorithm
- Sorting
- Priority Queue 
