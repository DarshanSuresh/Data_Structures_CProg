/*
 * Graphs - Data Structure Implementation in C
 * 
 * This program demonstrates graph operations including:
 * - Graph representation (Adjacency Matrix and Adjacency List)
 * - Graph traversals (DFS and BFS)
 * - Shortest path algorithms (Dijkstra's algorithm)
 * - Minimum Spanning Tree (Prim's algorithm)
 * - Graph properties and utilities
 * 
 * Compilation: gcc -o graphs graphs.c
 * Execution: ./graphs
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

#define MAX_VERTICES 20
#define INF INT_MAX

// ===== ADJACENCY MATRIX REPRESENTATION =====

typedef struct {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} GraphMatrix;

// Initialize graph with adjacency matrix
void initGraphMatrix(GraphMatrix* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

// Add edge to adjacency matrix (undirected graph)
void addEdgeMatrix(GraphMatrix* graph, int src, int dest) {
    if (src >= 0 && src < graph->vertices && dest >= 0 && dest < graph->vertices) {
        graph->adjMatrix[src][dest] = 1;
        graph->adjMatrix[dest][src] = 1;  // For undirected graph
    }
}

// Add weighted edge to adjacency matrix
void addWeightedEdgeMatrix(GraphMatrix* graph, int src, int dest, int weight) {
    if (src >= 0 && src < graph->vertices && dest >= 0 && dest < graph->vertices) {
        graph->adjMatrix[src][dest] = weight;
        graph->adjMatrix[dest][src] = weight;  // For undirected graph
    }
}

// Display adjacency matrix
void displayMatrix(GraphMatrix* graph) {
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < graph->vertices; i++) {
        printf("%2d ", i);
        for (int j = 0; j < graph->vertices; j++) {
            printf("%2d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// ===== ADJACENCY LIST REPRESENTATION =====

typedef struct AdjListNode {
    int dest;
    int weight;
    struct AdjListNode* next;
} AdjListNode;

typedef struct {
    AdjListNode* head;
} AdjList;

typedef struct {
    int vertices;
    AdjList* array;
} GraphList;

// Create new adjacency list node
AdjListNode* createAdjListNode(int dest, int weight) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Initialize graph with adjacency list
GraphList* initGraphList(int vertices) {
    GraphList* graph = (GraphList*)malloc(sizeof(GraphList));
    graph->vertices = vertices;
    graph->array = (AdjList*)malloc(vertices * sizeof(AdjList));
    
    for (int i = 0; i < vertices; i++) {
        graph->array[i].head = NULL;
    }
    
    return graph;
}

// Add edge to adjacency list
void addEdgeList(GraphList* graph, int src, int dest, int weight) {
    // Add edge from src to dest
    AdjListNode* newNode = createAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    
    // Add edge from dest to src (for undirected graph)
    newNode = createAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Display adjacency list
void displayList(GraphList* graph) {
    printf("\nAdjacency List:\n");
    for (int v = 0; v < graph->vertices; v++) {
        AdjListNode* current = graph->array[v].head;
        printf("Vertex %d: ", v);
        while (current) {
            printf("-> %d(%d) ", current->dest, current->weight);
            current = current->next;
        }
        printf("\n");
    }
}

// ===== QUEUE FOR BFS =====

typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

bool isQueueEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, int data) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    
    if (isQueueEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) return -1;
    
    QueueNode* temp = queue->front;
    int data = temp->data;
    
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    
    free(temp);
    return data;
}

// ===== GRAPH TRAVERSALS =====

// DFS helper function
void DFSUtil(GraphMatrix* graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSUtil(graph, i, visited);
        }
    }
}

// Depth-First Search
void DFS(GraphMatrix* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    
    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFSUtil(graph, startVertex, visited);
    printf("\n");
}

// Breadth-First Search
void BFS(GraphMatrix* graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    Queue queue;
    initQueue(&queue);
    
    printf("BFS Traversal starting from vertex %d: ", startVertex);
    
    visited[startVertex] = true;
    enqueue(&queue, startVertex);
    
    while (!isQueueEmpty(&queue)) {
        int currentVertex = dequeue(&queue);
        printf("%d ", currentVertex);
        
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&queue, i);
            }
        }
    }
    printf("\n");
}

// ===== SHORTEST PATH ALGORITHMS =====

// Find vertex with minimum distance
int minDistance(int dist[], bool sptSet[], int vertices) {
    int min = INF, minIndex;
    
    for (int v = 0; v < vertices; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    
    return minIndex;
}

// Dijkstra's shortest path algorithm
void dijkstra(GraphMatrix* graph, int src) {
    int dist[MAX_VERTICES];
    bool sptSet[MAX_VERTICES];
    
    // Initialize distances and sptSet
    for (int i = 0; i < graph->vertices; i++) {
        dist[i] = INF;
        sptSet[i] = false;
    }
    
    dist[src] = 0;
    
    for (int count = 0; count < graph->vertices - 1; count++) {
        int u = minDistance(dist, sptSet, graph->vertices);
        sptSet[u] = true;
        
        for (int v = 0; v < graph->vertices; v++) {
            if (!sptSet[v] && graph->adjMatrix[u][v] && 
                dist[u] != INF && dist[u] + graph->adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->adjMatrix[u][v];
            }
        }
    }
    
    printf("\nShortest distances from vertex %d:\n", src);
    printf("Vertex\tDistance\n");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d\t", i);
        if (dist[i] == INF) {
            printf("INF\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }
}

// ===== MINIMUM SPANNING TREE =====

// Prim's algorithm for MST
void primMST(GraphMatrix* graph) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];
    
    // Initialize keys and mstSet
    for (int i = 0; i < graph->vertices; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }
    
    key[0] = 0;
    parent[0] = -1;
    
    for (int count = 0; count < graph->vertices - 1; count++) {
        int u = minDistance(key, mstSet, graph->vertices);
        mstSet[u] = true;
        
        for (int v = 0; v < graph->vertices; v++) {
            if (graph->adjMatrix[u][v] && mstSet[v] == false && 
                graph->adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph->adjMatrix[u][v];
            }
        }
    }
    
    printf("\nMinimum Spanning Tree (Prim's Algorithm):\n");
    printf("Edge\tWeight\n");
    int totalWeight = 0;
    for (int i = 1; i < graph->vertices; i++) {
        printf("%d - %d\t%d\n", parent[i], i, graph->adjMatrix[i][parent[i]]);
        totalWeight += graph->adjMatrix[i][parent[i]];
    }
    printf("Total weight of MST: %d\n", totalWeight);
}

// ===== GRAPH PROPERTIES =====

// Check if graph is connected
bool isConnected(GraphMatrix* graph) {
    bool visited[MAX_VERTICES] = {false};
    
    // Start DFS from vertex 0
    DFSUtil(graph, 0, visited);
    
    // Check if all vertices were visited
    for (int i = 0; i < graph->vertices; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

// Count edges in graph
int countEdges(GraphMatrix* graph) {
    int edges = 0;
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = i + 1; j < graph->vertices; j++) {
            if (graph->adjMatrix[i][j] != 0) {
                edges++;
            }
        }
    }
    return edges;
}

// Find degree of a vertex
int vertexDegree(GraphMatrix* graph, int vertex) {
    int degree = 0;
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjMatrix[vertex][i] != 0) {
            degree++;
        }
    }
    return degree;
}

// Create sample graph for demonstration
void createSampleGraph(GraphMatrix* graph) {
    initGraphMatrix(graph, 6);
    
    // Add edges to create a sample graph
    addWeightedEdgeMatrix(graph, 0, 1, 4);
    addWeightedEdgeMatrix(graph, 0, 2, 3);
    addWeightedEdgeMatrix(graph, 1, 2, 1);
    addWeightedEdgeMatrix(graph, 1, 3, 2);
    addWeightedEdgeMatrix(graph, 2, 3, 4);
    addWeightedEdgeMatrix(graph, 3, 4, 2);
    addWeightedEdgeMatrix(graph, 4, 5, 6);
}

int main() {
    GraphMatrix graph;
    GraphList* listGraph;
    int choice, vertices, src, dest, weight, startVertex;
    
    printf("=== Graph Data Structure Demo ===\n\n");
    
    // Initialize with sample graph
    createSampleGraph(&graph);
    listGraph = initGraphList(6);
    
    // Add same edges to list representation
    addEdgeList(listGraph, 0, 1, 4);
    addEdgeList(listGraph, 0, 2, 3);
    addEdgeList(listGraph, 1, 2, 1);
    addEdgeList(listGraph, 1, 3, 2);
    addEdgeList(listGraph, 2, 3, 4);
    addEdgeList(listGraph, 3, 4, 2);
    addEdgeList(listGraph, 4, 5, 6);
    
    printf("Sample graph created with 6 vertices and weighted edges.\n");
    
    do {
        printf("\n--- Graph Operations Menu ---\n");
        printf("Graph Representation:\n");
        printf("1. Display Adjacency Matrix\n");
        printf("2. Display Adjacency List\n");
        printf("3. Add Edge\n");
        printf("\nGraph Traversals:\n");
        printf("4. DFS Traversal\n");
        printf("5. BFS Traversal\n");
        printf("\nShortest Path:\n");
        printf("6. Dijkstra's Algorithm\n");
        printf("\nMinimum Spanning Tree:\n");
        printf("7. Prim's Algorithm\n");
        printf("\nGraph Properties:\n");
        printf("8. Check if Connected\n");
        printf("9. Count Edges\n");
        printf("10. Vertex Degree\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayMatrix(&graph);
                break;
                
            case 2:
                displayList(listGraph);
                break;
                
            case 3:
                printf("Enter source vertex (0-%d): ", graph.vertices-1);
                scanf("%d", &src);
                printf("Enter destination vertex (0-%d): ", graph.vertices-1);
                scanf("%d", &dest);
                printf("Enter weight: ");
                scanf("%d", &weight);
                addWeightedEdgeMatrix(&graph, src, dest, weight);
                addEdgeList(listGraph, src, dest, weight);
                printf("Edge added successfully!\n");
                break;
                
            case 4:
                printf("Enter starting vertex for DFS (0-%d): ", graph.vertices-1);
                scanf("%d", &startVertex);
                DFS(&graph, startVertex);
                break;
                
            case 5:
                printf("Enter starting vertex for BFS (0-%d): ", graph.vertices-1);
                scanf("%d", &startVertex);
                BFS(&graph, startVertex);
                break;
                
            case 6:
                printf("Enter source vertex for Dijkstra (0-%d): ", graph.vertices-1);
                scanf("%d", &startVertex);
                dijkstra(&graph, startVertex);
                break;
                
            case 7:
                primMST(&graph);
                break;
                
            case 8:
                if (isConnected(&graph)) {
                    printf("Graph is connected.\n");
                } else {
                    printf("Graph is NOT connected.\n");
                }
                break;
                
            case 9:
                printf("Number of edges in graph: %d\n", countEdges(&graph));
                break;
                
            case 10:
                printf("Enter vertex to find degree (0-%d): ", graph.vertices-1);
                scanf("%d", &startVertex);
                printf("Degree of vertex %d: %d\n", startVertex, vertexDegree(&graph, startVertex));
                break;
                
            case 0:
                printf("Freeing memory and exiting...\n");
                free(listGraph->array);
                free(listGraph);
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}