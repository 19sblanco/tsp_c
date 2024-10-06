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

### Version Beta 
- ✅ Working program in Python
- [Python repository](https://github.com/19sblanco/tsp_python)

| Cities | Time (seconds) |
|--------|----------------|
| 12 | 808.4938039779663 |

### Version 1.0 baseline
- ✅ Completed working program

| Cities | Time (seconds) |
|--------|----------------|
| 12 | 23.480295 |
| 13 | 265.090176 |

### Version 2.0 
- ✅ Handled all memory in the stack (with no heap memory usage)

| Cities | Time (seconds) |
|--------|----------------|
| 12 | 13.547940 |
| 13 | 221.827008 |

### Version 3.0 
- ✅ Stop searching down a path if that path is longer than the current best

| Cities | Time (seconds) |
|--------|----------------|
| 12 | 0.536989 |
| 13 | 2.537332 |
| 14 | 9.415950 |
| 15 | 14.350740 |
| 16 | 110.076049 |


#### Version 4.0
- ✅  Use Dynamic programming and bitwise operations 

| Cities | Time (seconds) |
|--------|----------------|
| 18 | 0.527816 |
| 19 | 1.272880 |
| 20 | 2.794500 |
| 21 | 6.400442 |
| 22 | 15.197409 |

### Future Versions (Planned)

#### Version 6.0
- [ ] Add threads
- [ ] Use ints instead of doubles