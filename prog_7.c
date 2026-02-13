#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* =========================================================
   Dijkstra's Algorithm Implementation
   - Finds shortest path from source to all vertices
   - Uses adjacency matrix representation
   ========================================================= */

#define MAX_VERTICES 100 // Maximum number of vertices

// Function to find vertex with minimum distance not yet processed
int minDistance(int dist[], int visited[], int V)
{
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra algorithm
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int V, int src)
{
    int dist[V];    // Distance from source to vertex
    int visited[V]; // Visited vertices

    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited, V);
        if (u == -1)
            break; // remaining vertices are inaccessible
        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print shortest distances
    printf("Vertex\tDistance from Source %d\n", src);
    for (int i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }
}

/* =========================================================
   Main Function
   - Demonstrates Dijkstra on a weighted graph
   ========================================================= */
int main()
{
    int V = 6; // Number of vertices

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    // Example weighted undirected graph
    // Edge list: src, dest, weight
    int edges[][3] = {
        {0, 1, 7},
        {0, 2, 9},
        {0, 5, 14},
        {1, 2, 10},
        {1, 3, 15},
        {2, 3, 11},
        {2, 5, 2},
        {3, 4, 6},
        {4, 5, 9}};
    int E = sizeof(edges) / sizeof(edges[0]);

    // Build adjacency matrix
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        graph[u][v] = w;
        graph[v][u] = w; // undirected
    }

    int source = 0;
    dijkstra(graph, V, source);

    return 0;
}
