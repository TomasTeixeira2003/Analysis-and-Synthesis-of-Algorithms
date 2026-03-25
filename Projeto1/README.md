# Rectangular Area Tiling

This project was developed for the **Analysis and Synthesis of Algorithms** (ASA) course at LEIC, Instituto Superior Técnico (2022/2023). It focuses on solving a combinatorial problem involving the tiling of a specific grid area using square tiles of multiple dimensions.

## Problem Description

The objective is to calculate the total number of unique ways to completely tile a given area defined within an $n \times m$ grid. The area is delimited by a "staircase" path.

* **Tiles**: Only square tiles are allowed ($1 \times 1$, $2 \times 2$, $3 \times 3$, etc.).
* **Constraints**: 
    * The area must be fully covered.
    * Tiles cannot overlap.
    * Tiles must stay within the defined staircase boundary.
* **Goal**: Find the total number of possible tiling configurations.



## Implementation Details

The solution is implemented in **C++** and focuses on algorithmic efficiency to handle large grids within the execution time limits.

### Input Format
The program reads from standard input:
1.  Two integers: $n$ (rows) and $m$ (columns).
2.  A sequence of $m$ integers representing the height of the staircase in each column.

### Output
A single integer representing the total number of possible configurations.

---

## Algorithmic Approach

To solve this problem efficiently, the project utilizes:
* **Recursion with Memoization**: Breaking down the tiling problem into smaller sub-problems and storing results to avoid redundant calculations.
* **Backtracking**: Exploring different tile placements at each available grid position.
* **Symmetry & Optimization**: Pruning search paths that cannot lead to a valid full tiling to reduce the state space.
