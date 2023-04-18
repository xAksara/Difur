//gomoklin

#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <string>
#include <fstream>

float a = 0.4, h = 0.5;
//const unsigned int N = 50; для отображения
unsigned int N = 50, N_SCAN, col, row, cages;

using std::cout, std::cin, std::endl, std::string;

void input_params() {
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

float X(float x, float y) {
    return x + y + a*x*(1 - x*x);
}

float Y(float x, float y) {
    return y + a*x*(1 - x*x);
}

float x(float X, float Y) {
    return X - Y;
}

float y(float X, float Y) {
    return Y - a * (X - Y)*(1 - (X - Y)*(X - Y));
}

struct Point {
    float x;
    float y;
};

int main() {
    Point vector_a = {0.1, 0.086}; //alfa < 1
    Point vector_b = {0.1, 0.046}; //alfa > 1

    Point straight[N], reverse[N];
    straight[0] = {0.1, 0.086};
    reverse[0] = {0.1, 0.046};
    for (int i = 0; i < N; ++i) {
        straight[i] = {X(straight[i - 1].x, straight[i - 1].y)};
        reverse[i] = {X(reverse[i - 1].x, reverse[i - 1].y)};
    }
    return 0;
}