#ifndef _AKS_GRAPH_H_
#define _AKS_GRAPH_H_ 1
#include <vector>
#include <set>

namespace aks
{
    // static std::vector<unsigned int> road;
    // static std::set<unsigned int> returnable;
    struct vertex {
        unsigned int num = 0;
        unsigned int color = 0;
        bool visited = 0;
    };

    void write_graph(vertex** graph, const unsigned int& N);
    void dfs(vertex** graph, int now, vertex* vert, const unsigned int& N);
    void print_returnable();
    void clear_color(vertex* vert, const unsigned int& N);
};
#endif