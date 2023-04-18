#include <math.h>
#include <fstream>
#include <iostream>
 
using std::cin;
using std::cout;
using std::endl;
using std::string;

float dt = 0.01, delta = 0.25, gamma_ = 0.3, beta = 1, alfa = -1, omega = 1, x = 0, y = 0.5;
int N = 5000;

float func(float x, float y, float t) {
    return gamma_*cos(omega*t)- delta*y - alfa*x - beta*x*x*x;
}
 
float rk_y(float x, float y, float t) {
    float f1, f2, f3, f4;

    f1 = func(x, y, t);
    f2 = func(x + dt/2, y + f1*dt/2, t);
    f3 = func(x + dt/2, y + f2*dt/2, t);
    f4 = func(x + dt, y + f3*dt, t);
    return y + (f1 + 2*f2 + 2*f3 + f4) * dt / 6;
 }

float rk_x(float x, float y) {
    return x + dt*y; // y = dx/dt
}

float x_n(float x, float y) {
    return x + dt*y; 
}

float y_n(float x, float y, float t) {
    return y + dt*func(x, y, t);
}

void input_params() {
    string input;
    cout << "Введите x (x == 0)" << endl;
    std::getline(cin, input);
    if (input != "") {
        x = atof(input.c_str());
    }
    cout << "Введите y (y == 0.5)" << endl;
    std::getline(cin, input);
    if (input != "") {
        y = atof(input.c_str());
    }
    cout << "Введите шаг (delta_t == 0.01)" << endl;
    std::getline(cin, input);
    if (input != "") {
        dt = atof(input.c_str());
    }
    cout << "Введите delta (k == 0.25)" << endl;
    std::getline(cin, input);
    if (input != "") {
        delta = atof(input.c_str());
    }
    cout << "Введите gamma_ (gamma_ == 0.03)"  << endl;
    std::getline(cin, input);
    if (input != "") {
        gamma_ = atof(input.c_str());
    }
    cout << "Введите alfa (alfa == -1)" << endl;
    std::getline(cin, input);
    if (input != "") {
        alfa = atof(input.c_str());
    }
    cout << "Введите beta (beta == 1)" << endl;
    std::getline(cin, input);
    if (input != "") {
        beta = atof(input.c_str());
    }
    cout << "Введите omega (omega == 1)" << endl;
    std::getline(cin, input);
    if (input != "") {
        omega = atof(input.c_str());
    }
    cout << "Введите N (N == 5000)" << endl;
    std::getline(cin, input);
    if (input != "") {
        N = atof(input.c_str());
    }
}

int main(int argc, char** argv) {
    float t = 0;
//    float x_next = 0, y_next = 0;
    int algo;

    if  (argc != 2) {
        cout << "Неправильные аргументы, введите только имя файла для запии последовательности" << endl;
        return 1;
    }
    cout << "Выберите алгоритм" << endl << "1) Эйлер\n2) Рунге-Кутта" << endl;
    cin >> algo;
    cin.ignore();
    input_params();

    std::ofstream file;
//timer    
    file.open(argv[1]);
    if(!file.is_open()) {
        cout << "Ошибка открытия файла" << endl;
        return 1;
    }

    file << x << " " << y << endl;
    if (algo == 1) {
        for (int i = 1; i <= N; i++) {
            x = x_n(x, y);
            y = y_n(x, y, t);
            t += dt;
            file << x << " " << y << endl;
        }
    }
    else if (algo == 2) {
        for (int i = 1; i <= N; i++) {
            x = rk_x(x, y);
            y = rk_y(x, y, t);
            t += dt;
            file << x << " " << y << endl;
        }        
    }
    else {
        cout << "Ошибка выбора алгоритма" << endl;
        file.close();
        return 1;
    }
    file.close();
}
