#include <iostream>

class parabola {
    double a = 0, b = 0, c = 0;
    public:
        friend bool operator / (parabola p1, parabola p2); // для использования закрытых членов класса
        friend bool operator || (parabola p1, parabola p2);
        parabola(float a1, float b1, float c1) {
        this->a = a1;
        this->b = b1;
        this->c = c1;
    }
        ~parabola() {
            std:: cout << "Destructor called for parabola\n";
        }
        void print_parabola() {
            printf("y=%.2fx^2+%.2fx+%.2f\n", a, b, c);
        }
        void find_extreme() {
            double x0 = 0, ext = 0;
            x0 = (-b) / (2 * a);
            ext = a * (pow(x0,2)) + b * x0 + c;
            if (a > 0 && a != 0)
                printf("Min extreme function: %.2f\n", ext);
            else
                printf("Max extreme function: %.2f\n", ext);
        }
};

bool operator || (parabola p1, parabola p2) {
    if (p1.a == p2.a && p1.b == p2.b && p1.c == p2.c)
        return true;
    else
        return false;
}

bool operator / (parabola p1, parabola p2) {
    double a = p1.a - p2.a, b = p1.b - p2.b, c = p1.c - p2.c;
    double d = pow(b, 2) - 4 * a * c;
    if (d >= 0)
        return true;
    else
        return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    parabola y1(1, 2, 3);
    parabola y2(4, 5, 6);

    y1.print_parabola();
    y1.find_extreme();

    y2.print_parabola();
    y2.find_extreme();

    bool sovpadaet1 = y1 || y2;
    bool sovpadaet2 = y1 / y2;
    std::cout << "Sovpadayt " << sovpadaet1 << std::endl;
    std::cout << "Peresekaytsa " << sovpadaet2 << std::endl;

    system("pause");
    return 0;
}
