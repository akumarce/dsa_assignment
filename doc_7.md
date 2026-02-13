# Question 7: Dijkstra’s Algorithm for Shortest Path

## 1. Purpose

Implements **Dijkstra’s algorithm** to compute the **shortest distance** from a source vertex to all other vertices in a **weighted undirected graph**.

- Demonstrates **graph representation using adjacency matrix**
- Shows **distance calculation** using **greedy approach**
- Provides **clear, modular, and efficient design**

---

## 2. Data Structure

### Graph

```c
int graph[MAX_VERTICES][MAX_VERTICES];
```

- **2D array** representing adjacency matrix
- `graph[u][v]` = weight of edge between `u` and `v`
- `0` indicates **no direct edge**

### Additional Arrays

- `dist[V]` → stores shortest distance from source
- `visited[V]` → tracks visited vertices

---

## 3. Functions

| Function      | Purpose                                     | Input                  | Output / Effect                        |
| ------------- | ------------------------------------------- | ---------------------- | -------------------------------------- |
| `minDistance` | Find vertex with minimum distance unvisited | `dist[], visited[], V` | Returns vertex index with min distance |
| `dijkstra`    | Implements Dijkstra’s algorithm             | `graph[][], V, src`    | Prints shortest distance from `src`    |

**Flow of `dijkstra`:**

1. Initialize `dist[] = ∞`, `visited[] = 0`
2. Set `dist[src] = 0`
3. Repeat `V-1` times:
   - Pick **unvisited vertex with min distance**
   - Mark it **visited**
   - Update distances of **adjacent vertices**

4. Print the final distances

---

## 4. Main Function Overview

1. Define graph size (`V = 6`)
2. Build adjacency matrix from weighted edges:

```
Edges: (0-1,7), (0-2,9), (0-5,14), (1-2,10), (1-3,15), (2-3,11), (2-5,2), (3-4,6), (4-5,9)
```

3. Choose source vertex (`0`)
4. Call `dijkstra(graph, V, source)`
5. Print shortest distances from source

---

## 5. Sample Output

```
Vertex  Distance from Source 0
0       0
1       7
2       9
3       20
4       20
5       11
```

> Distances represent **shortest paths** from vertex `0` to all other vertices.

---

## 6. Algorithm Example

**Graph:**

```
        0
      /   \
     1     2
    / \    \
   3   4 -  5
```

**Dijkstra from 0:**

- Distance to 0 → 0
- Distance to 1 → 7
- Distance to 2 → 9
- Distance to 3 → 20
- Distance to 4 → 20
- Distance to 5 → 11

---

## 7. Notes

- Uses **adjacency matrix** → easy for small graphs
- **Greedy selection** of min distance vertex ensures correctness
- Time Complexity: **O(V²)**
- Easily extendable to **larger graphs** using priority queue (heap)
- Modular and clean design → **preeminent coding standard**

---
