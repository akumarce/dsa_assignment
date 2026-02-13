# Question 1: Balanced Parentheses Checker Using Stack

## 1. Purpose

Checks whether a mathematical expression contains **balanced parentheses**.
Balanced parentheses require that each opening bracket `(`, `[`, `{` has a corresponding closing bracket `)`, `]`, `}` in the correct order.

A **stack (LIFO)** data structure is used to track and match brackets efficiently.

---

## 2. Data Structure

### Stack

A **stack is implemented using a C struct**:

```c
typedef struct {
    char *items;    // Array storing stack elements
    int top;        // Index of the top element
    int maxSize;    // Maximum capacity
} Stack;
```

- `items`: dynamically allocated array for brackets
- `top`: index of the current top element
- `maxSize`: maximum number of elements

This design provides **modularity**, **dynamic sizing**, and **memory safety**.

---

## 3. Functions

| Function      | Purpose                         | Input                   | Output                          |
| ------------- | ------------------------------- | ----------------------- | ------------------------------- |
| `createStack` | Allocate and initialize stack   | `int size`              | `Stack*` pointer                |
| `push`        | Push a character onto the stack | `Stack* s, char c`      | `1` if success, `0` if overflow |
| `pop`         | Remove and return top character | `Stack* s`              | Top character or `\0` if empty  |
| `isEmpty`     | Check if stack is empty         | `Stack* s`              | `1` if empty, `0` otherwise     |
| `isMatching`  | Check if brackets match         | `char open, char close` | `1` if match, `0` otherwise     |
| `isBalanced`  | Check if expression is balanced | `const char* expr`      | `1` if balanced, `0` if not     |

**Flow:**

1. Stack is created with size equal to the expression length.

2. Each character in the expression is processed:
   - **Opening brackets** → pushed onto stack
   - **Closing brackets** → popped and checked against top
   - Mismatch or empty stack → expression **not balanced**

3. Stack empty at end → expression **balanced**

---

## 4. Main Function Overview

- Test expressions:

```c
"a + (b - c) * (d"
"m + [a - b * (c + d * {m)]"
"a + (b - c)"
```

- Steps per expression:
  1. Print expression
  2. Call `isBalanced()`
  3. Print `"Balanced"` or `"Not Balanced"`

---

## 5. Sample Output

```
===== Balanced Parentheses Checker =====

Expression: a + (b - c) * (d
Result: Not Balanced

Expression: m + [a - b * (c + d * {m)]
Result: Not Balanced

Expression: a + (b - c)
Result: Balanced
```

---

## 6. Stack Operation Example

**Expression:** `"a + (b - c) * (d"`

| Character | Stack State | Action                         |
| --------- | ----------- | ------------------------------ |
| a         | []          | Ignore                         |
| +         | []          | Ignore                         |
| (         | [ ( ]       | Push                           |
| b         | [ ( ]       | Ignore                         |
| -         | [ ( ]       | Ignore                         |
| c         | [ ( ]       | Ignore                         |
| )         | []          | Pop and match → OK             |
| \*        | []          | Ignore                         |
| (         | [ ( ]       | Push                           |
| d         | [ ( ]       | Ignore                         |
| End       | [ ( ]       | Stack not empty → Not Balanced |

**Result:** Not Balanced

---

## 7. Notes

- Non-bracket characters are ignored.
- Stack is dynamically allocated → supports expressions of **any length**.
- Memory is freed properly → **no leaks**.

---
