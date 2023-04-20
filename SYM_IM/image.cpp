#include <iostream>
#include <set>
#include <math.h>
#include <stdio.h>
#include <time.h> 

#include "aks_graph.h"

float x0_ = -2, x1_ = 2, y0_ = -2, y1_ = 2, dx = 0.5, dy = 0.5;
float a = 0, b = 0, h_x, h_y;
unsigned int N, N_SCAN, col, row, cages;

using std::cout, std::cin, std::endl, std::string;
using namespace aks;

void input_params();
float get_x(float x, float y);
float get_y(float x, float y);
unsigned int get_cell(float x, float y);

struct Point {
    float x, y;
};

int main() {
    input_params();

    Point start_point, scan_point, temp_point;
    std::set <unsigned int> result_cells;
    vertex* vert = new vertex[N+1];
    vertex** graph = new vertex* [N+1];
    for (int i = 0; i <= N; i++) {
        graph[i] = new vertex [N+1];
        for (int j = 0; j <= N; j++) {
            graph[i][j].num = -1;
        }
    }
    clock_t start = clock();
    for (int i = 0, j = 0; i < N; graph[++i][0].num = ++j) {
        start_point.x = x0_ + ((i % 8) - (i != 0)) * dx;
        start_point.y = y0_ + (i / 8) * dy;


        for (unsigned k = 0; k < N_SCAN; k++) {
            scan_point.x = start_point.x + h_x/2 + k*h_x;
            for (unsigned l = 0; l < N_SCAN; l++) {
                scan_point.y = start_point.y + h_y/2 + l*h_y;

                temp_point.x = get_x(scan_point.x, scan_point.y);
                temp_point.y = get_y(scan_point.x, scan_point.y);

                if (temp_point.x > x1_ || temp_point.x < x0_ || 
                    temp_point.y > y1_ || temp_point.y < y0_) goto end_loop;

                result_cells.insert(get_cell(temp_point.x, temp_point.y));
            }
        }        
        end_loop:

        int k = 0;
        for (auto it : result_cells) graph[i+1][++k].num = it;
        result_cells.clear();
    }

    write_graph(graph, N);

    for(int i = 1; i <= N; clear_color(vert, N), i++) {
        if (!vert[i].visited) {
            dfs(graph, i, vert, N);
        }
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    print_returnable();
    cout << "Время работы: " << seconds << endl;

    for (int i = 0; i <= N; i++) delete[] graph[i];
    delete[] graph;
    delete[] vert;

    return 0;
}

void input_params() {
    string input;
    cout << "Введите x0 (x0 == -2)" << endl;
    std::getline(cin, input);
    if (input != "") {
        x0_ = atof(input.c_str());
    }
    cout << "Введите x1 (x1 == 2)" << endl;
    std::getline(cin, input);
    if (input != "") {
        x1_ = atof(input.c_str());
    }
    cout << "Введите y0 (y0 == -2)"  << endl;
    std::getline(cin, input);
    if (input != "") {
        y0_ = atof(input.c_str());
    }
    cout << "Введите y1 (y1 == 2)" << endl;
    std::getline(cin, input);
    if (input != "") {
        y1_ = atof(input.c_str());
    }
    cout << "Введите a (a == 0)" << endl;
    std::getline(cin, input);
    if (input != "") {
        a = atof(input.c_str());
    }
    cout << "Введите b (b == 0)" << endl;
    std::getline(cin, input);
    if (input != "") {
        b = atof(input.c_str());
    }
    cout << "Введите dx (dx == 0.5)" << endl;
    std::getline(cin, input);
    if (input != "") {
        dx = atof(input.c_str());
    }
    cout << "Введите dy (dy == 0.5)" << endl;
    std::getline(cin, input);
    if (input != "") {
        dy = atof(input.c_str());
    }
    N = (x1_ - x0_)/dx*(y1_ - y0_)/dy;
    N_SCAN = 5;
    col = (x1_ - x0_) / dx;
    row = (y1_ - y0_) / dy;
    cages = col * row;
    h_x = dx/N_SCAN;
    h_y = dy/N_SCAN;
}

inline float get_x(float x, float y) {
    return x*x - y*y + a;
}

inline float get_y(float x, float y) {
    return 2*x*y + b;
}

inline unsigned int get_cell(float x, float y)  {

    int col_count = (x - x0_)/dx + (x != x1_);
    int row_count = (y - y0_)/dy - (y == y1_); 

    if (1 + x == 1 && x < 0) {
        col_count--;
    }
    if (1 + y == 1 && y < 0) {
        row_count--;
    }

    return col_count + row_count * col;
}