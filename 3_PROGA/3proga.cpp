//gomoklin

#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <string>
#include <fstream>

float a = 0.4, h = 0.5;
//const unsigned int N = 50; для отображения
unsigned int N = 50;

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

struct Vect {
    float x0 = 0;
    float x1 = 0;
    float y0 = 0;
    float y1 = 0;
    float length = sqrt((x1-x0)*(x1-x0) + (y1-y0)*(y1-y0));
    void calc_len() {
        length = sqrt((x1-x0)*(x1-x0) + (y1-y0)*(y1-y0));
    }
};

Vect s_next_vect(Vect v) {
    Vect ret;
    ret.x0 = v.x1;
    ret.y0 = v.y1;
    ret.x1 = X(v.x1, v.y1);
    ret.y1 = Y(v.x1, v.y1);
    ret.calc_len();
    return ret;
}

Vect r_next_vect(Vect v) {
    Vect ret;
    ret.x0 = v.x1;
    ret.y0 = v.y1;
    ret.x1 = x(v.x1, v.y1);
    ret.y1 = y(v.x1, v.y1);
    ret.calc_len();
    return ret;
}

int main() {
    Vect straight[N], reverse[N];
    straight[0] = {0, 0.1, 0, 0.086};
    reverse[0] = {0, 0.1, 0, 0.046};
    Vect s_temp_Vect, r_temp_Vect;

    std::ofstream s_file;
    std::ofstream r_file;
    s_file.open("s_file.txt");
    r_file.open("r_file.txt");
    s_file << straight[0].x1 << " " << straight[0].y1 << endl;
    r_file << reverse[0].x1 << " " << reverse[0].y1 << endl;
    for (int i = 1; i < N; i++) {
        straight[i] = s_next_vect(straight[i-1]);
        reverse[i] = r_next_vect(reverse[i-1]);
        s_file << straight[i].x1 << " " << straight[i].y1 << endl;
        r_file << reverse[i].x1 << " " << reverse[i].y1 << endl;
    }
    s_file.close();
    r_file.close();

    return 0;
}