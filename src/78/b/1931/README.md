# 1931
## Allocating Meetings

- [Problem Link](https://www.acmicpc.net/problem/1931)
- Solutions: [C++](./1931.cpp)

### Problem Description
Given N meetings each with its start time and end time, find the maximum number of meetings possible to fit where no meetings overlap.

### Algorithm
- Sort the meetings by the start time and end time.
- Iterate through the sorted meetings while keeping track of the current end time.
- If the next meeting's start time is after the current end time, add this meeting to the final meetings.
- If the next meeting's end time is before than the current end time, update the current end time to this meeting.

### Keywords
- Greedy Algorithm
- Sorting
