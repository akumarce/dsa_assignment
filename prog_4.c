#include <stdio.h>
#include <stdlib.h>

/* =========================================================
   Node Structure Definition
   - Represents a node in a doubly linked list
   ========================================================= */
typedef struct Node
{
    int data;          // Value stored in the node
    struct Node *prev; // Pointer to previous node
    struct Node *next; // Pointer to next node
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/* ---------------------------------------------------------
   Function: appendNode
   Purpose : Append a node at the end of the list
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
    newNode->prev = temp;
}

/* ---------------------------------------------------------
   Function: insertAfter
   Purpose : Insert a node after a given node
   Input   : Pointer to previous node, int data
   --------------------------------------------------------- */
void insertAfter(Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        printf("Previous node cannot be NULL\n");
        return;
    }
    Node *newNode = createNode(data);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != NULL)
        prevNode->next->prev = newNode;
    prevNode->next = newNode;
}

/* ---------------------------------------------------------
   Function: deleteNode
   Purpose : Delete a given node from the list
   Input   : Pointer to head pointer, Node* to delete
   --------------------------------------------------------- */
void deleteNode(Node **head, Node *delNode)
{
    if (*head == NULL || delNode == NULL)
        return;

    if (*head == delNode)
        *head = delNode->next;

    if (delNode->next != NULL)
        delNode->next->prev = delNode->prev;

    if (delNode->prev != NULL)
        delNode->prev->next = delNode->next;

    free(delNode);
}

/* ---------------------------------------------------------
   Function: printListForward
   Purpose : Print the list from head to tail
   Input   : Node* head
   --------------------------------------------------------- */
void printListForward(Node *head)
{
    Node *temp = head;
    printf("Forward: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ---------------------------------------------------------
   Function: printListBackward
   Purpose : Print the list from tail to head
   Input   : Node* tail
   --------------------------------------------------------- */
void printListBackward(Node *tail)
{
    Node *temp = tail;
    printf("Backward: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

/* =========================================================
   Main Function
   - Demonstrates doubly linked list insertion and deletion
   ========================================================= */
int main()
{
    Node *head = NULL;

    // Create initial list: 10, 20, 30
    appendNode(&head, 10);
    appendNode(&head, 20);
    appendNode(&head, 30);

    printf("Initial List:\n");
    printListForward(head);

    // Insert 25 after second node (20)
    insertAfter(head->next, 25);
    printf("\nAfter inserting 25 after 20:\n");
    printListForward(head);

    // Delete node with value 20
    deleteNode(&head, head->next);
    printf("\nAfter deleting 20:\n");
    printListForward(head);

    // Print backward from tail
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    printListBackward(tail);

    // Free all remaining nodes
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
