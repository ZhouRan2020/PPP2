// cpp-study2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "..\std_lib_facilities.h"

int f(int);
int ff(int&);
void my_swap(double&, double&);


int main()
{
    string s;

    double num1 = 1;
    double num2 = 2;

    cout << s;

    int x = 7;

    int y = f(x);

    cout << x << y;

    int z = ff(x);

    cout << x << z;

    my_swap(num1, num2);

    keep_window_open();
    return 0;
    //std::cout << "Hello World!\n";
}


int f(int x) {
    x = x + 1;
    return x;

}


int ff(int& xx) {
    xx = xx + 1;
    return xx;

}

void my_swap(double& d1, double& d2) {
    double temp = 0;
    temp = d1;
    d1 = d2;
    d2 = temp;

}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
