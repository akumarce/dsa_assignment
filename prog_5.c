#include <stdio.h>
#include <stdlib.h>

/* =========================================================
   Graph Structure Definition
   - Represents an undirected graph using adjacency matrix
   ========================================================= */
typedef struct
{
    int V;           // Number of vertices
    int **adjMatrix; // Adjacency matrix
} Graph;

/* ---------------------------------------------------------
   Function: createGraph
   Purpose : Allocate and initialize a graph with V vertices
   Input   : int V
   Returns : Pointer to Graph
   --------------------------------------------------------- */
Graph *createGraph(int V)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->V = V;

    g->adjMatrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        g->adjMatrix[i] = (int *)calloc(V, sizeof(int)); // initialize to 0
    }
    return g;
}

/* ---------------------------------------------------------
   Function: addEdge
   Purpose : Add an undirected edge between src and dest
   Input   : Graph*, int src, int dest
   --------------------------------------------------------- */
void addEdge(Graph *g, int src, int dest)
{
    if (src >= g->V || dest >= g->V || src < 0 || dest < 0)
        return;
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1; // undirected
}

/* ---------------------------------------------------------
   DFS using recursion
   --------------------------------------------------------- */
void DFSUtil(Graph *g, int v, int *visited)
{
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < g->V; i++)
    {
        if (g->adjMatrix[v][i] && !visited[i])
            DFSUtil(g, i, visited);
    }
}

void DFS(Graph *g, int start)
{
    int *visited = (int *)calloc(g->V, sizeof(int));
    printf("DFS starting from node %d: ", start);
    DFSUtil(g, start, visited);
    printf("\n");
    free(visited);
}

/* ---------------------------------------------------------
   BFS using queue
   --------------------------------------------------------- */
typedef struct
{
    int *items;
    int front;
    int rear;
    int size;
} Queue;

Queue *createQueue(int size)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->items = (int *)malloc(size * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int val)
{
    q->items[++(q->rear)] = val;
    q->size++;
}

int dequeue(Queue *q)
{
    q->size--;
    return q->items[q->front++];
}

int isEmpty(Queue *q)
{
    return q->size == 0;
}

void BFS(Graph *g, int start)
{
    int *visited = (int *)calloc(g->V, sizeof(int));
    Queue *q = createQueue(g->V);

    visited[start] = 1;
    enqueue(q, start);

    printf("BFS starting from node %d: ", start);

    while (!isEmpty(q))
    {
        int v = dequeue(q);
        printf("%d ", v);

        for (int i = 0; i < g->V; i++)
        {
            if (g->adjMatrix[v][i] && !visited[i])
            {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    printf("\n");

    free(visited);
    free(q->items);
    free(q);
}

/* =========================================================
   Main Function
   - Demonstrates BFS and DFS on an example undirected graph
   ========================================================= */
int main()
{
    int V = 6; // number of vertices
    Graph *g = createGraph(V);

    // Add edges
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 4);
    addEdge(g, 3, 5);
    addEdge(g, 4, 5);

    // Perform traversals
    DFS(g, 0);
    BFS(g, 0);

    // Free adjacency matrix
    for (int i = 0; i < V; i++)
        free(g->adjMatrix[i]);
    free(g->adjMatrix);
    free(g);

    return 0;
}
