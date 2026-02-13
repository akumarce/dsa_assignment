---

# Question 4: Doubly Linked List – Insert and Delete

## 1. Purpose

Implements a **doubly linked list** with functions to:

* **Insert a node after a given node**
* **Delete a specific node**
* **Traverse the list forward and backward**

Demonstrates **dynamic memory management** and **modular function design** in C.

---

## 2. Data Structure

### Node

Each node contains:

```c
typedef struct Node {
    int data;           // Value stored in the node
    struct Node* prev;  // Pointer to previous node
    struct Node* next;  // Pointer to next node
} Node;
```

- `data`: integer value
- `prev`: pointer to the previous node
- `next`: pointer to the next node

**Advantages:**

- Can traverse **both directions**
- Supports **dynamic insertion and deletion**
- Modular for extensions (search, sort, etc.)

---

## 3. Functions

| Function            | Purpose                            | Input                        | Output / Effect            |
| ------------------- | ---------------------------------- | ---------------------------- | -------------------------- |
| `createNode`        | Allocate and initialize a new node | `int data`                   | `Node*` pointer            |
| `appendNode`        | Add node at the end of the list    | `Node** head, int data`      | List updated               |
| `insertAfter`       | Insert node after a given node     | `Node* prevNode, int data`   | List updated               |
| `deleteNode`        | Delete a specific node             | `Node** head, Node* delNode` | List updated, memory freed |
| `printListForward`  | Print list from head to tail       | `Node* head`                 | Prints forward list        |
| `printListBackward` | Print list from tail to head       | `Node* tail`                 | Prints backward list       |

**Flow of Operations:**

1. Create initial nodes
2. Append nodes at the end
3. Insert node after a specific node
4. Delete a specific node
5. Print list forward and backward

---

## 4. Main Function Overview

- Steps:

1. Initialize an empty doubly linked list (`head = NULL`)
2. Append nodes: `10, 20, 30`
3. Print **initial list**
4. Insert `25` after node `20`
5. Delete node `20`
6. Print **forward and backward traversal**
7. Free all nodes

- Sample code snippet:

```c
appendNode(&head, 10);
appendNode(&head, 20);
appendNode(&head, 30);
insertAfter(head->next, 25);
deleteNode(&head, head->next);
```

---

## 5. Sample Output

```
Initial List:
Forward: 10 -> 20 -> 30 -> NULL

After inserting 25 after 20:
Forward: 10 -> 20 -> 25 -> 30 -> NULL

After deleting 20:
Forward: 10 -> 25 -> 30 -> NULL

Backward Traversal:
Backward: 30 -> 25 -> 10 -> NULL
```

---

## 6. Notes

- Supports **dynamic insertion and deletion** anywhere in the list
- Forward and backward traversal demonstrates **bidirectional linkage**
- Memory is freed at the end → **no leaks**
- Modular design ensures **easy extension for additional operations**

---
