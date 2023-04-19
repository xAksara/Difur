#include <iostream>
#include <set>
#include <math.h>
#include "aks_graph.h"
//cbkmyst rjvgjytyns? rjvgjytyns cbkmyjq cdzpyjcnb
float x0_ = -2, x1_ = 2, y0_ = -2, y1_ = 2, dx = 0.5, dy = 0.5, a = 0, b = 0;
 //для отображения
unsigned int N, N_SCAN, col, row, cages;

using std::cout, std::cin, std::endl, std::string;

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
}

inline float get_x(float x, float y) {
    return x*x - y*y + a;
}

inline float get_y(float x, float y) {
    return 2*x*y + b;
}
// у - у0 округляет гавно
inline unsigned int get_cell(float x, float y) {

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

struct Point {
    float x, y;
};

int main() {
    float x, y, b, c, h_x, h_y;
    unsigned int a, cur_cell;
    Point start_point;
    Point scan_point;
    Point temp_point;
    std::set <unsigned int> result_cells;
    // std::vector<Point> points;
    // points.push_back(Point{0.1, 0.2}); //emplace_back
    input_params();

    vertex **graph = new vertex* [N+1];
    for (int i = 0; i <= N; i++) {
        graph[i] = new vertex [N+1];
        for (int j = 0; j <= N; j++) {
            graph[i][j].num = -1;
        }
    }

    for (int i = 0; i <= N; i++) {
    }
    h_x = dx/N_SCAN;
    h_y = dy/N_SCAN;

    for (int i = 0, j = 0; i < N; graph[++i][0].num = ++j) {
        start_point.x = x0_ + ((i % 8) - (i != 0)) * dx;
        start_point.y = y0_ + (i / 8) * dy;


        for (unsigned j = 0; j < N_SCAN; j++) {
            scan_point.x = start_point.x + h_x/2 + j*h_x;
            for (unsigned k = 0; k < N_SCAN; k++) {
                scan_point.y = start_point.y + h_y/2 + k*h_y;

                temp_point.x = get_x(scan_point.x, scan_point.y);
                temp_point.y = get_y(scan_point.x, scan_point.y);

                if (temp_point.x > x1_ || temp_point.x < x0_ || temp_point.y > y1_ || temp_point.y < y0_) goto end_loop;

                a = get_cell(temp_point.x, temp_point.y);
                result_cells.insert(a);
            }
        }        
        end_loop:

        int k = 0;
        for (std::set <unsigned int> :: iterator it = result_cells.begin(); it != result_cells.end(); it++) {
            graph[i+1][++k].num = *it;
        } 
        result_cells.clear();
    }

    write_graph(graph);
    int j = 0;
    for(int i = 1; i <= N; clear_color(), i++) {
        if (!vert[i].visited) {
            dfs(graph, i);
            j++;
        }
    }
    print_returnable();

    for (int i = 0; i <= N; i++) {
        delete[] graph[i];
    }
    delete[] graph;
    delete[] vert;

    return 0;
}