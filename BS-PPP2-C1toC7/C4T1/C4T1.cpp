// C4T1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "..\C3T2\std_lib_facilities.h"

int main()
{
   // std::cout << "Hello World!\n";
    constexpr double usd_per_jpy = 0.0091;
    constexpr double usd_per_uer = 1.2352;
    constexpr double usd_per_gbp = 1.3310;
    constexpr double usd_per_cny = 0.1565;
    cout << "Please enter money, followed by a unit(j, u, g, c)\n";

    double money;

    char unit;

    cin >> money >> unit;

    switch (unit) {
    case'j':cout << "You have " << money << " JPY equal to " << usd_per_jpy * money << " USD!!!"; break;
    case'u':cout << "You have " << money << " UER equal to " << usd_per_uer * money << " USD!!!"; break;
    case'g':cout << "You have " << money << " GBP equal to " << usd_per_gbp * money << " USD!!!"; break;
    case'c':cout << "You have " << money << " CNY equal to " << usd_per_cny * money << " USD!!!"; break;
    default:cout << "invalid input.\n";

    }

    //cout<<"money"""
    keep_window_open();

    return 0;
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
