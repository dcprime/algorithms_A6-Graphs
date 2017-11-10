/******************* graphs.cpp ************************/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "graphs.h"

void graph_init(Graph *graph) {
    
    // set all hash values and vertex values to NULL
    for (int i = 0; i < NUM_VERTICES; i++) {
        graph->data[i].hash = -1;
        for (int j = 0; j < NUM_VERTICES; j++) {
            graph->vertex[i][j] = 0;
        }
    }
}

// insert message into graph as a vertex
int graph_insert_vertex(Graph *graph, Message v) {

    // insert message into graph's first available data slot
    for (int i = 0; i < NUM_VERTICES; i++) {
        if (graph->data[i].hash == -1) {
            graph->data[i] = v;
            return (i);
        }
    }
    return (-1);
}

// make connection between two messages as an edge
int graph_insert_edge(Graph *graph, Message v1, Message v2) {

    // find the index numbers of messages v1 and v2
    short vertex1 = find_vertex(graph, v1);
    short vertex2 = find_vertex(graph, v2);
    
    // if either of the messages are not in the graph, return 0
    if (vertex1 == -1 || vertex2 == -1) return (0);
    
    // insert a directed edge between both messages
    graph->vertex[vertex1][vertex2] = 1;

    // to create undirected edges, uncomment the line below
    // graph->vertex[vertex2][vertex1] = 1;

    return (1);
}

// check if connection exists between two messages
int graph_is_adjacent(Graph *graph, Message v1, Message v2) {

    // find the index numbers of messages v1 and v2
    short vertex1 = find_vertex(graph, v1);
    short vertex2 = find_vertex(graph, v2);

    // if either of the messages are not in the graph, return 0
    if (vertex1 == -1 || vertex2 == -1) return (0);

    // if edge exists between both vertices, return 1
    if (graph->vertex[vertex1][vertex2] == 1) {
        return (1);
    }
    else {
        return (0);
    }
}

// check if vertex exists in graph
int find_vertex(Graph *graph, Message v) {
    for (int i = 0; i < NUM_VERTICES; i++) {
        if (graph->data[i].hash == v.hash) {
            return (i);
        }
    }
    return (-1);
}