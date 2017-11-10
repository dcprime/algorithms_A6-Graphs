#pragma once
/* graphs.h: Header file for graph functions and definitions */

#define NUM_VERTICES 100

/******************* structure definitions ********************/

// Message structure
typedef struct message {
    char text[140];
    short sender_id;
    short receiver_id;
    char priority;
    short sequence;
    char other[25];
    short hash;
} Message;

// Graph structure
typedef struct graph {
    Message data[NUM_VERTICES];
    short vertex[NUM_VERTICES][NUM_VERTICES];
} Graph;

/******************** function prototypes ***********************/

// initialize graph
void graph_init(Graph *graph); 

// insert message into graph as a vertex
int graph_insert_vertex(Graph *graph, Message v);

// make connection between two messages as an edge
int graph_insert_edge(Graph *graph, Message v1, Message v2);

// check if connection exists between two messages
int graph_is_adjacent(Graph *graph, Message v1, Message v2);

// check if vertex exists in graph
int find_vertex(Graph *graph, Message v);