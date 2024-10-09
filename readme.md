# Optimizing the Traveling Salesman Problem 

> *Built from scratch*

This repository is a study of the traveling salesman problem and the various ways to optimize it. I examined different optimizations and algorithmic improvements would impact the running time and algorithmic complexity of the code. To achieve this I conducted emprical experiments where I measured the time for my program to complete with different inputs and I worked out the algorithmic complexity by hand to figure out how much better an optimization is on an algorithmic level.

**Problem Description**
The Traveling Salesman Problem (tsp) says "Given a set of cities and their coordinates, what is the shortest path that passes through all cities once then returns to the originial city?" 

Pretty simple sounding problem but Tsp is a famous problem in computer science because its notoriously HARD. Not only is this algoritm considered decently hard to impliment its classified as a hard algorithm because computers have a hard time with these algoirthms because the workload required to complete one of these increases drastically as the size of the input increases. 

**Problem representation**
- I represented cities as an x, y pair (x, y)
- I used a distance matrix, a precomputed table containing all pairwise distances between cities


### Different Versions
Each later version of the code is build directly from the version previous to it, with the exception of the beta version to v1.0, in this case the beta version and v1.0 only differ in the programming langauge it was implimented in. Where the beta was implimented in python and v1.0 was implimented in C. 


**Note: Accessing different versions code**
To access different versions of the code, select a different branch in github.

**Beta**: [Python repository](https://github.com/19sblanco/tsp_python)

**v1.0 (main)**
v1.0 impliments a naive brute force recursive algorithm in C. This code will recursively search down all possible paths. There are no optimizations what so ever, just brutally dumb code. I thought that this would serve as a good base line to build optimizations on top of.

**v2.0**
v2.0 impliments the same algorithm as before but instead of using memory on the heap, the code now uses only stack memory. Stack memory is faster than heap memory because heap memory needs additional overhead to manage. This overhead doesn't grow as fast as the problem size grows, meaning, when you increase the input, and therfore problem size, you don't increase the savings this optimization gives you.

**v3.0**
For v3.0, without any more research and just thinking on my own, I implimented the backtracking approach optimization on the recursive algorithm. Backtracking is an algorithmic optimization where your code realizes its going down a path that is guarenteed to not be the correct answer, it will backtrack to a state where its on a path that has a chance of producing a correct answer.

**v4.0**
v4.0 is where I use dynamic programming with bitmasking. Dynamic programming is the first time where my code gets a better complexity class going from O(n!) to O(n^2 * 2^n). Bit masking also speeds things up because bitwise operations are really fast for a cpu to perform and it saves space for better utilization of the cpu cache.


## Tables

### Version Beta 

| Cities | Time (seconds) |
|--------|----------------|
| 12 | 808.4938039779663 |

### Version 1.0 baseline

| Cities | Time (seconds) |
|--------|----------------|
| 12 | 23.480295 |
| 13 | 265.090176 |

#### speed up table
| Version | Multiplier |  
| ------- | ---------- |
| Beta | 34.43 |


### Version 2.0 

| Cities | Time (seconds) |
|--------|----------------|
| 12 | 13.547940 |
| 13 | 221.827008 |


#### speed up table
| Version | Multiplier |  
| ------- | ---------- |
| Beta | 59.67 |
| v1.0 |  1.195-1.73 |


### Version 3.0 

| Cities | Time (seconds) |
|--------|----------------|
| 12 | 0.536989 |
| 13 | 2.537332 |
| 14 | 9.415950 |
| 15 | 14.350740 |
| 16 | 110.076049 |


#### speed up table
| Version | Multiplier |  
| ------- | ---------- |
| Beta | 1505.60589 |
| v1.0 |  43.7258-104.4759 |
| v2.0 |  25.22-87.4253 |


#### Version 4.0

| Cities | Time (seconds) |
|--------|----------------|
| 12 | .004070 |
| 13 | .009303 |
| 14 | .028719 |
| 15 | .053919 |
| 16 | .093316 |
| 18 | .505427 |
| 19 | 1.272880 |
| 20 | 2.794500 |
| 21 | 6.400442 |
| 22 | 15.197409 |

| Version | Multiplier |  
| ------- | ---------- |
| Beta | 198647.126 |
| v1.0 |  5769.114-28495.128 |
| v2.0 |  3328.732-23844.674 |
| v3.0 |  131.938-1179.605 |

