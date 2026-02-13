# Question 6: Construction of Min Heap and Max Heap

## 1. Purpose

Builds both **Min Heap** and **Max Heap** from a given unsorted array using heap construction algorithms.

- **Min Heap:** Parent node ≤ children
- **Max Heap:** Parent node ≥ children

This demonstrates **heap data structure**, **array-based tree representation**, and **heapify process**.

---

## 2. Data Structure

### Heap (Array Representation)

The heap is implemented using an array:

```c
arr[i]      -> parent
arr[2*i+1]  -> left child
arr[2*i+2]  -> right child
```

This representation avoids explicit node structures and uses **complete binary tree indexing**.

---

## 3. Functions

| Function       | Purpose                                 | Input         | Output / Effect              |
| -------------- | --------------------------------------- | ------------- | ---------------------------- |
| `swap`         | Swap two integer values                 | `int*, int*`  | Values swapped               |
| `heapifyMin`   | Maintain min-heap property at index `i` | `arr[], n, i` | Subtree becomes min-heap     |
| `heapifyMax`   | Maintain max-heap property at index `i` | `arr[], n, i` | Subtree becomes max-heap     |
| `buildMinHeap` | Convert array into min heap             | `arr[], n`    | Array rearranged as min heap |
| `buildMaxHeap` | Convert array into max heap             | `arr[], n`    | Array rearranged as max heap |
| `printArray`   | Print array elements                    | `arr[], n`    | Displays heap representation |

---

## 4. Main Function Overview

Steps performed in `main()`:

1. Define an unsorted array:

```
40, 10, 30, 50, 20, 60
```

2. Copy array into:
   - `minHeap`
   - `maxHeap`

3. Call:

```
buildMinHeap(minHeap, n);
buildMaxHeap(maxHeap, n);
```

4. Print:
   - Original array
   - Min Heap
   - Max Heap

5. Free allocated memory.

---

## 5. Sample Output

```
Original Array: 40 10 30 50 20 60
Min Heap: 10 20 30 50 40 60
Max Heap: 60 50 30 40 20 10
```

---

## 6. Heap Construction Example

**Original Array:**

```
        40
      /    \
    10      30
   /  \    /
 50   20  60
```

### After Min Heap

```
        10
      /    \
    20      30
   /  \    /
 50   40  60
```

### After Max Heap

```
        60
      /    \
    50      30
   /  \    /
 40   20  10
```

---

## 7. Notes

- Heap is built using **bottom-up heapify** from last non-leaf node
- Time Complexity:
  - Build Heap: **O(n)**
  - Heapify: **O(log n)**

- Dynamic memory allocation used for separate min and max heaps
- Implementation is modular and easily extendable for priority queues or heap sort
