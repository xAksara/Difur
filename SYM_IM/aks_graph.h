#ifndef _AKS_GRAPH_H_
#define _AKS_GRAPH_H_ 1
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include "aks_graph.cpp"

void write_graph(vertex** graph, const unsigned int& N);
void dfs(vertex** graph, int now, vertex* vert, const unsigned int& N);
void print_returnable();
void clear_color(vertex* vert, const unsigned int& N);

#endif