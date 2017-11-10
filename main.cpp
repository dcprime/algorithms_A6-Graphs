/******************* main.cpp ************************/

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "graphs.h"

void main(int argc, char *argv[]) {

    // create new graph
    Graph graph1;
    Graph *graph_ptr = &graph1;
    graph_init(graph_ptr);

    // seed RNG
    time_t seed;
    seed = time(NULL);
    srand(time(NULL));

    // populate graph with vertecies
    for (short i = 0; i < NUM_VERTICES; i++) {
        Message m = { "some text", 01, 02, 'A', 00, "filler", i };
        if (graph_insert_vertex(graph_ptr, m) == -1) {
            printf("vertex not inserted - check parameters\n\n");
            break;
        }
    }

    // randomly connect each vertex to 2-6 other vertices
    for (short i = 0; i < NUM_VERTICES; i++) {
        //generate a random number between 2 and 6 for number of edges to create
        int edges = (2 + rand() % (7 - 2));
        
        // connect each vertex to a random other vertex "edges" times
        for (short j = 0; j < edges; j++) {
            int rand_vertex = (rand() % NUM_VERTICES + 1);
            if (!graph_insert_edge(graph_ptr, graph1.data[i], graph1.data[rand_vertex])) {
                printf("Edge not created - please review data\n");
                break;
            }
        }
    }

    // display the adjacency information for each vertex
    for (short i = 0; i < NUM_VERTICES; i++) {
        printf("Node %d connects to: ", i);
        for (short j = 0; j < NUM_VERTICES; j++) {
            if (graph_is_adjacent(graph_ptr, graph1.data[i], graph1.data[j])) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    system("pause");
}