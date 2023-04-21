//gomoklin

#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <string>
#include <fstream>
#include "my_node.cpp"

//const unsigned int N = 50; для отображения

using std::cout, std::cin, std::endl, std::string;
// using namespace aks;

void input_params(float &a, float &h);

int main() {
    float a = 0.4, h = 0.5;
    input_params(a, h);
    aks::PointList point_list(a);\

    point_list.push({10, 46});
    point_list.shreder(h);

    std::ofstream file;
    file.open("points.txt");
    aks::Node *node;
    for(int i = 0; node = point_list.get_at(i); i++) {
        file << node->point.x << " " << node->point.y << endl;
    }
    file.close();

    return 0;
}

void input_params(float &a, float &h) {
    string input;
    cout << "Введите a (a == 0.4)" << endl;
    std::getline(cin, input);
    if (input != "") {
        a = atof(input.c_str());
    }
    cout << "Введите h (h == 0.5)" << endl;
    std::getline(cin, input);
    if (input != "") {
        h = atof(input.c_str());
    }
}
