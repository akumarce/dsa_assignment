# Question 2: Infix to Postfix Converter and Evaluator

## 1. Purpose

Converts a mathematical expression from **infix notation** (e.g., `3+4*2`) to **postfix notation** (Reverse Polish Notation) and evaluates its **numeric result**.

- **Infix**: Operators are between operands (`a + b`)
- **Postfix**: Operators after operands (`a b +`)
- **Stack (LIFO)** is used both for conversion and evaluation to handle **operator precedence** efficiently.

---

## 2. Data Structures

### Stack

Two stack types are implemented using a C struct:

```c
typedef struct {
    int *items;    // Array storing integers (for evaluation)
    char *ops;     // Array storing operators (for conversion)
    int top;       // Index of the top element
    int maxSize;   // Maximum capacity
} Stack;
```

- `items`: dynamically allocated array for integer evaluation
- `ops`: dynamically allocated array for operator conversion
- `top`: index of the current top element
- `maxSize`: maximum number of elements

**Design advantages:**

- Modular: separate stacks for evaluation and conversion
- Dynamic sizing based on expression length
- Proper memory management with `free()`

---

## 3. Functions

| Function               | Purpose                                 | Input                              | Output                         |
| ---------------------- | --------------------------------------- | ---------------------------------- | ------------------------------ |
| `createIntStack`       | Allocate and initialize integer stack   | `int size`                         | `Stack*` pointer               |
| `createCharStack`      | Allocate and initialize character stack | `int size`                         | `Stack*` pointer               |
| `pushInt` / `pushChar` | Push element onto respective stack      | `Stack* s, int/char val`           | None                           |
| `popInt` / `popChar`   | Pop element from respective stack       | `Stack* s`                         | Top element                    |
| `peekInt` / `peekChar` | Peek top element without removing       | `Stack* s`                         | Top element                    |
| `precedence`           | Get operator precedence                 | `char op`                          | Precedence value (int)         |
| `isOperator`           | Check if a character is an operator     | `char c`                           | `1` if operator, `0` otherwise |
| `infixToPostfix`       | Convert infix expression to postfix     | `const char* infix, char* postfix` | Postfix string                 |
| `evaluatePostfix`      | Evaluate numeric postfix expression     | `const char* postfix`              | Integer result                 |

**Flow:**

1. For **conversion**: scan infix expression
   - Operand → append to postfix
   - Operator → push to stack with precedence handling
   - Parentheses → push/pop accordingly

2. For **evaluation**: scan postfix expression
   - Operand → push to integer stack
   - Operator → pop two values, compute, push result

---

## 4. Main Function Overview

- Test expressions:

```c
"3+4*2"
"(1+2)*(3+4)"
"5*(6+2)-8/4"
```

- Steps per expression:
  1. Print infix expression
  2. Call `infixToPostfix()` → generate postfix
  3. Print postfix expression
  4. Call `evaluatePostfix()` → compute numeric result
  5. Print result

---

## 5. Sample Output

```
===== Infix to Postfix Converter & Evaluator =====

Infix: 3+4*2
Postfix: 342*+
Evaluation: 11

Infix: (1+2)*(3+4)
Postfix: 12+34+*
Evaluation: 21

Infix: 5*(6+2)-8/4
Postfix: 562+*84/-
Evaluation: 38
```

---

## 6. Stack Operation Example

**Expression:** `"3+4*2"`

| Character | Stack State (Operators) | Postfix    | Action                              |
| --------- | ----------------------- | ---------- | ----------------------------------- |
| 3         | []                      | 3          | Operand → append                    |
| +         | [+]                     | 3          | Operator → push                     |
| 4         | [+]                     | 3 4        | Operand → append                    |
| \*        | [+ *]                   | 3 4        | Operator → push (higher precedence) |
| 2         | [+ *]                   | 3 4 2      | Operand → append                    |
| End       | []                      | 3 4 2 \* + | Pop remaining operators → append    |

**Postfix:** `342*+`
**Evaluation:** `3 + (4 * 2) = 11`

---

## 7. Notes

- Supports single-digit numeric operands (can be extended to multi-digit).
- Stack structures provide **modularity** and **dynamic sizing**.
- Proper memory management ensures **no memory leaks**.
- Operator precedence and parentheses are handled correctly.

---
