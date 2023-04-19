#ifndef _AKS_GRAPH_H_
#define _AKS_GRAPH_H_ 1
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include "aks_graph.cpp"

void write_graph(vertex** graph);
void dfs(vertex** graph, int now);
void print_returnable();
void clear_color();

#endif