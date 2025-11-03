#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 20
#define TRUE 1
#define FALSE 0

// Global variables for the adjacency matrix, visited array, and queue
int g[MAX][MAX];   // Graph represented as an adjacency matrix
int visit[MAX];    // Keeps track of visited vertices
int q[MAX];        // Queue used for BFS
int n;             // Number of vertices in the graph

// Function declarations
void initialize(void);
void create(void);
void traverse(void);
void bfs(int startVertex);
void error(const char *msg);

int main(void)
{
    int startVertex;

    // Step 1: Initialize all arrays to zero or false
    initialize();

    // Step 2: Create the graph (directed or undirected)
    create();

    // Step 3: Display the adjacency matrix of the created graph
    printf("\n\nAdjacency Matrix of the Graph:\n");
    traverse();

    // Step 4: Ask user for the starting vertex for BFS
    printf("\nEnter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    // Step 5: Validate the input vertex
    if (startVertex >= n || startVertex < 0)
        error("Invalid vertex!");

    // Step 6: Perform and display BFS traversal
    printf("\nBreadth First Search (BFS) Traversal:\n");
    bfs(startVertex);

    return 0;
}

/*
 * Function: initialize
 * --------------------
 * Initializes the adjacency matrix and visited array to default values.
 * Initially, there are no edges and no visited vertices.
 */
void initialize(void)
{
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++)
            g[i][j] = FALSE;   // No edges initially
        visit[i] = FALSE;       // Mark all vertices as unvisited
    }
}

/*
 * Function: create
 * ----------------
 * Creates a graph by taking user input for edges.
 * The user can choose whether the graph is directed or undirected.
 * Edges are entered as pairs of vertex numbers (v1, v2).
 */
void create(void)
{
    int v1, v2;
    char ch;
    int directed = 0;

    printf("\nThis program creates a graph and performs BFS traversal.\n");
    printf("Press 'D' for Directed graph or 'U' for Undirected graph: ");
    ch = toupper(getchar());  // Take user choice and convert to uppercase

    // If the user chooses 'D', mark graph as directed
    if (ch == 'D')
        directed = 1;

    // Get total number of vertices
    printf("\nEnter number of vertices: ");
    scanf("%d", &n);

    // Input edges
    printf("\nEnter edges (v1 v2). Enter -1 -1 to stop:\n");
    while (1)
    {
        scanf("%d %d", &v1, &v2);

        // Sentinel value to stop input
        if (v1 == -1 && v2 == -1)
            break;

        // Check for invalid vertices
        if (v1 >= n || v2 >= n || v1 < 0 || v2 < 0)
            error("Invalid vertex value!");

        // Add edge to adjacency matrix
        g[v1][v2] = TRUE;
        if (!directed)
            g[v2][v1] = TRUE;  // Add reverse edge for undirected graphs
    }
}

/*
 * Function: traverse
 * ------------------
 * Displays the adjacency matrix of the current graph.
 * Each row represents connections from one vertex to all others.
 */
void traverse(void)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf(" %d", g[i][j]);
        printf("\n");
    }
}

/*
 * Function: bfs
 * -------------
 * Performs Breadth-First Search traversal starting from a given vertex.
 * BFS explores all neighbors of a vertex before moving to the next level.
 * A queue is used to keep track of the order of exploration.
 */
void bfs(int startVertex)
{
    int front = 0, rear = -1;

    // Enqueue the starting vertex and mark it as visited
    q[++rear] = startVertex;
    visit[startVertex] = TRUE;

    // Continue until queue is empty
    while (front <= rear)
    {
        int v = q[front++];  // Dequeue a vertex
        printf(" %d", v);    // Print the visited vertex

        // Explore all adjacent vertices
        for (int i = 0; i < n; i++) {
            // If there’s a connection and vertex is not yet visited
            if (g[v][i] == TRUE && !visit[i]) {
                q[++rear] = i;       // Enqueue the vertex
                visit[i] = TRUE;     // Mark it as visited
            }
        }
    }
}

/*
 * Function: error
 * ---------------
 * Displays an error message and terminates the program.
 * Used for invalid inputs like wrong vertex numbers.
 */
void error(const char *msg)
{
    printf("\nError: %s\n", msg);
    exit(1);
}
