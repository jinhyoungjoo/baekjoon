# 2579 
## Walking Up Stairs.

- [Problem Link](https://www.acmicpc.net/problem/2579)
- Solutions: [C++](./2579.cpp)

### Problem Description
- Given N integers, find the maximum value of the sum of a subsequence where the subsequence cannot have 3 consecutive numbers.

### Algorithm
- Track two tables, each indicating the number of consecutive numbers reached. Since the condition is that three consecutive numbers is not possible, the values are 1 and 2.
- Follow the recursive equation where:
    - scores[i][0] = max( scores[i - 2][0], scores[i - 2][1] ) + values[i]
    - scores[i][1] = scores[i - 1] + values[i]

### Keywords
- Dynamic Programming
