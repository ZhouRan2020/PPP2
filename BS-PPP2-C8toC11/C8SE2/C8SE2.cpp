// C8SE2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

void swap_v(double, double);

void swap_r(int&, int&);

//void swap_cr(const double&, const double&);

void swap_dr( double&,  double&);

int main()
{
    std::cout << "Hello World!\n";

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


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
