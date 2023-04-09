#include <iostream>

void swap_v(double, double);

void swap_r(int&, int&);

//void swap_cr(const double&, const double&);

void swap_dr( double&,  double&);

int main()
{
    int x = 7;
    int y = 9;
    swap_r(x, y);
    swap_v(7, 9);
    std::cout << x << y << std::endl;

    const int cx = 7;
    const int cy = 9;
    swap_v(static_cast<double>(cx), static_cast<double>(cy));
    swap_v(7.7, 9.9);
    std::cout << cx << cy << std::endl;

    double dx = 7.7;
    double dy = 9.9;
    swap_dr(dx, dy);
    swap_v(7.7, 9.9);
    std::cout << dx << dy << std::endl;

    return 0;
}

void swap_v(double a, double b) {
    double temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_dr(double& a, double& b) {
    double temp;
    temp = a;
    a = b;
    b = temp;
}

/*
    void swap_cr(const double& a, const double& b) {
    double temp;
    temp = a;
    a = b;
    b = temp;
}
*/
