#include <stdio.h>
#include <stdlib.h>

/* =========================================================
   Node Structure Definition
   - Represents a single node in a singly linked list
   ========================================================= */
typedef struct Node
{
    int data;          // Value stored in the node
    struct Node *next; // Pointer to the next node
} Node;

/* ---------------------------------------------------------
   Function: createNode
   Purpose : Allocate and initialize a new node
   Input   : int data
   Returns : Pointer to newly created Node
   --------------------------------------------------------- */
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* ---------------------------------------------------------
   Function: appendNode
   Purpose : Append a node to the end of the linked list
   Input   : Pointer to head pointer, int data
   --------------------------------------------------------- */
void appendNode(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

/* ---------------------------------------------------------
   Function: printList
   Purpose : Print the linked list in normal order
   Input   : Pointer to head
   --------------------------------------------------------- */
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ---------------------------------------------------------
   Function: reverseTraversal
   Purpose : Print the linked list in reverse order
   Input   : Pointer to head
   Method  : Recursion
   --------------------------------------------------------- */
void reverseTraversal(Node *head)
{
    if (head == NULL)
        return;
    reverseTraversal(head->next);
    printf("%d -> ", head->data);
}

/* =========================================================
   Main Function
   - Demonstrates linked list creation and reverse traversal
   ========================================================= */
int main()
{
    Node *head = NULL;

    // Create a sample linked list
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);
    appendNode(&head, 40);

    printf("Original Linked List:\n");
    printList(head);

    printf("\nReverse Traversal of Linked List:\n");
    reverseTraversal(head);
    printf("NULL\n");

    // Free memory
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
