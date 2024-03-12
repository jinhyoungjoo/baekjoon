# 1806
## Paritial Sum

- [Problem Link](https://www.acmicpc.net/problem/1806)
- Solutions: [C++](./1806.cpp)

### Problem Description
Given an array of integers, find the shortest length subarray where the sum of the subarray is greater or equal to S.

### Algorithm
- Record the cumulative sum of the array.
- Have two pointers indicating the beginning and end of the subarray.
- If the difference between the two pointers is smaller than S, move the second pointer.
- If the difference between the two pointers is greater or equal to S, then update the minimum length, move the second pointer one step backward, and move the first pointer one step forward to start the process again.

### Keywords
- Cumulative Sum
- Two Pointer
