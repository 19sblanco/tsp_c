# Traveling Salesman Problem Implemented in C

> *Using as few libraries as possible*

## Algorithm

The implementation uses a backtracking approach. Backtracking searches down all possible paths for a given set of cities, then returns the most optimal solution (shortest distance path).

## Data Representation

Cities:
- Get inputted as coordinates (x, y)
- Once inputted, the program uses the coordinates of each city to calculate a distance matrix

## Different Versions

*I completed different versions of this program through GitHub branches. To look at the code for another version, change the branch.*

### Version Beta (Completed)
- ✅ Working program in Python
- [Python repository](https://github.com/19sblanco/tsp_python)

| Cities | Time (seconds) |
|--------|----------------|
| 12 | 808.4938039779663 |

### Version 1.0 (Completed)
- ✅ Completed working program

| Cities | Time (seconds) |
|--------|----------------|
| 12 | 23.480295 |
| 13 | 265.090176 |

### Version 2.0 (Completed)
- ✅ Handled all memory in the stack (with no heap memory usage)

| Cities | Time (seconds) |
|--------|----------------|
| 12 | 13.547940 |
| 13 | 221.827008 |

### Version 3.0 (Completed)
- ✅ Stop searching down a path if that path is longer than the current best

| Cities | Time (seconds) |
|--------|----------------|
| 12 | 0.536989 |
| 13 | 2.537332 |
| 14 | 9.415950 |
| 15 | 14.350740 |
| 16 | 110.076049 |

### Future Versions (Planned)

#### Version 4.0
- [ ] Use bitwise operations instead of arrays

#### Version 5.0
- [ ] Use memoization to store work so that redundant values don't need to be recomputed

#### Version 6.0
- [ ] Add threads