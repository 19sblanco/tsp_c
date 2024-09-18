# Traveling salesman problem implemented in C
*using as few libraries as possible*

## Algorithm
I used a backtracking approach. Backtracking searches down all possible paths for a given set of cities then returns the most optimal solution (shortest distance path).

## Data Representation
Cities: 
    - get inputted as coordinates (x, y) 
    - once inputted, the program uses the coordinates of each cities to calculate a distance matrix

## Different versions
*I complete different versions of this program through github branches. To look at the code for another version change the branch*

**Version 1.0** (completed)
- Completed working program

**Version 2.0** (completed)
- Handled all memory in the stack (with no heap memory usage)

**Version 3.0** (completed)
- Stop searching down a path if that path is longer than the current best

**Version 4.0** (work in progress)
- Use bitwise operations instead of arrays

**Version 5.0** (work in progress)
- Add threads
