# 2193
## Pinary Number

- [Problem Link](https://www.acmicpc.net/problem/2193)
- Solutions: [C++](./2193.cpp)

### Problem Description
Find the number of binary numbers of length N that fits the following condition.
- The number does not start with 0.
- The number does not have two consecutive 1s.

### Algorithm
- Use dynamic programming and track two numbers. One for the count of numbers where the trailing bit is 0, and the other for the count of numbers where the training bit is 1.

### Keywords
- Dynamic Programming
