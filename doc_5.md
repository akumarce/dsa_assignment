# Question 5: Undirected Graph Traversal (BFS & DFS)

## 1. Purpose

Implements an **undirected graph** using an **adjacency matrix** and demonstrates:

- **Depth-First Search (DFS)** traversal
- **Breadth-First Search (BFS)** traversal

This demonstrates **graph representation**, **dynamic memory allocation**, and **modular traversal functions**.

---

## 2. Data Structure

### Graph

```c
typedef struct {
    int V;          // Number of vertices
    int** adjMatrix; // Adjacency matrix
} Graph;
```

- `V`: number of vertices in the graph
- `adjMatrix`: 2D array storing edges (1 if edge exists, 0 otherwise)

**Queue Structure** (for BFS):

```c
typedef struct {
    int* items;
    int front;
    int rear;
    int size;
} Queue;
```

- Supports **FIFO** operations for BFS

---

## 3. Functions

| Function      | Purpose                                 | Input                         | Output / Effect                 |
| ------------- | --------------------------------------- | ----------------------------- | ------------------------------- |
| `createGraph` | Allocate and initialize graph           | `int V`                       | Pointer to Graph                |
| `addEdge`     | Add undirected edge between vertices    | `Graph*, int src, int dest`   | Updates adjacency matrix        |
| `DFSUtil`     | Recursive helper for DFS                | `Graph*, int v, int* visited` | Prints node during recursion    |
| `DFS`         | Depth-first traversal from start node   | `Graph*, int start`           | Prints DFS traversal order      |
| `createQueue` | Allocate queue for BFS                  | `int size`                    | Pointer to Queue                |
| `enqueue`     | Add element to queue                    | `Queue*, int val`             | Queue updated                   |
| `dequeue`     | Remove element from queue               | `Queue*`                      | Returns dequeued element        |
| `isEmpty`     | Check if queue is empty                 | `Queue*`                      | Returns 1 if empty, 0 otherwise |
| `BFS`         | Breadth-first traversal from start node | `Graph*, int start`           | Prints BFS traversal order      |

---

## 4. Main Function Overview

- Steps:

1. Create a graph with `6` vertices
2. Add edges:

```
0-1, 0-2, 1-3, 1-4, 2-4, 3-5, 4-5
```

3. Call `DFS(g, 0)` to traverse from vertex `0`
4. Call `BFS(g, 0)` to traverse from vertex `0`
5. Free allocated adjacency matrix and queue

---

## 5. Sample Output

```
DFS starting from node 0: 0 1 3 5 4 2
BFS starting from node 0: 0 1 2 3 4 5
```

> Output shows **node visitation order** in DFS and BFS starting from vertex 0.

---

## 6. Traversal Example

**Graph structure (vertices 0–5):**

```
    0
   / \
  1   2
 / \   \
3   4 - 5
```

**DFS from 0:** 0 → 1 → 3 → 5 → 4 → 2
**BFS from 0:** 0 → 1 → 2 → 3 → 4 → 5

- DFS explores **depth first**
- BFS explores **level by level**

---

## 7. Notes

- **DFS** implemented recursively → uses system call stack
- **BFS** implemented with queue → uses dynamic memory queue
- Proper **memory management** → no leaks
- Modular design allows **easy graph size scaling and traversal extensions**

---
