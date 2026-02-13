#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* =========================================================
   Stack Structure Definition
   - Encapsulates the stack properties and operations
   - Dynamic size based on expression length
   ========================================================= */
typedef struct
{
    char *items; // Array to store stack elements
    int top;     // Index of the top element
    int maxSize; // Maximum capacity of the stack
} Stack;

/* ---------------------------------------------------------
   Function: createStack
   Purpose : Allocate and initialize a stack of given size
   Input   : size -> maximum number of elements
   Returns : pointer to created Stack
   --------------------------------------------------------- */
Stack *createStack(int size)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->items = (char *)malloc(size * sizeof(char));
    s->top = -1;
    s->maxSize = size;
    return s;
}

/* ---------------------------------------------------------
   Function: push
   Purpose : Push a character onto the stack
   Input   : Stack pointer, character to push
   Returns : 1 if successful, 0 if overflow
   --------------------------------------------------------- */
int push(Stack *s, char c)
{
    if (s->top == s->maxSize - 1)
        return 0; // Stack overflow
    s->items[++(s->top)] = c;
    return 1;
}

/* ---------------------------------------------------------
   Function: pop
   Purpose : Pop a character from the stack
   Input   : Stack pointer
   Returns : top element if stack not empty, '\0' if empty
   --------------------------------------------------------- */
char pop(Stack *s)
{
    if (s->top == -1)
        return '\0'; // Stack underflow
    return s->items[(s->top)--];
}

/* ---------------------------------------------------------
   Function: isEmpty
   Purpose : Check if stack is empty
   Input   : Stack pointer
   Returns : 1 if empty, 0 otherwise
   --------------------------------------------------------- */
int isEmpty(Stack *s)
{
    return s->top == -1;
}

/* ---------------------------------------------------------
   Function: isMatching
   Purpose : Check if opening and closing brackets match
   Input   : open -> opening bracket, close -> closing bracket
   Returns : 1 if match, 0 otherwise
   --------------------------------------------------------- */
int isMatching(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

/* ---------------------------------------------------------
   Function: isBalanced
   Purpose : Check if a given mathematical expression
             has balanced parentheses
   Input   : expr -> string expression
   Returns : 1 if balanced, 0 if not
   --------------------------------------------------------- */
int isBalanced(const char *expr)
{
    int len = strlen(expr);
    Stack *s = createStack(len); // Stack size = expression length

    for (int i = 0; i < len; i++)
    {
        char c = expr[i];

        // Push opening brackets
        if (c == '(' || c == '{' || c == '[')
            push(s, c);

        // Match closing brackets
        else if (c == ')' || c == '}' || c == ']')
        {
            if (isEmpty(s) || !isMatching(pop(s), c))
            {
                free(s->items); // Free allocated memory
                free(s);
                return 0; // Not balanced
            }
        }
        // Ignore other characters
    }

    int balanced = isEmpty(s); // If stack empty -> balanced
    free(s->items);            // Free memory
    free(s);
    return balanced;
}

/* =========================================================
   Main Function
   - Tests multiple expressions
   - Prints results in clear format
   ========================================================= */
int main()
{
    const char *expressions[] = {
        "a + (b - c) * (d",
        "m + [a - b * (c + d * {m)]",
        "a + (b - c)"};

    int n = sizeof(expressions) / sizeof(expressions[0]);

    printf("===== Balanced Parentheses Checker =====\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("Expression: %s\n", expressions[i]);
        if (isBalanced(expressions[i]))
            printf("Result: Balanced\n\n");
        else
            printf("Result: Not Balanced\n\n");
    }

    return 0;
}
