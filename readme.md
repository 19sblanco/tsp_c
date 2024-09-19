# Traveling salesman problem implemented in C
*using as few libraries as possible*

## Algorithm
I used a backtracking approach. Backtracking searches down all possible paths for a given set of cities then returns the most optimal solution (shortest distance path).

## Data Representation
Cities: 
    - get inputted as coordinates (x, y) 
    - once inputted, the program uses the coordinates of each cities to calculate a distance matrix

## Different versions
* I complete different versions of this program through github branches. To look at the code for another version change the branch*

### note:
* each version is built upon the previous version, meaning it will have all the features of the previous version

**Version beta** (completed)
- Completed a working program in Python
- [Python repository](https://github.com/19sblanco/tsp_python)
- Time for execution of program
    - cities: 12
    - time: 808.4938039779663

**Version 1.0** (completed)
- Completed working program
- Time for execution of program
    - cities: 12
    - time: 23.480295
    - cities: 13
    - time: 265.090176

**Version 2.0** (completed)
- Handled all memory in the stack (with no heap memory usage)
- Time for execution of program
    - cities: 12
    - time: 13.547940
    - cities:13
    - time: 221.827008

**Version 3.0** (completed)
- Stop searching down a path if that path is longer than the current best
- Time for execution of program
    - cities: 12
    - time: 0.536989
    - cities: 13
    - time: 2.537332
    - cities: 14
    - time: 9.415950 
    - cities: 15
    - time: 14.350740 
    - cities: 16
    - time: 110.076049

**Version 4.0** (work in progress)
- use memoization to store work so that I don't have to recompute redundant values


**Version 5.0** (work in progress)
- Use bitwise operations instead of arrays

**Version 6.0** (work in progress)
- Add threads

