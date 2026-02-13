# Question 3: Reverse Traversal in a Singly Linked List

## 1. Purpose

Implements a **reverse traversal algorithm** in a **singly linked list** without modifying the list structure.

- **Normal traversal:** left-to-right along `next` pointers.
- **Reverse traversal:** prints elements **from tail to head** using **recursion**.
- Demonstrates **linked list manipulation** and **modular function design**.

---

## 2. Data Structure

### Node

Each node in the singly linked list is represented by a struct:

```c
typedef struct Node {
    int data;           // Value stored in the node
    struct Node* next;  // Pointer to the next node
} Node;
```

- `data`: stores the integer value of the node
- `next`: pointer to the next node in the list

**Advantages:**

- Simple and lightweight for a singly linked list
- Supports dynamic memory allocation
- Can be extended for other linked list operations

---

## 3. Functions

| Function           | Purpose                            | Input                   | Output / Effect                                   |
| ------------------ | ---------------------------------- | ----------------------- | ------------------------------------------------- |
| `createNode`       | Allocate and initialize a node     | `int data`              | `Node*` pointer                                   |
| `appendNode`       | Append a node at the end           | `Node** head, int data` | List updated with new node                        |
| `printList`        | Print linked list in normal order  | `Node* head`            | Prints elements from head to tail                 |
| `reverseTraversal` | Print linked list in reverse order | `Node* head`            | Prints elements from tail to head using recursion |

**Flow for Reverse Traversal:**

1. Call `reverseTraversal(head)`.
2. Recursively traverse to the end (`head == NULL`).
3. Print nodes while unwinding the recursion.

---

## 4. Main Function Overview

- Steps:

1. Initialize an empty linked list (`head = NULL`)
2. Append nodes: `10, 20, 30, 40`
3. Print **original list** using `printList()`
4. Print **reverse traversal** using `reverseTraversal()`
5. Free all allocated memory

- Sample linked list creation:

```c
appendNode(&head, 10);
appendNode(&head, 20);
appendNode(&head, 30);
appendNode(&head, 40);
```

---

## 5. Sample Output

```
Original Linked List:
10 -> 20 -> 30 -> 40 -> NULL

Reverse Traversal of Linked List:
40 -> 30 -> 20 -> 10 -> NULL
```

---

## 6. Reverse Traversal Example

**List:** `10 -> 20 -> 30 -> 40 -> NULL`

| Call Stack Level | Current Node | Action                 |
| ---------------- | ------------ | ---------------------- |
| 1                | 10           | Recurse to next (20)   |
| 2                | 20           | Recurse to next (30)   |
| 3                | 30           | Recurse to next (40)   |
| 4                | 40           | Recurse to next (NULL) |
| 4                | 40           | Print 40               |
| 3                | 30           | Print 30               |
| 2                | 20           | Print 20               |
| 1                | 10           | Print 10               |

**Result:** `40 -> 30 -> 20 -> 10 -> NULL`

---

## 7. Notes

- Uses **recursion** → no extra stack needed
- Memory is freed at the end → **no leaks**
- Demonstrates **modular linked list design**
- Can be extended for other operations like deletion, insertion, or search

---
