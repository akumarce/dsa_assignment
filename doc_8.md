# Question 8: Random Integer Sorting with User-Selected Algorithm

## 1. Purpose

This program generates a list of **N random integers** in the range `[1, 1000]` and sorts them using a **user-selected sorting algorithm**:

- **Bubble Sort**
- **Selection Sort**
- **Insertion Sort**
- **Merge Sort**

It also tracks and displays:

- Total **comparisons** performed
- Total **swaps** performed (where applicable)

The program demonstrates **dynamic array handling**, **algorithm modularity**, and **statistical tracking** of operations.

---

## 2. Data Structure

### Arrays

```c
int arr[N];      // Original random numbers
int copy[N];     // Copy used for sorting
```

- `arr[]` → stores the original random numbers
- `copy[]` → sorted version of `arr[]`
- `N` → number of integers provided by the user

### Counters

- `compCount` → counts **comparisons**
- `swapCount` → counts **swaps** (Bubble, Selection, Insertion only)

---

## 3. Functions

| Function          | Purpose                                            | Input                              | Output / Effect                    |
| ----------------- | -------------------------------------------------- | ---------------------------------- | ---------------------------------- |
| `swap`            | Swap two integers and increment swap count         | `int *a, *b, *swapCount`           | Swaps values, increments swapCount |
| `bubbleSort`      | Sort array using Bubble Sort                       | `arr[], n, &compCount, &swapCount` | Array sorted, counts updated       |
| `selectionSort`   | Sort array using Selection Sort                    | `arr[], n, &compCount, &swapCount` | Array sorted, counts updated       |
| `insertionSort`   | Sort array using Insertion Sort                    | `arr[], n, &compCount, &swapCount` | Array sorted, counts updated       |
| `mergeSort`       | Sort array using Merge Sort                        | `arr[], n, &compCount`             | Array sorted, comparisons counted  |
| `merge`           | Helper for Merge Sort                              | `arr[], l, m, r, &compCount`       | Merges two subarrays               |
| `mergeSortHelper` | Recursively divides and sorts array for Merge Sort | `arr[], l, r, &compCount`          | Calls merge on subarrays           |

---

## 4. Main Function Overview

1. **Input**: Ask user for number of integers `N`
2. **Random Generation**: Populate `arr[]` with numbers `[1,1000]`
3. **Copy Array**: Copy `arr[]` into `copy[]` for sorting
4. **Display Original Array**
5. **Algorithm Choice**: User selects one of the 4 sorting algorithms
6. **Sort**: Call the corresponding sorting function
7. **Display Sorted Array**
8. **Display Stats**: Total comparisons and swaps (if applicable)

---

## 5. Sample Output

### Sample Run 1

```
Enter number of integers (N): 10

Original Array:
523 12 845 234 67 91 456 789 3 678

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
2

Sorted Array:
3 12 67 91 234 456 523 678 789 845

Total Comparisons: 45
Total Swaps: 6
```

### Sample Run 2 (Merge Sort)

```
Enter number of integers (N): 8

Original Array:
120 500 32 67 999 2 450 87

Choose sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
4

Sorted Array:
2 32 67 87 120 450 500 999

Total Comparisons: 16
```

> **Note:** Swap count is not tracked for Merge Sort as merging does not involve direct swaps.

---

## 6. Notes

- Comparisons and swaps provide insight into **algorithm efficiency**
- Modular design allows **easy extension** for other sorting algorithms
- Random numbers ensure **different outputs each run**
- Preeminent coding: **clear comments, modular functions, clean output**

---
