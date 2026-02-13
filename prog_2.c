#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* =========================================================
   Stack Structure Definition
   - Encapsulates stack properties and operations
   ========================================================= */
typedef struct
{
    int *items; // Array to store stack elements (for evaluation)
    char *ops;  // Array to store operators (for conversion)
    int top;
    int maxSize;
} Stack;

/* ---------------------------------------------------------
   Function: createIntStack
   Purpose : Allocate and initialize a stack for integers
   --------------------------------------------------------- */
Stack *createIntStack(int size)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->items = (int *)malloc(size * sizeof(int));
    s->ops = NULL; // not used for int stack
    s->top = -1;
    s->maxSize = size;
    return s;
}

/* ---------------------------------------------------------
   Function: createCharStack
   Purpose : Allocate and initialize a stack for characters
   --------------------------------------------------------- */
Stack *createCharStack(int size)
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->ops = (char *)malloc(size * sizeof(char));
    s->items = NULL; // not used for char stack
    s->top = -1;
    s->maxSize = size;
    return s;
}

/* ---------------------------------------------------------
   Generic Stack Operations
   --------------------------------------------------------- */
int isEmpty(Stack *s) { return s->top == -1; }

void pushInt(Stack *s, int val) { s->items[++(s->top)] = val; }
int popInt(Stack *s) { return s->items[(s->top)--]; }
int peekInt(Stack *s) { return s->items[s->top]; }

void pushChar(Stack *s, char c) { s->ops[++(s->top)] = c; }
char popChar(Stack *s) { return s->ops[(s->top)--]; }
char peekChar(Stack *s) { return s->ops[s->top]; }

/* ---------------------------------------------------------
   Operator Precedence and Utility
   --------------------------------------------------------- */
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

/* ---------------------------------------------------------
   Function: infixToPostfix
   Purpose : Converts infix expression to postfix
   --------------------------------------------------------- */
void infixToPostfix(const char *infix, char *postfix)
{
    Stack *s = createCharStack(strlen(infix));
    int k = 0; // index for postfix
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];

        if (isalnum(c))
        { // operand
            postfix[k++] = c;
        }
        else if (c == '(')
        {
            pushChar(s, c);
        }
        else if (c == ')')
        {
            while (!isEmpty(s) && peekChar(s) != '(')
                postfix[k++] = popChar(s);
            popChar(s); // remove '('
        }
        else if (isOperator(c))
        {
            while (!isEmpty(s) && precedence(peekChar(s)) >= precedence(c))
                postfix[k++] = popChar(s);
            pushChar(s, c);
        }
    }

    while (!isEmpty(s))
        postfix[k++] = popChar(s);

    postfix[k] = '\0';
    free(s->ops);
    free(s);
}

/* ---------------------------------------------------------
   Function: evaluatePostfix
   Purpose : Evaluates numeric postfix expression
   --------------------------------------------------------- */
int evaluatePostfix(const char *postfix)
{
    Stack *s = createIntStack(strlen(postfix));
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char c = postfix[i];
        if (isdigit(c))
        {
            pushInt(s, c - '0'); // convert char to int
        }
        else if (isOperator(c))
        {
            int b = popInt(s);
            int a = popInt(s);
            switch (c)
            {
            case '+':
                pushInt(s, a + b);
                break;
            case '-':
                pushInt(s, a - b);
                break;
            case '*':
                pushInt(s, a * b);
                break;
            case '/':
                pushInt(s, a / b);
                break;
            case '^':
            {
                int res = 1;
                for (int j = 0; j < b; j++)
                    res *= a;
                pushInt(s, res);
                break;
            }
            }
        }
    }
    int result = popInt(s);
    free(s->items);
    free(s);
    return result;
}

/* =========================================================
   Main Function
   - Demonstrates infix to postfix conversion and evaluation
   ========================================================= */
int main()
{
    const char *expressions[] = {
        "3+4*2",
        "(1+2)*(3+4)",
        "5*(6+2)-8/4"};

    int n = sizeof(expressions) / sizeof(expressions[0]);

    printf("===== Infix to Postfix Converter & Evaluator =====\n\n");

    for (int i = 0; i < n; i++)
    {
        char postfix[100];
        printf("Infix: %s\n", expressions[i]);
        infixToPostfix(expressions[i], postfix);
        printf("Postfix: %s\n", postfix);
        printf("Evaluation: %d\n\n", evaluatePostfix(postfix));
    }

    return 0;
}
