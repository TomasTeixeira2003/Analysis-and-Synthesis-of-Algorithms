# High-Speed Railway Optimization 

This project was developed for the **Analysis and Synthesis of Algorithms** (ASA) course at LEIC, Instituto Superior Técnico (2022/2023). It addresses a complex optimization problem involving computational geometry and graph theory to design an efficient railway network for "Caracolândia."

## Problem Description

The goal is to estimate the maximum commercial exchange value between regions while minimizing infrastructure costs. The project requires building a network that connects the maximum number of regions using only strictly necessary segments.

* **Input**: A set of coordinates (latitude/longitude) representing regional capitals and their potential commercial exchange values.
* **Constraints**:
    * Connections are assumed to be straight lines.
    * The network must follow a **Delaunay Triangulation** to identify potential neighboring regions.
    * The final infrastructure must be a **Minimum Spanning Tree (MST)** to minimize costs while maintaining connectivity.
* **Goal**: Determine the maximum commercial value possible within the optimized network.



## Implementation Details

The solution is implemented in **C++** and utilizes advanced geometric and graph algorithms to stay within strict time and memory limits.

### Input Format
The program reads from standard input:
1.  An integer representing the number of regions ($n$).
2.  For each region: $x$ and $y$ coordinates and an associated weight/value.

### Output
A single integer representing the optimized commercial value of the network.

---

## Algorithmic Approach

The project is divided into two major algorithmic phases:

1.  **Computational Geometry (Delaunay Triangulation)**:
    * Used to determine which regions are "neighbors" in a planar enforcement.
    * Ensures that no capital is inside the circumcircle of any triangle in the triangulation.
2.  **Graph Theory (Kruskal’s Algorithm)**:
    * Once the potential edges are identified via triangulation, an **MST algorithm** is applied.
    * This extracts the subset of edges that connects all points with the minimum total weight (or maximum value depending on the specific problem variant).
